#ifndef CRYPTOGRAM_H
#define CRYPTOGRAM_H
#include "cipher.h"
//------------------------------------------------- 
class Cryptogram: public Cipher<Cryptogram> //CRTP: 'Cryptogram' inherits from 'Cipher<Cryptogram>' class
{
  private:
    string Key;
  public:
    Cryptogram() { Key = " "; Name = "Cryptogram"; Type = 'S'; }
    Cryptogram(string k) { Key = k; Name = "Cryptogram"; Type = 'S'; };
    
    string keyGen();
    void setKey(string);
    string getKey() const { return Key; };
    
    /* void encrypt(); */
    string e(string);
    /* void decrypt(); */
    string d(string);
};
//-------------------------------------------------
#endif
