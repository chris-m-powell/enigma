#ifndef CIPHER_H
#define CIPHER_H
#include "ui.h"
#include "message.h"
//------------------------------------------------- 
// Purpose: Provides common interface for each 
//          cipher using CRTP
//    Date: 2019.283 
//------------------------------------------------- 
template <class T>
class Cipher {
  protected:
    string Name; 
    char Type;
    bool KeyFlag;
    vector<string> SourceBuffer;
    vector<string> TargetBuffer;
  public:
    Cipher() { Name = " "; Type = ' '; KeyFlag = 0; }
    Cipher(string n, char t) { Name = n; Type = t; KeyFlag = 0; }
    T& self() { return static_cast<T&>(*this); }
    void initKeyGen();
    void initEncrypt();      
    void initDecrypt();      
    void print();
    string getFilename(string = " ") const; // Default argument
    bool isValidFile(const string&) const;
    void getFile(string, ifstream&) const;
    bool readFileToSourceBuffer(const string& = " ");
    void writeTargetBufferToFile(const string& = " ") const;
    string wordToLower(string);
    string getName() const { return Name; }
    char getType() const { return Type; }
    void clearBuffers() { SourceBuffer.clear(); TargetBuffer.clear(); } 

    template <class U> void printBuffer(vector<U>&) const; 
};
//------------------------------------------------- 
template <class T>
string Cipher<T>::wordToLower(string Word) {
  for (int i = 0; i < Word.length(); i++) 
    Word[i] = tolower(Word[i]);
  return Word; 
}
//------------------------------------------------- 
template <class T>
void Cipher<T>::initKeyGen() {
  self().setKey(self().keyGen()); // CRTP: specialized
  if (KeyFlag == 0) {
    UI::alert(msg::KeyGenFailure, 1.5);
    return;  
  }
  UI::alert(msg::KeyGenSuccess, 1.5);
  clearBuffers();
}
//-------------------------------------------------
template <class T>
void Cipher<T>::initEncrypt() {
  if (KeyFlag == 0) {
    UI::alert(msg::KeyGenFailure, 1.5);
    return;
  }
  if (!readFileToSourceBuffer("plaintext"))
    return;
  for (int i = 0; i < SourceBuffer.size(); ++i) 
    TargetBuffer.push_back(self().encrypt(SourceBuffer[i])); // CRTP: specialized
  writeTargetBufferToFile("ciphertext");
  UI::alert(msg::CiphertextWriteSuccess, 1.5);
  /* clearBuffers(); */
}
//-------------------------------------------------
template <class T>
void Cipher<T>::initDecrypt() {
  if (KeyFlag == 0) {
    UI::alert(msg::KeyGenFailure, 1.5);
    return;
  }
  if (!readFileToSourceBuffer("ciphertext"))
    return;
  for (int i = 0; i < SourceBuffer.size(); ++i) 
    TargetBuffer.push_back(self().decrypt(SourceBuffer[i])); // CRTP: specialized
  writeTargetBufferToFile("decryption");
  clearBuffers();
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
bool Cipher<T>::readFileToSourceBuffer(const string& t) {
  ifstream fin;
  getFile(getFilename(t), fin);
  if (fin.is_open()) {
    string p;
    fin >> p;
    SourceBuffer.push_back(p);
    while (fin >> p) 
      SourceBuffer.push_back(p);
    fin.close();
    return true; 
  }
 return false; 
}
//-------------------------------------------------
template <class T>
void Cipher<T>::writeTargetBufferToFile(const string& t) const {
  ofstream fout;
  fout.open(getFilename(t).c_str());
  for (int i=0; i < TargetBuffer.size(); i++)
    fout << TargetBuffer[i] << " ";
  fout.close();
}
//------------------------------------------------- 
template <class T>
void Cipher<T>::print() {
  UI::header("Cipher Profile");
  cout << Name << endl;
  cout << Type << endl;
  cout << self().getKey() << endl; // CRTP: specialized method
  printBuffer(SourceBuffer);
  printBuffer(TargetBuffer);
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
#endif
