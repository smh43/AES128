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
    MATRICE newKey;
    COL newCol;
    MATRICE Subed = sub(k);

    for(uChar i = 0; i<4; i++){
        for(uChar j = 0; j<4; j++){
            newCol.push_back( Subed[i][j] ^ k[i][j] );
        }
        newKey.push_back(newCol);
        newCol.clear();
    }  
    return newKey;
}