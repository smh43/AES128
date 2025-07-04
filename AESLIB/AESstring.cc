#include "aeslib.h"
#include "debug.h"
#include <string>
#include <vector>

using namespace std;

string AES128::encryptString(string text){

    if(text.size() % 16 != 0){
        padding(text);
    }

    vector<MATRICE> textAllBlocks = stringToMat(text);

    return "";
}

string AES128::decryptString(string text){
    return "";
}