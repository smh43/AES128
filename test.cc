#include <iostream>
#include <string>
#include "AESLIB\aeslib.h"
#include "AESLIB\debug.h"
using namespace std;

int main(){
    string message = "Tu crois vraiment ce que tu vois?";

    string cle = "abcdefghijklmnop";
    
    AES128 obj(cle);

    // for(MATRICE& m : obj.roundKeys){
    //     pMat(m);
    // }
    
    string crypt = obj.encryptString(message);

    string clear = obj.decryptString(crypt);

    return 1;
}