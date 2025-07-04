#include "aeslib.h"
#include "debug.h"

void AES128::padding(string& text){  //PKCS7 padding
    if(text.size() % 16 == 0){       //on rajoute un bloc de padding pour se retrouver dans le dépadding
        for(uChar i = 0; i<16; i++){
            text += char(0x16);
        }
    }
    else{
        char padsize = 16 - (text.size() % 16);
        for(uChar i = 0; i < padsize; i++){
            text += padsize;
        }
    }
}

void AES128::depadding(string& data){
    char nbPad = data.back();

    if(nbPad == 0){
        err("Padding incorrect, termine par 0");
    }
    else{
        for(uChar i = 0; i < nbPad; i++){
            data.pop_back();
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////

MATRICE AES128::makeMat(const KEY& key){
    MATRICE mat;
    COL colonne;

    // si la clé est 0x00 0x01 0x02 0x03 0x04 0x05 0x06 0x07 etc...
    // la matrice sera organisé par tableau qui représenteront les colonnes

    // [[0x00 0x04 0x08 0x0c]
    //  [0x01 0x05 0x09 0x0d]
    //  [0x02 0x06 0x0a 0x0e]
    //  [0x03 0x07 0x0b 0x0f]]

    for(uChar j = 0; j < 4; j++){ 
        for(uChar i = j; i < 16; i+=4){
            colonne.push_back(key.at(i));
        }
        mat.push_back(colonne);
        colonne.clear();
    }

    return mat;
}

vector<MATRICE> AES128::stringToMat(string& text){
    vector<MATRICE> allMats;
    for(size_t i = 0; i < text.size(); i+=16){ //boucle de bloc
        string block = text.substr(i, 16);
        MATRICE mat;
        COL colonne;

        for(uChar j = 0; j < 4; j++){ //boucle de mat
            for(uChar z = j; z < 16; z+=4){ //boucle pour implémenter les colonnes
                colonne.push_back(uint8_t(block.at(z)));    
            }
            mat.push_back(colonne);
            colonne.clear();
        }
        allMats.push_back( mat );
        mat.clear();
    }

    return allMats;
}

string AES128::matToString(vector<MATRICE> am){
    string outText;

    for(MATRICE& mat : am){
        for(uChar i =0; i<4; i++){
            for(COL& c : mat){
                outText += char(c[i]);
            }
        }
    }

    return outText;
}

