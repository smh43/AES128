#include <aeslib.h>
#include <string>

string AESencryptString(string text, KEY key){
    if(key.size() != 16){
        err("Taille incorrecte, la clé doit faire 128 bits (16 octets)");
    }
}