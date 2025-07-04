
#include "aeslib.h"
#include "debug.h"

void pMat(MATRICE m){ //c'est juste pour faire beau
    cerr <<"[";
    for(uChar c=0; c<4;c++){
        cerr << (c ? " ":"") << "[";
        for(uChar l = 0; l<4;l++){
            cerr << "0x" << (m[c][l] < 0x10 ? "0" : "") << hex << int(m[c][l]) << (l != 3 ? " " : "");
            //cerr << char(m[c][l]) << (l != 3 ? " " : ""); //pour les matrices du message
        }
        cerr<<"]" << (c !=3 ? "\n" : "");
    }
    cerr<<"]"<<endl;
}

void pstr(string s){
    cerr<<'\'';
    for(char& c : s){
        if(c == 0xff) cerr << "|";
        cerr <<  "0x" << (c < 0x10 ? "0" : "") << hex << (short)(unsigned char)c << " "; //problème d'affichage hex car c est signé, il faut l'unsign et l'afficher en nombre
    }
    cerr << '\''<< endl;
}