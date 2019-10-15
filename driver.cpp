#include "crypto.h"
//------------------------------------------------- 



int main() {
  

    /* char x = 'A'; */
	/* cout<<"ASCII value of "<<x<<" is "<<(int)x<<endl; */
    
    /* int y = 65; */
    /* cout <<"ASCII index of "<<y<<" is "<<(char)y<<endl; */ 

  cout << RSA::encode("this is a test")[1]; 
  

  /* Crypto::startUp(); */
  return 0;
}
