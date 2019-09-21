#include "cryptogram.h"
//-------------------------------------------------
string Cryptogram::keyGen() {
  ifstream fin;
  getFile(getFilename("key"), fin);
  if (fin.is_open()) {
    return string ((istreambuf_iterator<char>(fin) ), (istreambuf_iterator<char>()));;
  }
}
//------------------------------------------------- 
void Cryptogram::encrypt() {
}
//------------------------------------------------- 
void Cryptogram::decrypt() {
}
//------------------------------------------------- 
