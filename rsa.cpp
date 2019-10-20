#include "rsa.h"
//------------------------------------------------- 
void RSA::keyGen() {
  /* int p = randPrime(50); */ 
  /* int q = randPrime(50); */ 
  /* int n = p * q; */
  /* int t = (p - 1) * (q - 1);// totient(p) * totient(q); */
  /* int e = genExp(n, t); */ 
  /* int d = modInv(e, t); */
 
  /* cout << p << endl; */
  /* cout << q << endl; */
  /* cout << n << endl << endl; */
  int p = 13;
  int q = 17;
  int n = p * q;
  int t = (p - 1) * (q - 1);
  int e = 7;
  int d = modInv(e, t);


  /* cout << (e * d) % t << endl << endl; */
  
  // set kpub=(n,e) and kpriv = d
  PubKey = make_tuple(n, e);
  PrivKey = d;
  KeyFlag = 1;
}
//------------------------------------------------- 
bool RSA::loadPlaintext() { 
  ifstream fin;
  getFile(getFilename("plaintext"), fin);
  if (fin.is_open()) {
    Buf.assign((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();
    return true; 
  } 
  return false;
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
  c = modExp(m, get<1>(PubKey), get<0>(PubKey)); // c=m^e (mod n)
  cout << c;
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
  m = modExp(c, PrivKey, get<0>(PubKey)); // m=c^d (mod n)
  cout << m;
  decode();
}
//------------------------------------------------- 
void RSA::decode() {
  string s = to_string(m);
  for_each(s.begin(), s.end(), [&](char i){ Buf.push_back(i + '0'); });
}
//------------------------------------------------- 
void RSA::savePlaintext() { 
  ofstream fout(getFilename("plaintext"));
  for_each(Buf.begin(), Buf.end(), [&fout](char i) { fout << i; }); 
  fout.close();
} 
//------------------------------------------------- 
int RSA::randInt(int lim) {
  default_random_engine n (chrono::steady_clock::now().time_since_epoch().count()); // provide seed
  uniform_int_distribution<int> uid {1,lim};   // generate integers from 0 to lim (lim included);
  return uid(n); // generate the random int
}
//------------------------------------------------- 
int RSA::randPrime(int lim) {
  int p = randInt(lim);
  while (!isPrime(p, 1)) p = randInt(lim);
  return p;
}
//------------------------------------------------- 
int RSA::genExp(int n, int t) {
  int e = randInt(t);
  while (gcd(e, t) != 1) e = randInt(t);
  return e;
}
//------------------------------------------------- 
int RSA::totient(int n) {
  if (isPrime(n, 1)) return n - 1;
  int t = 0;
  for (int i = 1; i <= n; ++i)
    if (gcd(i, n) == 1) t += 1;
  return t;
}
//------------------------------------------------- 
int RSA::modInv(int a, int m) {
    int g, x, y;
    tie(g, x, y) = xgcd(a, m);
    if (g != 1) return 0; 
    else return x % m;
    /* if (gcd(b, m) == 1) { */
        /* int g, u, v; */
        /* tie(g, u, v) = xgcd(k, totient(m)); */
        /* if (g == 1) return modExp(b, u, m); */
    /* } */
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
