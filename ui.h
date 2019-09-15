#ifndef UI_H
#define UI_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <unistd.h>
using namespace std;
//--------------------------------------------  
class UI 
{
  private:
    static int DividerLength;
  public:
    static void Clear() {cout << "\033[2J\033[1;1H";} const
    static void Clearline() {cout << "\033[A\033[2K";} const
    static void Divider() {cout << string(DividerLength, '-') << endl;} const
    static void Header(string h) {
      Clear();
      Divider(); 
      cout << setw(DividerLength/2 + h.length()/2) << h << endl; 
      Divider();
    }
    static void Option(int x, string s) {
      cout << "[" << x << "]" << setw(DividerLength - 3) << s << endl;
    }
    static void Back(int x, string s) {
      Divider(); 
      cout << "[" << x << "]" << setw(DividerLength - 3) << s << endl;
      Divider();
    }
    static void Prompt(string m) {cout << m << ": ";}
    static void Alert(string m, int t) {cout << m << endl; sleep(t); Clearline();}
};
//--------------------------------------------  
#endif
