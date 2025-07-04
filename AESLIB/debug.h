#pragma once

#include "aeslib.h"

#define info(x)  cout << "[$] " << x << endl;
#define err(x)   cerr << "[*] " << x << endl; exit(1);
#define debug(x) cerr << "[_] " << x << endl;

void pMat(MATRICE m, char type);
void pstr(string s);