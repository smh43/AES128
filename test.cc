#include <iostream>
#include <string>
#include "AESLIB\aeslib.h"
#include "AESLIB\debug.h"
using namespace std;

int main(){
    string message = "Tu crois vraiment ce que tu vois ?";

    message = "0123456789ABCDEF"; //decrypte MULTIPLE 16

    string cle = "abcdefghijklmnop";
    
    AES128 obj(cle);

    // for(MATRICE& m : obj.roundKeys){
    //     pMat(m);
    // }
    
    string crypt = obj.encryptString(message);
    cout << crypt << " | " << crypt.size() << endl;

    string clear = obj.decryptString(crypt);
    cout << clear << " | " << clear.size() << endl; 

    return 0;
}