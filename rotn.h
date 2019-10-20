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
    Rotn() {Key = 0; Name = "ROT-N"; }
    void keyGen();
    void encrypt(); 
    void decrypt(); 
//------------------------------------------------- 
};
#endif
