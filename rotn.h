#ifndef ROTN_H
#define ROTN_H
#include "cipher.h"
//------------------------------------------------- 
class Rotn: public Cipher<Rotn> //CRTP: 'Rotn' class inherits from 'Cipher<Rotn>' class
{
  private:
    int Key;
  public:
    Rotn() {Key = 0; Name = "Rotation"; Type = 'S';}
    Rotn(int k) {Key = k; Name = "Rotation"; Type = 'S';}
    int KeyGen();
    bool SetKey(int k) {Key = k;}
    int GetKey() const {return Key;}
    void Encrypt();
    string WordToLower(string);
    string E(string);
    void Decrypt();
    string D(string);
};
//-------------------------------------------------
#endif
