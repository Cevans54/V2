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
    

      // VERIFY
      assert(str.isEmpty());
    }

    {
      // uses defult ctor operrator++  char[] ctor
      //------------------------------------------------------
      // SETUP FIXTURE

      // TEST
      stack<String> str;
      // VERIFY
      assert(str.isEmpty());

    }
}
