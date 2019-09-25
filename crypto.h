#ifndef CRYPTO_H
#define CRYPTO_H
#include "rotn.h"
#include "cryptogram.h"
//-------------------------------------------- 
class Crypto {
  public:
    Crypto() {};
    static void startUp();
    static void displayCipherMenu() {
      UI::header("SELECT CIPHER");
      UI::option(1,"ROT-N");
      UI::option(2,"CRYPTOGRAM");
      UI::back(0,"QUIT");
    }
    static void displayOperationMenu() {
      UI::header("SELECT OPERATION");
      UI::option(1, "KEY GENERATION");
      UI::option(2, "ENCRYPTION");
      UI::option(3, "DECRYPTION");
      /* UI::option(4, "INFO"); */
      UI::back(0,"BACK");
    }
    template <class T> static void selectOperation(int);
};
//--------------------------------------------
#endif
