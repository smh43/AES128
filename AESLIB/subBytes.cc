#include "aeslib.h"
#include "debug.h"

MATRICE AES128::sub(MATRICE& block){
    MATRICE subed;
    COL c;
    for(COL& t : block){
        for(uint8_t& oct : t){
            size_t line = (oct & 0xf0) >> 4;
            size_t col = oct & 0x0f;
            c.push_back( AES128::subBytes.at(line).at(col) );
        }
        subed.push_back(c);
        c.clear();
    }
    return subed;
}

MATRICE AES128::unsub(MATRICE& cipher){
    MATRICE usubed;
    COL c;
    for(COL& t : cipher){
        for(uint8_t& oct : t){
            size_t line = (oct & 0xf0) >> 4;
            size_t col = oct & 0x0f;
            c.push_back( AES128::unSubBytes[line][col] );
        }
        usubed.push_back(c);
        c.clear();
    }
    return usubed;
}