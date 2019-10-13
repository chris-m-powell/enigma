#include "rsa.h"
//------------------------------------------------- 
int RSA::keyGen() {
  // select odd numbers p and q
  // apply primality test to p and q; if both passed, then continue; otherwise selent new p and q
  // compute n = pq
  // select integer e s.t. 1 < e < phi(n) and gcd(e,phi(n))=1
  // use xgcd to find ed = 1 (mod phi(n)), i.e., ed+phi(n)y=1
  // set kpub=(n,e) and kpriv = d
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
int RSA::modExp(int a, unsigned k, int m) {
  int b = 1;
  a = a % m;
  while (k) {
    if (k & 1) b = (b * a) % m;
    k = k >> 1;
    a = (a * a) % m;
  }
  return b;
}
//------------------------------------------------- 
int RSA::gcd(int a, int b) {
  while (b) tie(a, b) = make_tuple(b, a % b);
  return a;
}
//------------------------------------------------- 
tuple<int, int, int> RSA::xgcd(int a, int b) {
  if (a == 0) return make_tuple(b, 0, 1);
  int g, x, y;
  tie(g, x, y) = xgcd(b % a, a);
  return make_tuple(g, (y - (b / a) * x), x);
  /* if (b == 0) return make_tuple(a, 1, 0); */
  /* int x, g, v, w; */
  /* tie(x, g, v, w) = make_tuple(1, a, 0, b); */
  /* while (w) tie(x, g, v, w) = make_tuple(v, w, x - (g / w) * v, g % w); */
  /* x = x % (b / g); */
  /* return make_tuple(g, x, (g - (a * x)) / b); */
}
//------------------------------------------------- 
bool RSA::millerRabinTest(int d, int n) {
  srand(time(NULL));
  int x = modExp(2 + rand() % (n - 4), d, n);
  if (x == 1 || x == n - 1) return true;
  while (d != n - 1) {
    x = (x * x) % n;
    d *= 2;
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
  while (d % 2 == 0) d /= 2;
  for (int i =0; i < k; i++)
    if (!millerRabinTest(d, n)) return false;
}
//------------------------------------------------- 
