#include "rsa.h"
//------------------------------------------------- 
int RSA::keyGen() {
  int k = 0;
  return k;
}
//------------------------------------------------- 
void RSA::setKey(int k) {
  return;
}
//------------------------------------------------- 
string RSA::encrypt(string p) {
  return p;
}
//------------------------------------------------- 
string RSA::decrypt(string c) {
  return c;
}
//------------------------------------------------- 
int RSA::modExp(int a, int d, int n) {
  return a;
}
//------------------------------------------------- 
tuple<int, int, int> RSA::xgcd(int a, int b) {
  if (a == 0) return make_tuple(b, 0, 1);
  int g, x, y;
  tie(g, x, y) = xgcd(b % a, a);
  return make_tuple(g, (y - (b / a) * x), x);
}
//------------------------------------------------- 
bool RSA::millerRabinTest(int d, int n) {
  srand(time(NULL));
  int x = modExp(2 + rand() % (n - 4), d, n);
  if (x == 1 || x == n - 1) return true;
  while (d != n - 1) {
    x = (x * x) % n;
    d = d * 2;
    if (x == 1) return false;
    if (x == n - 1) return true;
  }
  return false;
}
//------------------------------------------------- 
bool RSA::isPrime(int n, int k) {
  if (n <= 1 || n == 4) return false;
  if (n <= 3) return true;
  int d = n - 1;
}
//------------------------------------------------- 
