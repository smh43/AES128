#include "aeslib.h"
#include "debug.h"
#include <vector>


vector<MATRICE> AES128::generateKeys(MATRICE k){ //génère par colonne
    vector<MATRICE> allKeys(10);
    MATRICE next_key;

    uint8_t rconIndex = 1; //commence à 1 parce que le premier est 0x00, et il ne fait pas partit de rcon cest juste pour bien aligner

    for(uChar i = 0; i < 10; i++){
        next_key = genOneKey(k, rconIndex++);
        allKeys[i] = next_key;
        k = next_key;
    }

    return allKeys;
}

MATRICE AES128::genOneKey(MATRICE k, uint8_t rconIndex){ //génération de clés peut etre différente de certains algorithmes, inspiré de : https://www.youtube.com/watch?v=gP4PqVGudtg&pp=0gcJCfwAo7VqN5tD
                                       //subbyte appliqué uniquement sur la derniere colonne de la clé précédente
                                       //décalage de la derniere colonne de 1
    MATRICE newKey;

    COL lastColMod = k[3];
    uint8_t temp = lastColMod[0];
    lastColMod.erase(lastColMod.begin());
    lastColMod.push_back(temp); //décalage de la dernière colonne

    for(uint8_t& e : lastColMod){
        uint8_t line = (e & 0xf0) >> 4;
        uint8_t colonne = e & 0x0f;

        e = subBytes.at(line).at(colonne); //subyte sur la derniere colonne
    }

    lastColMod[0]^= Rcon[rconIndex]; //rcon xor

    COL c; //colonne temporaire qui s'ajoute à newKey

    for(uChar fC = 0; fC < 4; fC++){
        c.push_back( k[0][fC] ^ lastColMod[fC] ); // génération de la première colonne
    }
    newKey.push_back(c);
    c.clear();

    for(uChar i = 1; i<4; i++){ //xor 3 dernières colonnes
        for(uChar j = 0; j<4; j++){
            c.push_back( k[i][j] ^ newKey[i-1][j] ); //on xor avec la colonne généré précedemment
        }
        newKey.push_back(c);
        c.clear();
    }

    return newKey;
} 