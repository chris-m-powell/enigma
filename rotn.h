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
    int keyGen();
    void setKey(int);
    int getKey() const { return Key; }
    void encode() { IntVec.assign(CharVec.begin(), CharVec.end()); }  
    void decode() { CharVec.assign(IntVec.begin(), IntVec.end()); }
    void encrypt(); 
    void decrypt(); 
    bool loadPlaintext();
    bool loadCiphertext();
    void saveCiphertext() const;
    void savePlaintext() const;
//------------------------------------------------- 
};
#endif
