#ifndef RSA_H
#define RSA_H
#include "cipher.h"
#include <gmpxx.h>

/* #define MODULUS_SIZE 1024                   /1* This is the number of bits we want in the modulus *1/ */
/* #define BLOCK_SIZE (MODULUS_SIZE/8)         /1* This is the size of a block that gets en/decrypted at once *1/ */
/* #define BUFFER_SIZE ((MODULUS_SIZE/8) / 2)  /1* This is the number of bytes in n and p *1/ */

/*------------------------------------------------- 
  Purpose: Provides the specialized implementation
           details for the rsa cipher
           using CRTP
     Date: 2019.283 
-------------------------------------------------*/ 
class RSA: public Cipher<RSA> { //CRTP: 'Rotn' class inherits from 'Cipher<Rotn>' class
  private:
    int n, e; // Public Key
    int d; // Private Key
    int m, c;
    vector<int> intVec;
  public:
    RSA() { Name = "RSA"; n = e = d; 
            m = c = 0; }
    void keyGen();
    void encode();
    void decode();
    void encrypt();
    void decrypt();
    int randint(int, int);
    int randPrime(int, int);
    tuple<int, int> genPubKey(int, int, int);
    int genPrivKey(int, int);
    int gcd(int, int);
    tuple<int, int, int> xgcd(int, int);
    int modExp(int, unsigned, int);
    bool millerRabintest(int, int);
    bool isPrime(int, int);
    bool loadCiphertext();
    void saveCiphertext();
    /* bool loadPlaintext(); */
    /* void savePlaintext(); */
    int totient(int);
};
#endif
