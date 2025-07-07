#include <iostream>
#include <string>
#include "AESLIB\aeslib.h"
#include "AESLIB\debug.h"
using namespace std;

int main(){
    
    string message = "Test AES ? 128, tout intégré";
    string cle = "abcdefghijklmnop";
    
    AES128 obj(cle);
    
    string crypt = obj.encryptString(message); //ne pas afficher ca avec cout et cerr car les octets provoquent des comportements indéfinis
    //pstr(crypt);

    string clear = obj.decryptString(crypt);
    cout << clear << " | " << clear.size() << endl;

    return 0;
}