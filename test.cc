#include <iostream>
#include <string>
#include "AESLIB\aeslib.h"
#include "AESLIB\debug.h"
using namespace std;

int main(){
    string message = "Tu crois vraiment ce que tu vois?";
    string cle = "abcdefghijklmnop";
    
    AES128 obj(cle);
    
    string crypt = obj.encryptString(message); //ne pas afficher ca avec cout et cerr car les octets provoquent des comportements indéfinis
    //pstr(crypt);

    string clear = obj.decryptString(crypt);
    cout << clear << " | " << clear.size() << "/" << message.size() << endl;

    return 0;
}