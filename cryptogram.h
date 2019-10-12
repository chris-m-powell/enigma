#ifndef CRYPTOGRAM_H
#define CRYPTOGRAM_H
#include "cipher.h"
/*------------------------------------------------- 
  Purpose: Provides the specialized implementation
           details for the cryptogram cipher
           using CRTP
     Date: 2019.283 
-------------------------------------------------*/ 
class Cryptogram: public Cipher<Cryptogram> { //CRTP: 'Cryptogram' inherits from 'Cipher<Cryptogram>' class
  private:
    string Key;
  public:
    Cryptogram() { Key = " "; Name = "CRYPTOGRAM"; }
    Cryptogram(string k) { Key = k; Name = "CRYPTOGRAM"; };
    string keyGen();
    void setKey(string);
    string getKey() const { return Key; };
    string encrypt(string);
    string decrypt(string);
};
#endif
