#pragma once

#include <iostream>
#include <string>
#include <array>
#include <vector>

#define err(x) cerr << x << endl; exit(1);

using namespace std;

typedef array<array<uint8_t, 4>, 4> MATRICE;
typedef vector<uint8_t> KEY;

string AESencryptString(string text, KEY key);
string AESdecryptString(string cipher, KEY key);
bool AESencryptFile(fstream file, KEY key);
bool AESdecryptFile(fstream file, KEY key);