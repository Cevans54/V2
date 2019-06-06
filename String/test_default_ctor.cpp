//  String class test program
//
//  Tests: defualt
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        // uses defult ctor operrator++  char[] ctor 
	//------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String str;

        // VERIFY
        assert(str == "");
   }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing defualt." << std::endl;

}

