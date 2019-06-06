//  String class test program
//
//  Tests: char constructor
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

	// TEST
	String str(5,"hi");

        // VERIFY
        assert(str.capacity()==5);
        assert(str=="hi");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(10,"hello world");

        // VERIFY
        assert(str.capacity()== 10);
        assert(str=="hello worl");
    }

 

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing int string ctor." << std::endl;

}

