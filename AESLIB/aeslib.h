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

class AES128{ //pour Optimiser je passe presque tout en référence
    public:
        AES128(KEY k); //constructeur pour l'objet KEY
        AES128(string kstr); //constructeur pour transformer une key string en un objet Key

        string encryptString(string text);
        string decryptString(string ciph);
        bool encryptFile(fstream file);
        bool decryptFile(fstream file);

        KEY key;
        vector<MATRICE> roundKeys;
    
    private:
        void padding(string& text);
        void depadding(string& data);

        ///////////////////////////////////////////////////
        MATRICE makeMat(const KEY& k); //pour les clés

        vector<MATRICE> stringToMat(string& text); //boucle de création de matrice
        string matToString(vector<MATRICE>& am);
        ///////////////////////////////////////////////////

        static const vector<vector<uint8_t>> subBytes; //16*16
        static const vector<vector<uint8_t>> unSubBytes; 
        MATRICE sub(MATRICE& block);
        MATRICE unsub(MATRICE& cipher);

        vector<MATRICE> generateKeys(MATRICE k);
        MATRICE genOneKey(MATRICE& k);

        void shiftLines(MATRICE& m);
        void unshiftLines(MATRICE& m);
        void mixColonnes(MATRICE& m);
        void unmixColonnes(MATRICE& m);

        void xorKey(MATRICE& block, const MATRICE& k);


};

