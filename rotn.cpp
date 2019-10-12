#include "rotn.h"
//------------------------------------------------- 
int Rotn::keyGen() {
  int k = 0;
  while (k % 26 == 0) {
    UI::prompt("Enter an integer not congruent to 0 mod 26");
    cin >> k;
  }
  return k;
}
//------------------------------------------------- 
void Rotn::setKey(int k) {
  if ( k % 26 == 0 )
    return;
  Key = k;
  KeyFlag = 1;
  return;
}
//------------------------------------------------- 
string Rotn::encrypt(string p) {
  transform(p.begin(), p.end(), p.begin(), [&](char i) { // lambda expression
    if (i >= 'a' && i <= 'z') {
      if (Key > 0) return (((i + Key) - 'a') % 26) + 'a';
      else return (((i + Key) - 'z') % 26) + 'z';
    } 
  });
  return p;
}
//------------------------------------------------- 
string Rotn::decrypt(string c) {
  transform(c.begin(), c.end(), c.begin(), [&](char i) { // lambda expression
    if (i >= 'a' && i <= 'z') {
      if (Key > 0) return (((i - Key) - 'z') % 26) + 'z';
      else return (((i - Key) - 'a') % 26) + 'a';
    } 
  });
  return c;
}
//------------------------------------------------- 
