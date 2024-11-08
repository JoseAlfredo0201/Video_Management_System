#include "Includes/App.h"
#include<iostream>

using namespace std;

int main(){
  App *myApp = new App();
  //myApp->debug();
  myApp->main_loop();
  
  
  return 0;
}
