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
        int str2=str.findchar('b');
	// VERIFY
        assert(1==str2);
    }    
   {
        //------------------------------------------------------
        //Test
        String  str("abcdefghijklmnopqrlstuwxyz");
        int str2=str.findchar('q');
         // VERIFY
        assert(16==str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("abcdefghijklmnopqrstuwxyz?????");
        int str2=str.findchar('?');
        // VERIFY
        assert(25==str2);
    }
    
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("abcdefghijk/1234567lmnopqrstuwxyz?????");
        int str2=str.findchar('/');
        // VERIFY
        assert(11==str2);

   }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("abcdefghijk1234567lmnopqrstuwxyz?????");
        int str2 =str.findchar('(');
        // VERIFY
        assert(-1==str2);


     }
    
   // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Array ctor." << std::endl;

}

