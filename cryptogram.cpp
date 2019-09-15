#include "cryptogram.h"
//------------------------------------------------- 
string Cryptogram::KeyGen() {
  UI::Prompt(msg::EnterFilename);
  string f = GetFilename();
  /* if (!ReadFile(GetFilename())) { */ 
    /* UI::Alert(msg::InvalidFilename, 1.5); */
    /* return; */
  /* } */
  /* string k; */
  /* for (int i=0; SourceBuffer.size(); i++) { */
    /* k = k + SourceBuffer[i]; */
  /* } */
  /* return k; */
  return f;
}
//------------------------------------------------- 
void Cryptogram::Encrypt() {
}
//------------------------------------------------- 
void Cryptogram::Decrypt() {
}
//------------------------------------------------- 
