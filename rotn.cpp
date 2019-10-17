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
void Rotn::encrypt() {
  transform(IntVec.begin(), IntVec.end(), IntVec.begin(), [&](int i) {
    if (Key > 0) {
      if (i >= 'a' && i <= 'z') return (((i + Key) - 'a') % 26) + 'a';
      else if (i >= 'A' && i <= 'Z') return (((i + Key - 'A') % 26) + 'A');
      else return i;
    }
    else {
      if (i >= 'a' && i <= 'z') return (((i + Key) - 'z') % 26) + 'z';
      else if (i >= 'A' && i <= 'Z') return (((i + Key) - 'Z') % 26) + 'Z';
      else return i;
    }
  });
}
//------------------------------------------------- 
void Rotn::decrypt() {
  transform(IntVec.begin(), IntVec.end(), IntVec.begin(), [&](int i) {
    if (Key > 0) {
      if (i >= 'a' && i <= 'z') return (((i - Key) - 'z') % 26) + 'z';
      else if (i >= 'A' && i <= 'Z') return (((i - Key) - 'Z') % 26) + 'Z';
      else return i;
    }
    else {
      if (i >= 'a' && i <= 'z') return (((i - Key) - 'a') % 26) + 'a';
      else if (i >= 'A' && i <= 'Z') return (((i - Key) - 'a') % 26) + 'a';
      else return i;
    }
  });
}
//------------------------------------------------- 
bool Rotn::loadPlaintext() { 
  ifstream fin;
  getFile(getFilename("plaintext"), fin);
  if (fin.is_open()) {
    CharVec.assign((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();
    return true; 
  } 
  return false;
}
//------------------------------------------------- 
bool Rotn::loadCiphertext() { 
  ifstream fin;
  getFile(getFilename("plaintext"), fin);
  if (fin.is_open()) {
    CharVec.assign((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    fin.close();
    return true; 
  } 
  return false; 
}
  //------------------------------------------------- 
void Rotn::saveCiphertext() const { 
  ofstream fout(getFilename("ciphertext"));
  for_each(IntVec.begin(), IntVec.end(), [&fout](int i) { fout << i; }); 
  fout.close();
} 
//------------------------------------------------- 
void Rotn::savePlaintext() const { 
  ofstream fout(getFilename("plaintext"));
  for_each(CharVec.begin(), CharVec.end(), [&fout](char i) { fout << i; }); 
  fout.close();
} 
