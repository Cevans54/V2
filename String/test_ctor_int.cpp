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
        String  str(5);

        // VERIFY
        assert(str.capacity()==5);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(10);

        // VERIFY
        assert(str.capacity()== 10);
    }

 

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing int ctor." << std::endl;

}

