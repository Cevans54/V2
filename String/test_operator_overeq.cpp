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
        String  str2;
        // VERIFY
        str=str2;
	assert(str == str2);
    }    
   {
        //------------------------------------------------------
        //Test
        String  str("a.?");
        String  str2;   
        // VERIFY
        str=str2;
	assert(str == str2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("aABb ");
	String  str2;
        // VERIFY
        str=str2;
	assert(str == str2);
    }
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String str("aABb ");
	String str2;
        // VERIFY
        str=str2;
        assert(str == str2);
    }


	// ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing =." << std::endl;

}

