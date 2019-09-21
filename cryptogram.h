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
    string getKey() const { return Key; };
    bool setKey(string k) { 
      while (k != " ") {
        Key = k;
        return true;
      } 
      return false;
    }
    
    void encrypt();
    /* string WordToLower(string); */
    /* string E(string); */
    void decrypt();
    /* string D(string); */
};
//-------------------------------------------------
#endif
