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
    int p, q; // Random prime integers 
    int n, e; // Public Key
    int t; // Totient(n)
    int d; // Private Key
    int m, c;
    vector<int> IntVec;
  public:
    RSA() { Name = "RSA"; }
    void keyGen();
    void encode();
    void decode();
    void encrypt();
    void decrypt();
    int randInt(int, int);
    int randPrime(int, int);
    int genExp(int, int);
    int totient(int);
    int gcd(int, int);
    tuple<int, int, int> xgcd(int, int);
    int modExp(int, unsigned, int);
    int modInv(int, int);
    bool millerRabinTest(int, int);
    bool isPrime(int, int);
    bool loadCiphertext();
    void saveCiphertext();
    /* bool loadPlaintext(); */
    /* void savePlaintext(); */
};
#endif
