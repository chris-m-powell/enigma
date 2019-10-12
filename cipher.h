#ifndef CIPHER_H
#define CIPHER_H
#include "ui.h"
#include "message.h"
/*------------------------------------------------- 
 Purpose: Provides common interface for each 
          cryptographic cipher using the
          Curiously Recursive Template Pattern
    Date: 2019.283 
-------------------------------------------------*/ 
template <class T>
class Cipher {
  protected:
    string Name; 
    bool KeyFlag;
    vector<string> Buffer;
  public:
    Cipher() { Name = " "; KeyFlag = 0; }
    Cipher(string n, char t) { Name = n; KeyFlag = 0; }
    T& derived() { return static_cast<T&>(*this); } // CRTP: deference pointer to object of derived class
    void initKeyGen();
    void initEncrypt();      
    void initDecrypt(); 
    void print();
    string getFilename(string = " ") const; // Default argument
    bool isValidFile(const string&) const;
    void getFile(string, ifstream&) const;
    bool readFileToBuffer(const string& = " ");
    string wordToLower(string);
    string getName() const { return Name; }
    template <class U> void printBuffer(vector<U>&) const; 
    template <class U> void writeBufferToFile(vector<U>&, const string& = " ") const; 
};
//------------------------------------------------- 
template <class T>
string Cipher<T>::wordToLower(string w) {
  transform(w.begin(), w.end(), w.begin(), [&](char i) { // lambda expression
    return tolower(i);
  });
  return w; 
}
//------------------------------------------------- 
template <class T>
void Cipher<T>::initKeyGen() {
  derived().setKey(derived().keyGen()); // CRTP: specialized
  if (KeyFlag == 0) {
    UI::alert(msg::KeyGenFailure, 1.5);
    return;  
  }
  UI::alert(msg::KeyGenSuccess, 1.5);
}
//-------------------------------------------------
template <class T>
void Cipher<T>::initEncrypt() {
  if (KeyFlag == 0) {
    UI::alert(msg::KeyGenFailure, 1.5);
    return;
  }
  if (!readFileToBuffer("plaintext"))
    return;
  transform(Buffer.begin(), Buffer.end(), Buffer.begin(), [&](string i) { // lambda expression
    i = wordToLower(i);
    return derived().encrypt(i); // CRTP: specialized
  });
  writeBufferToFile(Buffer, "ciphertext");
  UI::alert(msg::CiphertextWriteSuccess, 1.5);
}
//-------------------------------------------------
template <class T>
void Cipher<T>::initDecrypt() {
  if (KeyFlag == 0) {
    UI::alert(msg::KeyGenFailure, 1.5);
    return;
  }
  if (!readFileToBuffer("ciphertext"))
    return;
  transform(Buffer.begin(), Buffer.end(), Buffer.begin(), [&](string i) { // lambda expression
    return derived().decrypt(i); // CRTP: specialized
  });
  writeBufferToFile(Buffer, "decryption");
  UI::alert(msg::DecryptionSuccess, 1.5);
}
//-------------------------------------------------
template <class T>
bool Cipher<T>::isValidFile(const string& f) const {
  ifstream fin(f.c_str());
  return fin.is_open();
}
//-------------------------------------------------
template <class T>
string Cipher<T>::getFilename(string t) const {
  string f;
  if (t != " ") {
    UI::prompt("Enter " + t + " filename");
    cin >> f;
    return f;
  }
  UI::prompt(msg::EnterFilename);
  cin >> f;
  return f;
}
//-------------------------------------------------
template <class T>
void Cipher<T>::getFile(string f, ifstream& fin) const {
  if (!isValidFile(f)) {
    UI::alert(msg::InvalidFilename, 1.5);
    return;
  }
  fin.open(f.c_str());
}
//-------------------------------------------------
template <class T>
bool Cipher<T>::readFileToBuffer(const string& t) {
  ifstream fin;
  getFile(getFilename(t), fin);
  if (fin.is_open()) {
    Buffer.clear();
    string p;
    fin >> p;
    Buffer.push_back(p);
    while (fin >> p) 
      Buffer.push_back(p);
    fin.close();
    return true; 
  }
 return false; 
}
//------------------------------------------------- 
template <class T>
void Cipher<T>::print() {
  UI::header("Cipher Profile");
  cout << Name << endl;
  cout << derived().getKey() << endl; // CRTP: specialized method
  printBuffer(Buffer);
  UI::divider();
  sleep(2);
}
//-------------------------------------------------
template <class T>
template <class U>
void Cipher<T>::printBuffer(vector<U>& v) const { 
  for_each(v.begin(), v.end(), [](U i) { // lambda expression 
      cout << i << " "; 
  }); 
  cout << endl; 
} 
//------------------------------------------------- 
template <class T>
template <class U>
void Cipher<T>::writeBufferToFile(vector<U>& v, const string& t) const { 
  ofstream fout;
  fout.open(getFilename(t).c_str());
  for_each(v.begin(), v.end(), [&fout](U i) { // lambda expression 
      fout << i << " "; 
  }); 
  fout.close();
} 
//------------------------------------------------- 
#endif
