#include "rotn.h"
//------------------------------------------------- 
int Rotn::KeyGen() {
  int k = 0;
  while (k % 26 == 0) {
    UI::Prompt("Enter an integer not congruent to 0 mod 26");
    cin >> k;
  }
  return k;
}
//------------------------------------------------- 
void Rotn::Encrypt()
{
  string p;
  for (int i=0; i < SourceBuffer.size(); i++) {
    p = SourceBuffer[i];
    string c = E(p); 
    TargetBuffer.push_back(c);
  }
}
//------------------------------------------------- 
string Rotn::E(string p)
{
  p = WordToLower(p);
  string c = p;
  for (int i=0; i < p.size(); i++) {
    if (c[i] >= 'a' && c[i] <= 'z') {
      if (Key > 0) {
        c[i] = (((p[i]+Key)-'a')%26)+'a';
      } 
      else {
        c[i] = (((p[i]+Key)-'z')%26)+'z';
      }
    }	
  }
  return c;
}
//------------------------------------------------- 
string Rotn::WordToLower(string Word)
{
  for (int i = 0; i < Word.length(); i++) {
    Word[i] = tolower(Word[i]);
  }                                               
  return Word; 
}
//------------------------------------------------- 
void Rotn::Decrypt()
{
  string c;
  for (int i=0; i < SourceBuffer.size(); i++) 
    {
      c = SourceBuffer[i];
      string p = D(c);
      TargetBuffer.push_back(p);
    }
}
//------------------------------------------------- 
string Rotn::D(string c)
{
  string p = c;
  for (int i=0; i < c.size(); i++)
    {
      if (p[i] >= 'a' && p[i] <= 'z') {
        if (Key > 0) {
          p[i] = (((c[i]-Key)-'z')%26)+'z';
        }
	  else {
        p[i] = (((c[i]-Key)-'a')%26)+'a';
        }
      }
    }
  return p;
}
//------------------------------------------------- 