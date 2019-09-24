#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <unistd.h>
using namespace std;
//-------------------------------------------- 
class Message;
typedef Message msg;
//-------------------------------------------- 
class Message {
  public:
    static void readMessagesFromFile();
    static string KeyGenFailure;
    static string KeyGenSuccess;
    static string EnterFilename;
    static string InvalidFilename;
    static string PlaintextReadSuccess;
    static string EncryptionSuccess;
    static string CiphertextWriteSuccess;
    static string CiphertextReadSuccess;
    static string DecryptionSuccess;
    static string PlaintextWriteSuccess;
};
//--------------------------------------------
#endif
