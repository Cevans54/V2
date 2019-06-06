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
      str2.swap(str); 
      String swaped1=str2.pop();
      std::cerr<<'"'<<swaped1<<'"'<< std::endl;
      String swaped2=str.pop(); 
      std::cerr<<'"'<<swaped2<<'"'<< std::endl;
      // VERIFY
      assert(swaped2  == swaped1);
      std::cerr<< "finshed test one"<< std::endl;
    }
    {
      // uses defult ctor operrator++  char[] ctor
      //------------------------------------------------------
      // SETUP FIXTURE


      // TEST
      stack<String> str;
      str.push(" ");
      stack<String> str2(str);
      str2.push("hello world");
      
      String result1 = str.pop();
      String result2 = str2.pop();

	// VERIFY
	assert(" " == result1);
        assert("hello world" == result2);    
   }
    {
      // uses defult ctor operrator++  char[] ctor
      //------------------------------------------------------
      // SETUP FIXTURE


      // TEST
      stack<String> str;
      str.push(" ");
      str.push("hello world");
      stack<String> str2;
      str2.push("shasha shale it shake it up");
      str2.swap(str);
      
      String result1 = str.pop();
      String result2 = str2.pop();
      String result3 = str2.pop();
      // VERIFY
      assert("shasha shale it shake it up" == result1);
      assert("hello world" == result2);
      assert(" " == result3);
    }
   
}
