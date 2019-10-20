#include "cryptogram.h"
//-------------------------------------------------
void Cryptogram::keyGen() {
  ifstream fin;
  getFile(getFilename("key"), fin);
  if (fin.is_open()) {
  string s((istreambuf_iterator<char>(fin)), (istreambuf_iterator<char>()));
  Key = s;
  cout << Key;
  fin.close();
  KeyFlag = 1;
  }
}
//------------------------------------------------- 
void Cryptogram::encrypt() {
  transform(Buf.begin(), Buf.end(), Buf.begin(), [&](char i) {
    if ( i >= 'a' && i <= 'z') return Key[i - 'a'];
    if ( i >= 'A' && i <= 'Z') { 
      char c = Key[i - 'a'] - 32;
      return c; 
    }
  });
}
//------------------------------------------------- 
void Cryptogram::decrypt() {
  transform(Buf.begin(), Buf.end(), Buf.begin(), [&](char i) {
    if ( i >= 'a' && i <= 'z') return (Key.find(i)) + 'a'; 
    if ( i >= 'A' && i <= 'Z') return (Key.find(i + 32)) + 'A'; 
  });
}
