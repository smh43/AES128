#include <iostream>
#include <string>
#include "AESLIB\aeslib.h"
#include "AESLIB\debug.h"

using namespace std;

int main(){
    string message = "PS C:/Users/Elève/Documents/code/CPP/AES128>";

    //message = "0123456789ABCDEF"; //decrypte MULTIPLE &-

    string cle = "abcdefghijklmnop";
    
    AES128 obj(cle);

    // for(MATRICE& m : obj.roundKeys){
    //     pMat(m);
    // }
    
    string crypt = obj.encryptString(message);
    cerr<<crypt<<endl;

    string clear = obj.decryptString(crypt);
    cout << clear << endl; 

    return 0;
}