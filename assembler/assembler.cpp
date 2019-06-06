#include <iostream>
#include <fstream>
#include "../String/string.hpp"
#include "stack.hpp"
int varable_counter=1;

String evaluate(const String& left,const String& oper,const String& right,std::ostream& out);

String  infixtopost(const String & rhs,std::ostream& out)
{
  out<<"Infix Expression: "<<rhs<<std::endl;
   String result,right,oper,left;
   std::vector<String> input;
   if(rhs!="")
 
   input =rhs.split(' ');
   

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
   
  out<<"Postfix Expression: "<<result<<std::endl; 
  return result;
}


void  posttoassmbler(const String & rhs,std::ostream& out){
  String result,right,left,oper;
  std::vector<String> input;
  if(rhs!="")
  
  input=rhs.split(' ');

  stack<String>TheStack;

 
  for(size_t index=0;index<input.size();++index){
      
      if(input[index]!='*'&&input[index]!='+'&&input[index]!='/'&&input[index]!='-')    
	{
	  TheStack.push(input[index]);
       }      
      else{
	  right=TheStack.top();
	  TheStack.pop(); 
          left=TheStack.top();
          TheStack.pop();
          TheStack.push(evaluate(left,input[index],right,out));
       }

 
  }
  result=TheStack.top();
  TheStack.pop();
  
}



String evaluate(const String& left,const String& oper,const String& right,std::ostream& out)
{
  out<<"LD    "<<right<<"\n"; 
 if(oper=='+'){
   out<<"AD    "<<left<<"\n";
  }

  else if(oper=='-'){
    out<<"SB    "<<left<<"\n";
  }
  else if(oper=='*'){
    out<<"ML    "<<left<<"\n";
   }
  else if(oper=='/')
  {
    out<<"DV    "<<left<<"\n";
  }
 int tempct=varable_counter;
 String strReturn;
 while(tempct!=0){
   String tmp(char((tempct%10)+'0'));
 
     strReturn=tmp+strReturn;

     tempct=tempct/10;

}

 ++varable_counter;
 out<<"ST    "<<"TMP"+strReturn<<std::endl;
 return "TMP"+strReturn;
} 

int main(int argc, char *argv[])
{
  if (argc > 2)
    {std::cout<<"incorrect amount of arguments"<<std::endl;
      return -1;}
  std::ifstream in(argv[1]);
  if (!in.is_open())
    return -1;
  std::ofstream out;
  if(argc==3) 
    {
      out.open(argv[2]);
    }
  char spush;
 
 while(in>>spush){
    String rhs; 
    rhs=rhs+spush;
  
  while(in.get(spush)){
      rhs=rhs+spush;
      if(spush==';')
        break;
    }

  String post;
 if(out.is_open())
   {
     post=infixtopost(rhs,out);
     posttoassmbler(post,out);
   }    
 else{ 
   post=infixtopost(rhs,std::cout);
   posttoassmbler(post,std::cout);
 }

}   
 
} 
