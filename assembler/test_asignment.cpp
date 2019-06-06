#include "stack.hpp"
#include <iostream>
#include <cassert>
#include "../String/string.hpp"

//===================================================================================
int main() {
    {
      // uses defult ctor operrator++  char[] ctor
      //------------------------------------------------------
      // SETUP FIXTURE

      
      // TEST
      stack<String> str;
      str.push(" ");
      stack<String> str2=str;       
      String swaped1=str2.pop();
      // VERIFY
      assert(" "== swaped1);
     
    }
    {
      // uses defult ctor operrator++  char[] ctor
      //------------------------------------------------------
      // SETUP FIXTURE


      // TEST
      stack<String> str;
      str.push(" ");
      str.push("hello world");
      stack<String> str2=str;
      String swaped1=str2.pop();
      String swaped2=str2.pop();

      // VERIFY
      assert("hello world"==swaped1);
      assert(" "== swaped2);
    }

   

}
