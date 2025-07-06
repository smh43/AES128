#include "aeslib.h"
#include "debug.h"
#include <string>
#include <vector>

using namespace std;

/*
    encrypt:

    1.Padding
    2.Transformation en vecteur de matrice
    3.répéter 9 tours:
        changer les octets avec le tableau subByte
        décaler les lignes
        Changer les colonnes avec rainjled 
        xor avec la clé

    4.dernier round pareil sauf qu'on ne fait pas le changement de colonne
    5.convertion de vecteur de matrice a string
*/

string AES128::encryptString(string text){ //beaucoup plus court et épuré c'est carré

    padding(text);
    
    vector<MATRICE> textAllBlocks = stringToMat(text);

    for(MATRICE& block : textAllBlocks){
        for(uChar i = 0; i<9; i++){
            block = sub(block); //ne pas changer le type de retour, utilisé pour keyGen
            shiftLines(block);
            mixColonnes(block);
            xorKey(block, this->roundKeys[i]);
        }
        
        //dernier round sans mixColonne
        block = sub(block);
        shiftLines(block);
        xorKey(block, this->roundKeys[9]);
    }

    return matToString(textAllBlocks);;
}

/*  decrypt:

    1.transformer string en vecteur de matrice
    2.xor avec la derniere clé
    3.décaler les lignes
    4.unsub les octets
    5.répéter 9 tours:
        xor avec la clé (à l'envers)
        Changer les colonnes avec rijndaed 
        décaler les lignes
        unsub les octets

    6. convertir de vecteur de matrice à string
    7. dépadder
*/

string AES128::decryptString(string ciph){

    if(ciph.size()%16 != 0){
        err("Le message chiffré n'est pas de taille correct");
    }

    vector<MATRICE> ciphAllBlocks = stringToMat(ciph);

    for(MATRICE& bloc : ciphAllBlocks){
        xorKey(bloc, roundKeys[9]);
        unshiftLines(bloc);
        bloc = unsub(bloc);

        for(uChar i = 9; i > 0; i--){ //unsigned char, donc le i >=0 cause une boucle infini
            uChar index = i-1;

            xorKey(bloc, roundKeys[index]);
            unmixColonnes(bloc);
            unshiftLines(bloc);
            bloc = unsub(bloc);  
        }

    }
    string decoded = matToString(ciphAllBlocks);

    depadding(decoded);

    return decoded;
}