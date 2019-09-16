#include "crypto.h"
//--------------------------------------------    
void Crypto::StartUp() {
  Message::ReadMessagesFromFile();
  int i;
  do {
    DisplayCipherMenu();
    cin >> i;
    switch(i) {
      case 1: 
        SelectOperation<Rotn>(i);
        break;
      case 2:
        SelectOperation<Cryptogram>(i);
        break;
      case 0:
        UI::Clear();
        return;
    }
  } while(i != 1 || i != 2);
}
//--------------------------------------------
template <class T>
void Crypto::SelectOperation(int i) {
  int j;
  T x;
  do {
    DisplayOperationMenu();
    cin >> j;
    switch(j) {
      case 1: 
        x.InitKeyGen();
        break;
      case 2:
	    x.InitEncrypt();
        break;
      case 3:
        x.InitDecrypt();
        break;
      case 4:
        x.Print(x);
        break;
      case 0:
        return;
    }
  } while(j != 1 || j != 2 || j != 3 || j != 4);
}
