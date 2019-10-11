#ifndef ROTN_H
#define ROTN_H
#include "cipher.h"
//------------------------------------------------- 
// Purpose: Provides the specialized implementation
//          details for the rotation cipher
//          using CRTP
//    Date: 2019.283 
//------------------------------------------------- 
class Rotn: public Cipher<Rotn> { //CRTP: 'Rotn' class inherits from 'Cipher<Rotn>' class
  private:
    int Key;
  public:
    Rotn() {Key = 0; Name = "Rotation"; }
    Rotn(int k) {Key = k; Name = "Rotation"; }
    int keyGen();
    void setKey(int);
    int getKey() const { return Key; }
    string encrypt(string);
    string decrypt(string);
};
#endif
