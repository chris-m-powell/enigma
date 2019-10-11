#ifndef CRYPTO_H
#define CRYPTO_H
#include "rotn.h"
#include "cryptogram.h"
//------------------------------------------------- 
// Purpose: Generates menu for cipher selection
//          and submenu for operation selection:
//    Date: 2019.283 
//------------------------------------------------- 
class Crypto {
  public:
    Crypto() {};
    static void startUp();
    static void displayCipherMenu();
    static void displayOperationMenu();
    template <class T> static void selectOperation(int);
};
#endif
