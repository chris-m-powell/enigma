#include "rotn.h"
//------------------------------------------------- 
void Rotn::keyGen() {
  int k = 0;
  while (k % 26 == 0) {
    UI::prompt("Enter an integer not congruent to 0 mod 26");
    cin >> k;
  }
  Key = k;
  KeyFlag = 1;
}
//------------------------------------------------- 
void Rotn::encrypt() {
  transform(Buf.begin(), Buf.end(), Buf.begin(), [&](char i) {
    if (Key > 0) {
      if (i >= 'a' && i <= 'z') return (((i + Key) - 'a') % 26) + 'a';
      else if (i >= 'A' && i <= 'Z') return (((i + Key) - 'A') % 26) + 'A';
      else return i - 'A' + 'A';
    }
    else {
      if (i >= 'a' && i <= 'z') return (((i + Key) - 'z') % 26) + 'z';
      else if (i >= 'A' && i <= 'Z') return (((i + Key) - 'Z') % 26) + 'Z';
      else return i - 'A' + 'A';
    }
  });
}
//------------------------------------------------- 
void Rotn::decrypt() {
  transform(Buf.begin(), Buf.end(), Buf.begin(), [&](char i) {
    if (Key > 0) {
      if (i >= 'a' && i <= 'z') return (((i - Key) - 'z') % 26) + 'z';
      else if (i >= 'A' && i <= 'Z') return (((i - Key) - 'Z') % 26) + 'Z';
      else return i + 0;
    }
    else {
      if (i >= 'a' && i <= 'z') return (((i - Key) - 'a') % 26) + 'a';
      else if (i >= 'A' && i <= 'Z') return (((i - Key) - 'a') % 26) + 'a';
      else return i + 0;
    }
  });
}
