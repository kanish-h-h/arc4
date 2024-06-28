/* example.c */
#include "arcfour.h"
#include <stdio.h>
#include <unistd.h>

#define F fflush(stdout)

int main(void);

// ef20 ac12

void printbin(int8 *input, const int16 size) {
    int32 i;
    int8 *p;

    assert(size > 0);

    for (i=size, p=input; i; i--, p++) {
        if (!(i % 2))  // even
            printf(" ");
        printf("%.02x", *p);
    }
    printf("\n");
    return ;

}

int main() {
    Arcfour *rc4;
    int16 skey, stext;
    char *key, *from;
    char k[256];
    int8 *encrypted, *decrypted;

    key=from=0;
    encrypted=decrypted=0;
    from=key;
    skey=stext=0;

    key = "apples";   /* 8 BITS -> 2048 BITS */
    skey = strlen((char *)key);
    from = "Chicho! the eye's they never lie.";
    stext = strlen((char *)from);

    printf("Initializing encryption..."); F;
    rc4 = rc4init((int8 *)key, skey);
    printf("done\n");

    printf("'%s'\n ->", from);
    encrypted = rc4encrypt(rc4, (int8 *)from, stext);
    printbin(encrypted, stext);
    rc4uninit(rc4);

    printf("\nInitializing decryption..."); F;
    rc4 = rc4init((int8 *)key, skey);
    printf("done\n");

    decrypted = rc4decrypt(rc4, encrypted, stext);

    printf("Enter the Key: ");
    scanf("%[^\n]", k);

    int result = strcmp(k, key);
    if (result == 0) {
        printf("->'%s'\n", decrypted);
        //rc4uninit(rc4);
    } else {
        printf("Invalid KEY\n");
    }

    return 0;
}
