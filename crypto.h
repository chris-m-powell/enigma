#ifndef CRYPTO_H
#define CRYPTO_H
#include "cipher.h"
#include "rotn.h"
#include "cryptogram.h"
#include "message.h"
//-------------------------------------------- 
class Crypto {
  public:
    Crypto(){};
    static void StartUp();
    static void DisplayCipherMenu() {
      UI::Header("SELECT CIPHER");
      UI::Option(1,"ROT-N");
      UI::Option(2,"CRYPTOGRAM");
      UI::Back(0,"QUIT");
    }
    
    static void DisplayOperationMenu() {
      UI::Header("SELECT OPERATION");
      UI::Option(1, "KEY GENERATION");
      UI::Option(2, "ENCRYPTION");
      UI::Option(3, "DECRYPTION");
      UI::Option(4, "INFO");
      UI::Back(0,"BACK");
    }
   
    template <class T>
    static void SelectOperation(int, T&);
};
//--------------------------------------------
#endif
