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

    vector<MATRICE> allKeys(10);
    allKeys = generateKeys(k);

    vector<MATRICE> textAllBlocks = stringToMat(text);

    return "";
}

string AES128::decryptString(string text, KEY key){
    if(key.size() != 16){
        err("Taille incorrecte, la clé doit faire 128 bits (16 octets)");
    }
}