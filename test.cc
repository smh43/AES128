#include <iostream>
#include <string>
#include "AESLIB\aeslib.h"

using namespace std;

int main(){
    string message = "Tu peux lire des zones allouées mais non initialisées, mais tu risques de lire des valeurs indéfinies (garbage). "
                     "Dans certains langages (ex: C/C++), il est facile de lire par erreur hors des bornes d`un tableau si aucune vérification n`est faite, mais le système peut détecter ça s`il y a une séparation mémoire (guard pages)."
                     "Un accès en lecture à une adresse invalide (comme *(int*)0xdeadbeef) échouera, car cette adresse n`est pas mappée dans l`espace virtuel de ton processus.";

    KEY k = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    
    AES128 AesObj;
    AesObj.encryptString(message, k);
    return 0;
}