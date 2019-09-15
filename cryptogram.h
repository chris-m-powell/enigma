#ifndef CRYPTOGRAM_H
#define CRYPTOGRAM_H
#include "cipher.h"
//------------------------------------------------- 
class Cryptogram: public Cipher<Cryptogram> //CRTP: 'Cryptogram' inherits from 'Cipher<Cryptogram>' class
{
  private:
    string Key;
  public:
    Cryptogram() {Key = " "; Name = "Cryptogram"; Type = 'S';}
    Cryptogram(string k) {Key = k; Name = "Cryptogram"; Type = 'S';};
    
    string KeyGen();
    string GetKey() const {return Key;};
    void SetKey(string k) {Key = k;}
    
    void Encrypt();
    /* string WordToLower(string); */
    /* string E(string); */
    void Decrypt();
    /* string D(string); */
};
//-------------------------------------------------
#endif
