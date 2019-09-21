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
    bool setKey(int k) { Key = k; }
    int getKey() const { return Key; }
    void encrypt();
    string wordToLower(string);
    string e(string);
    void decrypt();
    string d(string);
};
//-------------------------------------------------
#endif
