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
    vector<char> CharVec;
    vector<int> IntVec;
  public:
    Cipher() { Name = " "; KeyFlag = 0; }
    T& derived() { return static_cast<T&>(*this); } // CRTP: deference pointer to object of derived class
    void initKeyGen();
    void initEncrypt();      
    void initDecrypt(); 
    string getFilename(string = " ") const;
    bool isValidFile(const string&) const;
    void getFile(string, ifstream&) const;
    string getName() const { return Name; }
    bool isValidKey() const;
};
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
bool Cipher<T>::isValidKey() const {
  if (KeyFlag == 0) {
      UI::alert(msg::KeyGenFailure, 1.5);
      return false;
  }
  return true;
}
//-------------------------------------------------
template <class T>
void Cipher<T>::initEncrypt() {
  if (!isValidKey()) return;
  if (!derived().loadPlaintext()) return; 
  derived().encode();
  derived().encrypt();
  derived().saveCiphertext();
  UI::alert(msg::CiphertextWriteSuccess, 1.5);
}
//-------------------------------------------------
template <class T>
void Cipher<T>::initDecrypt() {
  if (!isValidKey()) return;
  if (!derived().loadCiphertext()) return;
  derived().decrypt();
  derived().decode();
  derived().savePlaintext();
  UI::alert(msg::DecryptionSuccess, 1.5);
}
//-------------------------------------------------
template <class T>
bool Cipher<T>::isValidFile(const string& f) const {
  ifstream fin(f);
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
  fin.open(f, ios::binary);
}
//-------------------------------------------------
/* template <class T> */
/* template <class U> */
/* void Cipher<T>::printBuffer(vector<U>& v) const { */ 
  /* cout << endl; */
  /* for_each(v.begin(), v.end(), [&v](U i) { cout << i << " "; }); */ 
  /* cout << endl << endl; */ 
/* } */ 
#endif
