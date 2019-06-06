//  String class test program
//
//  Tests: operrator[]
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
        String  str("I am great");
	
        // VERIFY
        assert(str=="I am great");
	assert(str[0] =='I' );
    }


    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("da da do di di di doo da");

        // VERIFY
        assert("da da do di di di doo da");
	assert(str[11] ==' ');
    }

   
   
   

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing XXX." << std::endl;

}

