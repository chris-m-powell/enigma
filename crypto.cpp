#include "crypto.h"
//--------------------------------------------    
void Crypto::startUp() {
  Message::readMessagesFromFile();
  int i = 0;
  while(i != 1 || i != 2 || i != 3) {
    displayCipherMenu();
      cin >> i;
      switch(i) {
        case 1: 
          selectOperation<Rotn>(i);
          break;
        case 2:
          selectOperation<Cryptogram>(i);
          break;
        case 3: 
          selectOperation<RSA>(i);
          break;
        case 0:
          UI::clear();
          return;
    }
  }
}
//--------------------------------------------    
void Crypto::displayCipherMenu() {
  UI::header("SELECT CIPHER");
  UI::option(1,"ROT-N");
  UI::option(2,"CRYPTOGRAM");
  UI::option(3,"RSA");
  UI::back(0,"QUIT");
}
//--------------------------------------------
template <class T>
void Crypto::selectOperation(int i) {
  int j;
  T x; // declares object of dervied class
  while(j != 1 || j != 2 || j != 3) {
    displayOperationMenu(x.getName());
    cin >> j;
    switch(j) {
      case 1: 
        x.initKeyGen(); // CRTP: simulates dynamic dispatch
        break;
      case 2:
	    x.initEncrypt(); // CRTP: simulates dynamic dispatch
        break;
      case 3:
        x.initDecrypt(); // CRTP: simulates dynamic dispatch
        break;
      case 0:
        return;
    }
  }
}
//--------------------------------------------    
void Crypto::displayOperationMenu(string n) {
  UI::header("SELECT " + n + " OPERATION");
  UI::option(1, "KEY GENERATION");
  UI::option(2, "ENCRYPTION");
  UI::option(3, "DECRYPTION");
  UI::back(0,"BACK");
}
//--------------------------------------------
