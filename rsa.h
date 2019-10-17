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
    tuple<int, int> PubKey;
    int m, c;
  public:
    RSA() { PrivKey = 0; PubKey = make_tuple(0, 0); Name = "RSA"; m = c = 0; }
    vector<int> keyGen();
    void setKey(vector<int>);
    void encode();
    void decode();
    void encrypt() { c = modExp(m, get<1>(PubKey), get<0>(PubKey)); }
    void decrypt() { m = modExp(c, PrivKey, get<0>(PubKey)); }
   
    int randInt(int);
    int randPrime(int);
    int genExp(int, int);
    int totient(int);
    int gcd(int, int);
    tuple<int, int, int> xgcd(int, int);
    int modExp(int, unsigned, int);
    int modInv(int, int);
    bool millerRabinTest(int, int);
    bool isPrime(int, int);
    
    bool loadPlaintext();
    bool loadCiphertext();
    void saveCiphertext();
    void savePlaintext();
};
#endif
