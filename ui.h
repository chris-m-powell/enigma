#ifndef UI_H
#define UI_H
#include "message.h"
//------------------------------------------------- 
// Purpose: Provides API for user-interface;
//          primarily used by crypto class to 
//          construct menu system
//    Date: 2019.283 
//------------------------------------------------- 
class UI {
  private:
    static int DividerLength;
  public:
    static void clear() { cout << "\033[2J\033[1;1H"; } const
    static void clearline() { cout << "\033[A\033[2K"; } const
    static void divider() { cout << string(DividerLength, '-') << endl; } const
    static void header(string h) {
      clear();
      divider(); 
      cout << setw(DividerLength/2 + h.length()/2) << h << endl; 
      divider();
    }
    static void option(int x, string s) {
      cout << "[" << x << "]" << setw(DividerLength - 3) << s << endl;
    }
    static void back(int x, string s) {
      divider(); 
      cout << "[" << x << "]" << setw(DividerLength - 3) << s << endl;
      divider();
    }
    static void prompt(string m) { clearline(); cout << m << ": "; }
    static void alert(string m, int t) { clearline(); cout << m << endl; sleep(t); clearline(); }
};
#endif
