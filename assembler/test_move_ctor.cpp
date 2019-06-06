#include "stack.hpp"
#include <iostream>
#include <cassert>
#include "../string/string.hpp"
//===================================================================================

stack<String> myfunc(){
  stack <String> temp;
  return temp;
}






int main() {
    {
      // test move ctor
      //------------------------------------------------------
      // SETUP FIXTURE

      // TEST
      stack<String>a(myfunc());
    
      // VERIFY
    }

    {
      // test move asign 
      //------------------------------------------------------
      // SETUP FIXTURE

      // TEST
      stack<String> str;
      // VERIFy
      str=myfunc();
    }


}
