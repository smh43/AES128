#include "aeslib.h"

void AES128::padding(string& text){
    if(text.size() % 16 == 0) return;

    char padsize = 16 - (text.size() % 16);

    for(int i = 0; i < padsize; i++){
        text+=padsize;
    }
}