//  String class test program
//
//  Tests: reset
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        //Test
        String  str("ab");
	String str3("b");
        int str2=str.findstr(str3);
	std::cerr<<str2<<std::endl;
        // VERIFY
        assert(1==str2);
    }    
   {
        //------------------------------------------------------
        //Test
        String  str("abcdefghijklmnopqrlstuwxyz");
	String str3("opqrl");
        int str2=str.findstr(str3);
         // VERIFY
        assert(14==str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("abcdefghijklmnopqrstuwxyz?????");
        int str2=str.findstr("????");
        // VERIFY
        assert(25==str2);
    }
    
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("abcdefghijk1234567lmnopqrstuwxyz?????");
        int str2=str.findstr("1234567");
        // VERIFY
        assert(11==str2);

   }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("abcdefghijk1234567lmnopqrstuwxyz?????");
        int str2 =str.findstr("1ab2");
        // VERIFY
        assert(-1==str2);


     }
    
   // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Array ctor." << std::endl;

}

