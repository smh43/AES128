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
    // for(auto& p : allKeys){
    //     pMat(p);
    //     cerr<<endl;
    // }

    return {};
}

MATRICE AES128::genOneKey(MATRICE& k){
    MATRICE Subed = sub(k);

    for(uChar i =0; i<4; i++){
        continue;
    }  
    return {};
}