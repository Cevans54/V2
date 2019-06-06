//  String class test program
//
//  Tests: Array ctor
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
        String  str("a");

        // VERIFY
        assert(str =="a");
    }    
   {
        //------------------------------------------------------
        //Test
        String  str("a.?");

        // VERIFY
        assert(str == "a.?");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("aABb ");

        // VERIFY
        assert(str == "aABb ");
    }
    
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("aABb ");
	String str2("aABb ");
        // VERIFY
        assert(str == str2);
    }


	// ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Array ctor." << std::endl;

}

