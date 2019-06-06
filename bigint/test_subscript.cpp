// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi[0]==4);
        assert(digit==4);
    }
   {
        // Setup
        bigint bi(250);

        // Test
        bi[2] = 5;

        // Verify
        assert(bi[2]==5);
    }

    {
        // Setup
        bigint bi(6789);
       
        // Test
        int digit = 7;
        std::cerr <<"bi[1]== "<<bi[1] << std::endl;
        // Verify
        assert(bi[1] == 8);
   
    }

    {
        // Setup
        bigint bi("90000000000000000000000000");
        // Test
        int digit = bi[7];

        // Verify
        assert(bi[8]==0);
        assert(digit==0);
    }


    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
}

