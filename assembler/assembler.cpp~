#include <iostream>
#include <fstream>
#include "../String/string.hpp"
#include "stack.hpp"
void infixtopost(const String & rhs,std::ostream& out){

  String result,right,oper,left;
  std::vector<String>input;
  if(rhs!="")out<<rhs;
  input = rhs.split(' ');
  stack<String> TheStack;

  int indexer=0;
  while(input[indexer]!= ';')
    {
      if(input[indexer]==')')
        {
          right = TheStack.top();
          TheStack.pop();

          oper=TheStack.top();
          TheStack.pop();

          left=TheStack.top();
          TheStack.pop();

          TheStack.push(left+' '+right+' '+oper);
        }
      else{
        if(input[indexer] !='('){
          TheStack.push(input[indexer]);
        }

      }
      ++indexer;
    }
  result=TheStack.top();
  TheStack.pop();



  out<<result<<std::endl;

}




int main(int argc, char *argv[]){
   if(argc > 2){
      std::cout<<"incorrent amount of atguments"<<std::endl;
      return -1;
   }
   std::ifstream in(argv[1]);
   if(!in.is_open())
     return -1;
   std::ofstream out;
   if(argc==3)
     out.open(argv[2]);
   char spush;
   while(in>>spush){
      String rhs;
      rhs=rhs+spush;
      while(in.get(spush)){
	rhs=rhs+spush;
        if(spush==';')
	  break;
      }
      if(out.is_open())
        infixtopost(rhs,out);
      else
        infixtopost(rhs,std::cout);

   }
}
