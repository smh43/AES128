#include <iostream>
#include <string>
#include "AESLIB\aeslib.h"
#include "AESLIB\debug.h"

using namespace std;

int main(){
    string message = "PS C:/Users/Elève/Documents/code/CPP/AES128>";

    string k = "abcdefghijklmnop";
    
    AES128 obj(k);
    for(MATRICE& m : obj.roundKeys){
        pMat(m);
    }
    
    obj.encryptString(message);
    return 0;
}