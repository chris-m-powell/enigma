#include "cryptogram.h"
//-------------------------------------------------
string Cryptogram::KeyGen() {
  ifstream fin;
  GetFile(GetFilename("key"), fin);
  if (fin.is_open()) {
    return string ((istreambuf_iterator<char>(fin) ), (istreambuf_iterator<char>()));;
  }
}
//------------------------------------------------- 
void Cryptogram::Encrypt() {
}
//------------------------------------------------- 
void Cryptogram::Decrypt() {
}
//------------------------------------------------- 
