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
        String  str("a");
	str.resetCapacity(50);
        // VERIFY
        assert(str.capacity()==50);
    }    
   {
        //------------------------------------------------------
        //Test
        String  str("a.?");
	str.resetCapacity(350);
        // VERIFY
        assert(str.capacity()==350);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("aABb ");
	str.resetCapacity(256);
        // VERIFY
        assert(str.capacity()==256);
    }
    
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("aABb ");
	str.resetCapacity(3);
        // VERIFy
	assert(str.capacity()==3);
        assert(str=="aA");   
   }


	// ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Array ctor." << std::endl;

}

