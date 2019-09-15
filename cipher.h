#ifndef CIPHER_H
#define CIPHER_H
#include "ui.h"
#include "message.h"
//------------------------------------------------- 
template <class T>
class Cipher {
  protected:
    string Name; 
    char Type;
    vector<string> SourceBuffer;
    vector<string> TargetBuffer;
  public:
    Cipher() {Name = " "; Type = ' ';}
    Cipher(string n, char t) {Name = n; Type = t;}

    // CRTP methods
    T& Self() {return static_cast<T&>(*this);}
    void Print(Cipher<T> const& x);
    void InitKeyGen();      
    void InitEncrypt(Cipher<T> const& x);      
    void InitDecrypt(Cipher<T> const& x);      

    string GetFilename();
    bool ReadFile(string);
    bool WriteFile(string);
    string GetName() const {return Name;}
    char GetType() const {return Type;}
    
    // Deprecated
    /* auto GetKey() const {return static_cast<T const&>(*this).GetKey();} */
    /* static void print(Cipher<T> const& x) {cout << x.GetKey() << endl;} */ 
};
//------------------------------------------------- 
template <class T>
void Cipher<T>::InitKeyGen() {
  UI::Clearline();
  Self().SetKey(Self().KeyGen()); // CRTP: specialized
  UI::Clearline();
  UI::Alert(msg::KeyGenSuccess, 1.5);
}
//-------------------------------------------------
template <class T>
void Cipher<T>::InitEncrypt(Cipher<T> const& x) {
  UI::Clearline();
  UI::Prompt(msg::EnterFilename);
  if (!ReadFile(GetFilename())) {
    UI::Alert(msg::InvalidFilename, 1.5);
    return;
  }
  Self().Encrypt(); // CRTP: specialized
  UI::Prompt(msg::EnterFilename);
  if (!WriteFile(GetFilename())) {
    return;
  }
  UI::Alert(Message::CiphertextWriteSuccess, 1.5);
  SourceBuffer.clear();
  TargetBuffer.clear();
}
//-------------------------------------------------
template <class T>
void Cipher<T>::InitDecrypt(Cipher<T> const& x) {
  UI::Clearline();
  UI::Prompt(msg::EnterFilename);
  if (!ReadFile(GetFilename())) {
    UI::Alert(msg::InvalidFilename, 1.5);
    return;
  }
  Self().Decrypt(); // CRTP: specialized
  UI::Prompt(msg::EnterFilename);
  if (!WriteFile(GetFilename())) {
    return;
  }
  UI::Alert(msg::PlaintextWriteSuccess, 1.5);
  SourceBuffer.clear();
  TargetBuffer.clear();
}
//-------------------------------------------------
template <class T>
void Cipher<T>::Print(Cipher<T> const& x) {
  UI::Header("Cipher Profile");
  cout << Name << endl;
  cout << Type << endl;
  cout << Self().GetKey() << endl; // Specialized Method;
  UI::Divider();
  sleep(2);
}
//-------------------------------------------------
template <class T>
string Cipher<T>::GetFilename() {
  string f;
  cin >> f;
  return f;
}
//-------------------------------------------------
template <class T>
bool Cipher<T>::ReadFile(string f) {
  ifstream fin;
  fin.open(f.c_str());
  if (!fin) {
    return false;
  }
  string p;
  fin >> p;
  SourceBuffer.push_back(p);
  while (fin >> p) {
    SourceBuffer.push_back(p);
  }
  fin.close();
  return true;
}
//-------------------------------------------------
template <class T>
bool Cipher<T>::WriteFile(string f) {
  ofstream fout;
  fout.open(f.c_str());
for (int i=0; i < TargetBuffer.size(); i++) {
    fout << TargetBuffer[i] << " "; 
  }
  fout.close();
  return true;
}
//------------------------------------------------- 
#endif
