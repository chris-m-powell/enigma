#include "message.h"
//--------------------------------------------    
//Static member delcartions
string msg::KeyGenSuccess;
string msg::EnterFilename;
string msg::InvalidFilename;
string msg::PlaintextReadSuccess;
string msg::EncryptionSuccess;
string msg::CiphertextWriteSuccess;
string msg::CiphertextReadSuccess;
string msg::DecryptionSuccess;
string msg::PlaintextWriteSuccess;
//--------------------------------------------    
void Message::ReadMessagesFromFile() {
  ifstream fin;
  fin.open("message.txt");
  getline(fin, msg::KeyGenSuccess);
  getline(fin, msg::EnterFilename);
  getline(fin, msg::InvalidFilename);
  getline(fin, msg::PlaintextReadSuccess);
  getline(fin, msg::EncryptionSuccess);
  getline(fin, msg::CiphertextWriteSuccess);
  getline(fin, msg::CiphertextReadSuccess);
  getline(fin, msg::DecryptionSuccess);
  getline(fin, msg::PlaintextWriteSuccess);
}
//--------------------------------------------    
