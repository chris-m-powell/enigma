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
  public:
    RSA() {PrivKey = 0; PubKey = make_tuple(0, 0); Name = "RSA"; }
    /* RSA(int k, int k1, int k2) {PrivKey = k; PubKey = make_tuple(k1, k2); Name = "RSA"; } */
    vector<int> keyGen();
    void setKey(vector<int>);
    /* vector<int> getKey() const { return vec; } */
    string encrypt(string);
    vector<int> encode(string) const;
    string decode(vector<int>) const;
    string decrypt(string);
   
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
};
#endif
