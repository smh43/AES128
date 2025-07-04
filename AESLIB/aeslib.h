#pragma once

#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

typedef unsigned char uChar; //pour les boucles des matrices qui vont de 0 à 3
typedef vector<vector<uint8_t>> MATRICE; //vector de 4, plus pratique grace à .push_back, mais nécéssite plus de vérification pour les erreurs
typedef vector<uint8_t> KEY;
typedef vector<uint8_t> COL; //juste pour que ca rende mieux et faire la différence entre un vector normal et un vector pour les colonnes

class AES128{ 
    public:
        string encryptString(string text, KEY key);
        string decryptString(string cipher, KEY key);
        bool encryptFile(fstream file, KEY key);
        bool decryptFile(fstream file, KEY key);
    
    private:
        void padding(string& text);
        void depadding(string& data);

        ///////////////////////////////////////////////////
        MATRICE makeMat(const KEY& key); //pour les clés

        vector<MATRICE> stringToMat(string& text); //boucle de création de matrice
        string matToString(vector<MATRICE> am);

        vector<uint8_t> matToTab(MATRICE& mat);
        ///////////////////////////////////////////////////

        static const vector<vector<uint8_t>> subBytes; //16*16
        static const vector<vector<uint8_t>> unSubBytes; 
        MATRICE sub(MATRICE& block);
        MATRICE unsub(MATRICE& cipher);

        vector<MATRICE> generateKeys(MATRICE k);
        MATRICE genOneKey(MATRICE& k);

        MATRICE shiftLines(MATRICE m);
        MATRICE unshiftLines(MATRICE m);
        MATRICE mixColonnes(MATRICE m);
        MATRICE unmixColonnes(MATRICE m);


};

