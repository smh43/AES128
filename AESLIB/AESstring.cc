#include "aeslib.h"
#include <string>

using namespace std;

string AES128::encryptString(string text, KEY key){
    if(key.size() != 16){
        err("Taille incorrecte, la clé doit faire 128 bits (16 octets)");
    }
    if(text.size() % 16 != 0){
        padding(text);

        debug(text.size());
        debug(text);
    }

    return "";
}

string AES128::decryptString(string text, KEY key){
    if(key.size() != 16){
        err("Taille incorrecte, la clé doit faire 128 bits (16 octets)");
    }
}