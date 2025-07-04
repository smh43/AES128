#include "aeslib.h"

void AES128::padding(string& text){  //PKCS7 padding
    if(text.size() % 16 == 0){       //on rajoute un bloc de padding pour se retrouver dans le dépadding
        for(uChar i = 0; i<16; i++){
            text += char(0x16);
        }
    }
    else{
        char padsize = 16 - (text.size() % 16);
        for(uChar i = 0; i < padsize; i++){
            text+=padsize;
        }
    }
}

void AES128::depadding(string& data){
    char nbPad = data.back();

    if(nbPad == 0){
        err("Padding incorrect, termine par 0");
    }
    else{
        for(uChar i = data.size()-1; i>data.size()-1-nbPad; i--){
            data.pop_back();
        }
    }
}

MATRICE AES128::makeMat(const KEY& key){
    MATRICE mat;
    array<uint8_t, 4> colonne;

    for(uChar j = 0; j < 4; j++){
        for(uChar i = 0; i < 4; i++){
            colonne[i] = 0x02;
        }
        mat[j] = colonne;
    }

    return mat;
}