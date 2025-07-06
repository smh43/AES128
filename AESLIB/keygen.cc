#include "aeslib.h"
#include "debug.h"
#include <vector>


vector<MATRICE> AES128::generateKeys(MATRICE k){ //génère par colonne
    vector<MATRICE> allKeys(10);
    MATRICE next_key;


    for(uChar i = 0; i < 10; i++){
        next_key = genOneKey(k);
        allKeys[i] = next_key;
        k = next_key;
    }

    return allKeys;
}

MATRICE AES128::genOneKey(MATRICE& k){ //a revoir avec rcon
                                       //subbyte appliqué uniquement sur la derniere colonne de la clé précédente
                                       //décalage de la derniere colonne de 1
                                       //rcon xor + decalage colonne + subbyte sur chaque derniere colonne des 10 clés
    MATRICE newKey;
    COL newCol;

    for(uChar i = 0; i<4; i++){
        for(uChar j = 0; j<4; j++){
            continue; //a refaire
        }
        newKey.push_back(newCol);
        newCol.clear();
    }  
    return newKey;
} 