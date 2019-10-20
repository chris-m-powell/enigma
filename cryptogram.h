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
    void keyGen();
    void encrypt();
    void decrypt();
};
#endif
