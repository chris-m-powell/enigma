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
    int keyGen();
    void setKey(int);
    int getKey() const { return Key; }
    string encrypt(string);
    string decrypt(string);
};
//-------------------------------------------------
#endif
