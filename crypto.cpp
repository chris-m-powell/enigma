#include "crypto.h"
//--------------------------------------------    
void Crypto::startUp() {
  Message::readMessagesFromFile();
  int i;
  do {
    displayCipherMenu();
    cin >> i;
    switch(i) {
      case 1: 
        selectOperation<Rotn>(i);
        break;
      case 2:
        selectOperation<Cryptogram>(i);
        break;
      case 0:
        UI::clear();
        return;
    }
  } while(i != 1 || i != 2);
}
//--------------------------------------------
template <class T>
void Crypto::selectOperation(int i) {
  int j;
  T x;
  do {
    displayOperationMenu();
    cin >> j;
    switch(j) {
      case 1: 
        x.initKeyGen();
        break;
      case 2:
	    x.initEncrypt();
        break;
      case 3:
        x.initDecrypt();
        break;
      /* case 4: */
        /* x.print(); */
        /* break; */
      case 0:
        return;
    }
  /* } while(j != 1 || j != 2 || j != 3 || j != 4); */
  } while(j != 1 || j != 2 || j != 3);
}
//--------------------------------------------
