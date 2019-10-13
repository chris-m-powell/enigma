#include "crypto.h"
//------------------------------------------------- 
int main() {
  /* int a = 30; */
  /* int b = 50; */
  /* cout << get<0>(RSA::xgcd(a, b)); */
  /* cout << get<1>(RSA::xgcd(a, b)); */
  /* cout << get<2>(RSA::xgcd(a, b)); */
  /* RSA::isPrime(4,200); */
  
  /* int k = 4;  // Number of iterations */ 
  
    /* cout << "All primes smaller than 100: \n"; */ 
    /* for (int n = 1; n < 100; n++) */ 
       /* if (RSA::isPrime(n, k)) */ 
          /* cout << n << " "; */ 
  
    /* return 0; */
  


  cout << get<0>(RSA::xgcd(18, 93));
  cout << get<1>(RSA::xgcd(18, 93));
  cout << get<2>(RSA::xgcd(18, 93));
  /* Crypto::startUp(); */
  return 0;
}
