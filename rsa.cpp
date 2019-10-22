#include "rsa.h"
//------------------------------------------------- 
void RSA::keyGen() {
  int p = randPrime(3, 47); 
  int q = randPrime(51, 97);
  int t = (p - 1) * (q - 1);
  tie(n, e) = genPubKey(p, q, t); 
  d = genPrivKey(e, t);
  KeyFlag = 1;
}
//------------------------------------------------- 
void RSA::encode() {
  IntVec.assign(Buf.begin(), Buf.end()-1);
  string s;
  for_each(IntVec.begin(), IntVec.end(), [&](int i){ s += to_string(i); });
  m = stoi(s);
}
//------------------------------------------------- 
void RSA::encrypt() {
  encode();
  c = modExp(m, e, n); // c=m^e (mod n)
}
//------------------------------------------------- 
void RSA::saveCiphertext() { 
  ofstream fout(getFilename("ciphertext"));
  fout << c;
  fout.close();
} 
//------------------------------------------------- 
bool RSA::loadCiphertext() { 
  ifstream fin;
  getFile(getFilename("ciphertext"), fin);
  if (fin.is_open()) {
    fin >> c;
    fin.close();
    return true; 
  } 
  return false; 
}
//------------------------------------------------- 
void RSA::decrypt() {
  m = modExp(c, d, n); // m=c^d (mod n)
  decode();
}
//------------------------------------------------- 
void RSA::decode() {
  string s = to_string(m);
  for_each(s.begin(), s.end() - 2 , [&](char i){ Buf.push_back(i + '0'); });
}
//------------------------------------------------- 
int RSA::randPrime(int l, int u) {
  int p = randInt(l, u);
  while (!isPrime(p, 64)) p = randInt(l, u);
  return p;
}
//------------------------------------------------- 
int RSA::randInt(int l, int u) {
  default_random_engine n (chrono::steady_clock::now().time_since_epoch().count()); // provide seed
  uniform_int_distribution<int> uid {l,u};   // generate integers from l to u (inclusive);
  return uid(n); // generate the random int
}
//------------------------------------------------- 
tuple<int, int> RSA::genPubKey(int p, int q, int t) {
  int a = randInt(3, t - 1);
  while (gcd(a, t) != 1) a = randInt(3, t - 1);
  return make_tuple(p * q, a);
}
//------------------------------------------------- 
int RSA::genPrivKey(int a, int m) { //modInv
  int g, x, y;
  tie(g, x, y) = xgcd(a, m);
  if (g != 1) return 0; 
  else return ((x % m) + m) % m; // m is added to force positive
}
//------------------------------------------------- 
int RSA::modExp(int a, unsigned k, int m) {
  int b = 1;
  while (k) {
    if (k % 2 == 1) b = (b * a) % m;
    tie(a, k) = make_tuple((a * a) % m, k / 2);
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
bool RSA::isPrime(int n, int k) {
  if (n <= 1 || n == 4) return false;
  if (n <= 3) return true;
  int d = n - 1;
  while (d % 2 == 0) d /= 2;
  for (int i = 0; i < k; i++)
    if (!millerRabinTest(d, n)) return false;
  return true;
}
//------------------------------------------------- 
bool RSA::millerRabinTest(int d, int n) {
  int x = modExp(randInt(2, n - 2), d, n);
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
/* int RSA::totient(int n) { */
  /* if (isPrime(n, 1)) return n - 1; */
  /* int t = 0; */
  /* for (int i = 1; i <= n; ++i) */
    /* if (gcd(i, n) == 1) t += 1; */
  /* return t; */
/* } */
