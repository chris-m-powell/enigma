#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <algorithm>
#include <random>   // for default_random_engine & uniform_int_distribution<int>
#include <chrono>   // to provide seed to the default_random_engine
#include <sstream>
#include <iterator>
using namespace std;
/*------------------------------------------------- 
  Purpose: Generates strings to be used throughout
           user-interface
     Date: 2019.283 
-------------------------------------------------*/ 
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
typedef Message msg;
#endif
