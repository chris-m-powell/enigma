#ifndef RSA_H
#define RSA_H
#include "cipher.h"
/*------------------------------------------------- 
  Purpose: Provides the specialized implementation
           details for the rsa cipher
           using CRTP
     Date: 2019.283 
-------------------------------------------------*/ 
class RSA: public Cipher<RSA> { //CRTP: 'Rotn' class inherits from 'Cipher<Rotn>' class
  private:
    int PrivKey;
    int PubKey;
  public:
    RSA() {PrivKey = PubKey = 0; Name = "RSA"; }
    RSA(int k) {PrivKey = PubKey = k; Name = "RSA"; }
    int keyGen();
    void setKey(int);
    tuple<int, int> getKey() const { return make_tuple(PrivKey, PubKey); }
    string encrypt(string);
    string decrypt(string);
    
    static tuple<int, int, int> xgcd(int, int);
    static int modExp(int, int, int);
    static bool millerRabinTest(int, int);
    static bool isPrime(int, int);
};
#endif
