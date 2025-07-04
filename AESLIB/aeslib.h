#pragma once

#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

typedef unsigned char uChar; //pour les boucles des matrices qui vont de 0 à 3
typedef array<vector<uint8_t>, 4> MATRICE; //vector de 4, plus pratique grace à .push_back, mais nécéssite plus de vérification pour les erreurs
typedef vector<uint8_t> KEY;

class AES128{ 
    public:
        string encryptString(string text, KEY key);
        string decryptString(string cipher, KEY key);
        bool encryptFile(fstream file, KEY key);
        bool decryptFile(fstream file, KEY key);
    
    private:
        void padding(string& text);
        void depadding(string& data);

        MATRICE makeMat(const KEY& key);

        vector<MATRICE> generateKeys(MATRICE k);
};

