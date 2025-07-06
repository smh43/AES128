#include "aeslib.h"
#include "debug.h"

void AES128::shiftLines(MATRICE& m){
    uint8_t n0, n1, n2, n3;

    //decale de 1
    n0 = m[0][1], n1 = m[1][1], n2 = m[2][1], n3 = m[3][1];
    m[0][1] = n1, m[1][1] = n2, m[2][1] = n3, m[3][1] = n0;

    //decale de 2
    n0 = m[0][2], n1 = m[1][2], n2 = m[2][2], n3 = m[3][2];
    m[0][2] = n2, m[1][2] = n3, m[2][2] = n0, m[3][2] = n1;

    //decale de 3
    n0 = m[0][3], n1 = m[1][3], n2 = m[2][3], n3 = m[3][3];
    m[0][3] = n3, m[1][3] = n0, m[2][3] = n1, m[3][3] = n2;

}
void AES128::unshiftLines(MATRICE& m){
    uint8_t n0, n1, n2, n3;

    //recale de 1
    n0 = m[0][1], n1 = m[1][1], n2 = m[2][1], n3 = m[3][1];
    m[0][1] = n3, m[1][1] = n0, m[2][1] = n1, m[3][1] = n2;

    //recale de 2
    n0 = m[0][2], n1 = m[1][2], n2 = m[2][2], n3 = m[3][2];
    m[0][2] = n2, m[1][2] = n3, m[2][2] = n0, m[3][2] = n1;

    //recale de 3
    n0 = m[0][3], n1 = m[1][3], n2 = m[2][3], n3 = m[3][3];
    m[0][3] = n1, m[1][3] = n2, m[2][3] = n3, m[3][3] = n0;
    return;
}

uint8_t AES128::XTIME(uint8_t a){ //si a a le dernier bit, on le multiplie par 2 et on le ramene à un octet, sinon on le multiplie par 2

    if(a & 0x80){
        return ((a << 1) ^ 0x1B) & 0xFF;
    }
    else{
        return a << 1;
    }
}
void AES128::mixColonnes(MATRICE& m){
    for(COL& c : m){
        uint8_t t = c[0] ^ c[1] ^ c[2] ^ c[3];
        uint8_t u = c[0]; //pour boucler correctement
                          //3 * x = (2*x) ^ x = XTIME(x) ^ x dans le champ fini [0; 2**8] 

        c[0] ^= t ^ XTIME(c[0] ^ c[1]);
        c[1] ^= t ^ XTIME(c[1] ^ c[2]);
        c[2] ^= t ^ XTIME(c[2] ^ c[3]);
        c[3] ^= t ^ XTIME(c[3] ^ u);
    }
}
void AES128::unmixColonnes(MATRICE& m){
    for(COL& c : m){
        uint8_t u = XTIME(XTIME(c[0] ^ c[2]));
        uint8_t v = XTIME(XTIME(c[1] ^ c[3]));

        c[0]^= u;
        c[1]^= v;
        c[2]^= u;
        c[3]^= v;
    }
    mixColonnes(m);
}