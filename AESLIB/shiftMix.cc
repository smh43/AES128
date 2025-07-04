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


void AES128::mixColonnes(MATRICE& m){
    return;
}
void AES128::unmixColonnes(MATRICE& m){
    return;
}