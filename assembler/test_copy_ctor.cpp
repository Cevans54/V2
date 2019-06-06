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
      stack<String> str2(str);
      String result2 = str2.pop();
      // VERIFY
      assert(" " == result2);
    }
        {
      // uses defult ctor operrator++  char[] ctor
      //------------------------------------------------------
      // SETUP FIXTURE


      // TEST
      stack<String> str;
      str.push(" ");
      str.push("hello world");
      stack<String> str2(str);
      String result1 = str2.pop();
      String result2 = str2.pop();

	// VERIFY
	assert("hello world" == result1);
        assert(" " == result2);    
   }
   {
      // uses defult ctor operrator++  char[] ctor
      //------------------------------------------------------
      // SETUP FIXTURE


      // TEST
      stack<String> str;
      str.push(" ");
      str.push("hello world");
      str.push("shasha shale it shake it up");
      stack<String> str2(str);
      String result1 = str2.pop();
      String result2 = str2.pop();
      String result3 = str2.pop();
      // VERIFY
      assert("shasha shale it shake it up" == result1);
      assert("hello world" == result2);
      assert(" " == result3);
    }
   {
      // uses defult ctor operrator++  char[] ctor
      //------------------------------------------------------
      // SETUP FIXTURE


      // TEST
      stack<String> str;
      str.push(" ");
      str.push("hello world");
      stack<String> str2(str);
      String result1 = str2.pop();
      String result2 = str2.pop();

      // VERIFY
      assert("hello world" == result1);
      assert(" " == result2);
    }
    
}
