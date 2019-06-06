//  String class test program
//
//  Tests: reset
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <vector>
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        //Test
        String str("hello world");
        std::vector<String> output=str.split(' ');
	// VERIFY
        String teststr=output[0];
        std::cerr<<output[0]<<std::endl;
        std::cerr<<output[1]<<std::endl;
        assert(output[0]=="hello");
        assert(output[1]=="world");   
    }    
   {
        //------------------------------------------------------
        //Test
        String  str("hello world what is the meaning of life.");
        std::vector <String> output=str.split('w');
         // VERIFY
        std::cerr<<'"'<<output[0]<<'"'<<std::endl;
        assert(output[0]=="hello ");
        std::cerr<<'"'<<output[1]<<'"'<<std::endl;
        assert(output[1]=="orld ");
        std::cerr<<'"'<<output[2]<<'"'<<std::endl;
        assert(output[2]=="hat is the meaning of life.");   
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("hello.world.what.is the meaning.of life");
        std::vector <String> output=str.split('.');
        // VERIFY
        assert(output[0]=="hello");
        std::cerr<<output[0]<<std::endl;
        assert(output[1]=="world");
        assert(output[2]=="what");
        assert(output[3]=="is the meaning");    
        assert(output[4]=="of life");  
    }
    
	{
        //------------------------------------------------------
        // SETUP FIXTURE
        //Test
        String  str("hello; world ;what is; the meaning ;of life.");
        std::vector <String> output=str.split(';');
        // VERIFY
        assert(output[0]=="hello");
        assert(output[1]==" world ");
        assert(output[2]=="what is");
        assert(output[3]==" the meaning ");
        assert(output[4]=="of life.");
   
     }
  
    
   // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing Array split." << std::endl;

}

