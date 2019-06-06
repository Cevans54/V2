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
      String result=str.pop();
      // VERIFY
      assert(result== " ");
    }

    {
      // uses defult ctor operrator++  char[] ctor
      //------------------------------------------------------
      // SETUP FIXTURE

      // TEST
      stack<String> str;
      str.push("hello world");
      String result=str.pop();
      // VERIFY
      assert(result == "hello world");

    }
    {
      // uses defult ctor operrator++  char[] ctor
      //------------------------------------------------------
      // SETUP FIXTURE

      // TEST
      stack<String> str;
      str.push("123456789");
      String result=str.pop();
      // VERIFY
      assert(result == "123456789");

    }
    {
      // uses defult ctor operrator++  char[] ctor
      //------------------------------------------------------
      // SETUP FIXTURE

      // TEST
      stack<String> str;
      str.push("hello world");
      String result=str.pop();
      // VERIFY
      assert(result == "hello world");

    }



}
