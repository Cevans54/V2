#include "bigint.hpp"
#include <iostream>
#include <cassert>
//CAP= 100 
//sets all of aray to be equal to to 0
bigint::bigint()
{
  for (int i = 0;i<CAP; ++i)
    number[i]=0;

}
bigint::bigint(int rhs):bigint()
{
  int rhsN=rhs;
  int counter(0);
  while(counter!=99)
  {
    number[counter]= rhsN % 10;
    rhsN=rhsN/10;
    ++counter;
  }

}

bigint::bigint(const char rhs[]):bigint(){
  int endstr=0;
  while(rhs[endstr]!='\0')
    ++endstr;
 


  --endstr;

  int counter=0;
  while( counter<CAP && counter<=endstr )
    {
      number[counter]=rhs[endstr-counter]-'0';      
      ++counter;          
    }
}



bool bigint::operator==(const bigint & rhs) const
{
    for (int i = 0 ; i < CAP; ++i)
      {
        if (number[i]!=rhs.number[i])return false;
        
       }
return true;
}


std::ostream& operator<<(std::ostream & out, const bigint& rhs){
  int i = 99;
  //looks for the frist none null
  while (rhs.number[i]==0){
    --i;
    if (i==0)
      std::cout<<rhs.number[i];
  }
  // cout put from frsit non null interger to the end of the array
  int checker=0;
  while(i>=0){
    ++checker;
    std::cout << rhs.number[i];
    if ((checker % 50) == 0)
      out << std::endl;
    --i;
  }

  return out;
}

bigint bigint::operator +(const bigint & rhs)const
{
  bool carry=false;
  bigint lhs;
  for(int i=0; i <CAP;++i){
    int result = rhs.number[i]+number[i];
    if (carry){
        result++;
        carry=false;
    }
    if(result>= 10)carry=true;

    result=result%10;
    
    lhs.number[i]=result;
  }
  return lhs;

}

int bigint::operator[](int biIndex)const
{
  if(biIndex < CAP && biIndex > -1) return number[biIndex];
  return -1;

}
int& bigint::operator[](int biIndex)
{
  assert(biIndex < CAP && biIndex > -1);
  return number[biIndex];


}
std::istream& operator>>(std::istream& in, bigint& rhs)
{
  char temp[CAP];
  char Rfile;
  int i = 0;
  while (in>>Rfile)
    {
      if (Rfile==';')
        {
	  break;
        }
      temp[i] = Rfile;
      ++i;
    }
  temp[i] = 0;
  rhs = bigint(temp);
  return in;
}

