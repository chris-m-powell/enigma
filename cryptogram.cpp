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
  p = wordToLower(p);
  string c = p;
  for(int i=0; i < p.size(); i++) {
    if(p[i] >= 'a' && p[i] <= 'z') 
      c[i] = Key[p[i] - 'a']; 
  }
  return c;
}
//------------------------------------------------- 
string Cryptogram::decrypt(string c) {
  string p = c;
  for(int i = 0; i < c.size(); i++) {
    if (c[i] >= 'a' && c[i] <= 'z') 
      p[i] = (Key.find(c[i])) + 'a'; 
  }
  return p;
}
//------------------------------------------------- 
