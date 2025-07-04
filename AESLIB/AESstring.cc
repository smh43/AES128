#include "aeslib.h"
#include "debug.h"
#include <string>
#include <vector>

using namespace std;

string AES128::encryptString(string text, KEY key){
    if(key.size() != 16){
        err("Taille incorrecte, la clé doit faire 128 bits (16 octets)");
    }
    if(text.size() % 16 != 0){
        padding(text);
    }

    MATRICE k = makeMat(key);

    pMat(k);

    vector<MATRICE> allKeys(10);

    allKeys = generateKeys(k);

    return "";
}

string AES128::decryptString(string text, KEY key){
    if(key.size() != 16){
        err("Taille incorrecte, la clé doit faire 128 bits (16 octets)");
    }
}