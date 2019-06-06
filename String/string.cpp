#include "string.hpp"
#include <iostream>
#include <cassert>
#include <vector> 
//CAP = 256

// seats array equal to null
String::String()
{
	Capacity=DEFAULT_STRING_CAPACITY;
	str= new char[256];
	str[0]=0;
}

String::String(char input)
{
   Capacity=DEFAULT_STRING_CAPACITY;
   str= new char[256];
   str[0]=input;
   str[1]='\0';
}

String::String(const char rhs[])
{
   int length=0;
   Capacity = DEFAULT_STRING_CAPACITY;

   while(rhs[length]!='\0')
      ++length;   

   if (length+1 > Capacity)
     Capacity=length+1;

   str=new char[Capacity];   
   int i = 0;
      
   while(rhs[i] != 0){
         str[i] = rhs[i];
         ++i;
   }
   str[i] = 0;
}

String::String(int size, const char* entry)
{
 Capacity=size;
 str=new char[size];
 int lengthoe=0;
   
   while(entry[lengthoe]!=0)
   {
      ++lengthoe;
   }
   
   if(Capacity<lengthoe)
   {
      int i=0;	
     while(i<size)
      { 
      str[i]=entry[i];
      ++i;
         if(size==(i+1))
            str[size]=0;
      }
   }
if(lengthoe<Capacity)
   {
     int i =0;
     while(i<lengthoe)
      {
      str[i]=entry[i];
      ++i;
         if(lengthoe==(i+1))
            str[lengthoe]=0;
      }
  }
   
}

String::String(int x){
   Capacity=x; 
   str= new char [Capacity];
}
String::~String(){

delete[] str;

}
String& String::operator= (String rhs)
{
   if(str==rhs.str){
      return *this;
   }
   delete[] str;
   Capacity=rhs.Capacity;
   str=new char[Capacity];
   for(int i=0;i<Capacity;++i){
      str[i]=rhs.str[i];
   }

return *this;
}
String::String (const String& org)
{
   Capacity=org.Capacity;
   str=new char[Capacity];
   for(int i=0;i<Capacity;++i)str[i]=org.str[i];
}

void String::swap(String& rhs)
{
   char*temp=str;
   str=rhs.str;
   rhs.str=temp;
   
   int temp2=Capacity;
   Capacity=rhs.Capacity;
   rhs.Capacity=temp2;
    
}

bool String::operator==(const String& rhs)const
{
if (length()!=rhs.length())
	return false;
	

        for(int i=0;i<length();++i)
	{
		if(str[i] != rhs.str[i])return false;

	}
   return true;
}


String String::substr(int start, int end)const{
   String result;

if(start>=0&&end>start&&end<=length())
{   
   int index=0;
      
   for(int i = start; i < end; ++i)
   {
           result.str[index] = str[start+index];
           ++index;
           
 
   }
   result[index] = 0;
   return result;   
}
 return result;

}
int String::findchar(const char rhs)
{
   for(int i=0;i<length();++i)
	if(str[i]==rhs)return i; 

 return -1;
}

int String::findstr(const String& rhs)
{
   for(int i=0;i<length();++i)
   {  if(rhs[0]==str[i])
      { 
         for(int j=1;j<length();++j)
	 {
          if(str[i+j]!=rhs[j])return -1;
          if(rhs.length()==1||j==(rhs.length()-1))
             return (i);
         
         }

      }

   }
return -1;
}
int String::length()const
{
   int length=0;
   while(str[length]!='\0')
        ++length;
   return length;

}
void String::resetCapacity (int Nsize)
{
   char *str2;
   str2=new char[Nsize];

   if(Nsize>length())
   {
      for(int i=0;i<length();++i)
         str2[i]=str[i];

      str2[length()]=0;
   }
   if(Nsize<=length())
   {
      for(int i=0;i<Nsize-1;++i)
        str2[i]=str[i];
      str2[Nsize-1]=0;
   }

   Capacity=Nsize;
   delete [] str;
   str=str2;

}

int String::capacity() const
{
return Capacity;
}

bool operator!=(const String& lhs,const String& rhs)
{
   if( lhs==rhs)
      return false;
   return true;
}

bool operator==(const char lhs[],const String rhs)
{
   String copy(lhs);
   return copy==rhs;

}

bool operator==(const char lhs,const String rhs)
{
   String copy(lhs);
   return (copy==rhs);
}
bool operator==(const char* lhs, const String & rhs)
{
  String copy(lhs);
  return(copy==rhs);
}
bool String::operator<(const String& rhs)const
{
int i = 0;
   while((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i]))
   {
      ++i;
   }
      return str[i] < rhs.str[i];
}

bool operator>(const char lhs[] ,const String& rhs)
{
 String copy(lhs); 
 return rhs<copy;

}


String String::operator+(const String& rhs)const
{                           
   String result(str);
    if((rhs.length()+length()+1)>Capacity)
      result.resetCapacity(rhs.length()+length()+1);
   int offset = length();                       
   int i = 0;
	
   while(rhs.str[i] != 0){
      result.str[offset + i] = rhs.str[i];
      ++i;
}
	
   result.str[offset + i] = 0;
return result;
}


String operator+(const char lhs[],  const String& rhs)
{
String copy(lhs);
 return copy+rhs;

}

String operator+(char lhs,const String& rhs)
{
String copy(lhs);
   return copy+rhs;
}

bool operator<=(const String lhs,const String& rhs)
{
   if(lhs<rhs)	
      return true;
   if(lhs==rhs)
      return true;
return false;
}




bool operator<(const char rhs[],const String& lhs)
{
String check(rhs);
   return check<lhs;
}


bool operator<(char lhs,const String& rhs)
{
   String check(lhs);
   return check<rhs;

}
char String::operator[] (int get)const
{
   assert(get<Capacity&&get>=0);
    return str[get];
   
}

char& String::operator[](int index)
{
   assert(index<Capacity&&index>=0);
      return str[index];
}

std::ostream& operator<<(std::ostream& out,const  String& rhs)
{
   for(int i=0;i<rhs.capacity();++i)
   {  if(rhs[i]==0)
	break;
      out<<rhs[i];	


   }
 return out;
}
std::istream& operator>>(std::istream& in , String& rhs)
{  
   rhs="";
   char Rfile;
   if (!(in>>Rfile))
      return in;
   rhs=rhs+Rfile;
   while (in.get(Rfile)&&Rfile!='\n'&& Rfile!='\t'&& Rfile!=' ')
   {    rhs=rhs+Rfile;
   }
   return in;

}

std::vector<String> String::split(char input) const
{
std::vector <String> output;
int start=0;
int size=length();
for(int i=0;i<length();++i)
{
   if(str[i]==input)
   {
   output.push_back(substr(start,i));
   start=i+1;
   }
}
if(!(start>=length()))
   output.push_back(substr(start,size));

return output;
}

int strtonum(const String& in){
int final; 
int temp;
   for(int i= (in.length()-1); i >= 0; --i){
      temp =in[i]-'0';
      final=final+ temp*10^(in.length()-(i+1));
   }
return final;
}
