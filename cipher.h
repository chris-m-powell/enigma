#ifndef CIPHER_H
#define CIPHER_H
#include <algorithm>
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
    Cipher() { Name = " "; Type = ' '; }
    Cipher(string n, char t) { Name = n; Type = t; }

    // CRTP methods
    T& Self() { return static_cast<T&>(*this); }
    void InitKeyGen();      
    void InitEncrypt();      
    void InitDecrypt();      
    void Print(Cipher<T> const& x);

    string GetFilename(string = " ") const; // default argument
    bool IsValidFile(const string&) const;
    void GetFile(string, ifstream&) const;
    bool ReadFileToSourceBuffer(const string& = " ");
    void WriteTargetBufferToFile(const string& = " ") const;
    
    
    string GetName() const { return Name; }
    char GetType() const { return Type; }
    void ClearBuffers() { SourceBuffer.clear(); TargetBuffer.clear(); } 
    template <class U> void PrintBuffer(vector<U>&) const; 
};
//------------------------------------------------- 
template <class T>
void Cipher<T>::InitKeyGen() {
  UI::Clearline();
  if (!Self().SetKey(Self().KeyGen())) { // CRTP: specialized
    UI::Clearline();
    UI::Alert(msg::KeyGenSuccess, 1.5);
    ClearBuffers();
  }
}
//-------------------------------------------------
template <class T>
void Cipher<T>::InitEncrypt() {
  UI::Clearline();
  if (ReadFileToSourceBuffer("plaintext")) {
    Self().Encrypt(); // CRTP: specialized
    UI::Clearline();
    WriteTargetBufferToFile("ciphertext");
    UI::Alert(Message::CiphertextWriteSuccess, 1.5);
    ClearBuffers();
    return;
  }
}
//-------------------------------------------------
template <class T>
void Cipher<T>::InitDecrypt() {
  UI::Clearline(); 
  if (ReadFileToSourceBuffer("ciphertext")) {
    Self().Decrypt(); // CRTP: specialized method
    UI::Clearline();
    WriteTargetBufferToFile("decryption");
    ClearBuffers();
    return;
  }
}
//-------------------------------------------------
template <class T>
void Cipher<T>::Print(Cipher<T> const& x) {
  UI::Header("Cipher Profile");
  cout << Name << endl;
  cout << Type << endl;
  cout << Self().GetKey() << endl; // CRTP: specialized method
  UI::Divider();
  sleep(2);
}
//-------------------------------------------------
template <class T>
bool Cipher<T>::IsValidFile(const string& f) const {
  ifstream fin(f.c_str());
  return fin.is_open();
}
//-------------------------------------------------
template <class T>
string Cipher<T>::GetFilename(string t) const {
  string f;
  if (t != " ") {
    UI::Prompt("Enter " + t + " filename");
    cin >> f;
    return f;
  }
  UI::Prompt(msg::EnterFilename);
  cin >> f;
  return f;
}
//-------------------------------------------------
template <class T>
void Cipher<T>::GetFile(string f, ifstream& fin) const {
  if (!IsValidFile(f)) {
    UI::Alert(msg::InvalidFilename, 1.5);
    return;
  }
  fin.open(f.c_str());
}
//-------------------------------------------------
template <class T>
bool Cipher<T>::ReadFileToSourceBuffer(const string& t) {
  ifstream fin;
  GetFile(GetFilename(t), fin);
  if (fin.is_open()) {
    string p;
    fin >> p;
    SourceBuffer.push_back(p);
    while (fin >> p) {
      SourceBuffer.push_back(p);
    }
    fin.close();
    return true; 
  }
 return false; 
}
//-------------------------------------------------
template <class T>
void Cipher<T>::WriteTargetBufferToFile(const string& t) const {
  ofstream fout;
  fout.open(GetFilename(t).c_str());
  for (int i=0; i < TargetBuffer.size(); i++) {
    fout << TargetBuffer[i] << " "; 
  }
  fout.close();
}
//------------------------------------------------- 
template <class T>
template <class U>
void Cipher<T>::PrintBuffer(vector<U>& v) const { 
    for_each(v.begin(), v.end(), [](U i) { // lambda expression 
        cout << i << " "; 
    }); 
    cout << endl; 
} 
//------------------------------------------------- 
#endif
