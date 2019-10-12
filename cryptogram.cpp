#include "cryptogram.h"
//-------------------------------------------------
string Cryptogram::keyGen() {
  ifstream fin;
  getFile(getFilename("key"), fin);
  if (!fin.is_open())
    return " ";
  return string ((istreambuf_iterator<char>(fin) ), (istreambuf_iterator<char>()));
}
//------------------------------------------------- 
void Cryptogram::setKey(string k) { 
  if (k == " ")
    return;
  Key = k;
  KeyFlag = 1;
}
//------------------------------------------------- 
string Cryptogram::encrypt(string p) {
  transform(p.begin(), p.end(), p.begin(), [&](char i) { // lambda expression
    if ( i >= 'a' && i <= 'z')
      return Key[i - 'a']; 
  });
  return p;
}
//------------------------------------------------- 
string Cryptogram::decrypt(string c) {
  transform(c.begin(), c.end(), c.begin(), [&](char i) { // lambda expression
    if ( i >= 'a' && i <= 'z')
      return (Key.find(i)) + 'a'; 
  });
  return c;
}
//------------------------------------------------- 
