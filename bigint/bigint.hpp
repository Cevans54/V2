#ifndef bigint_HPP
#define bigint_HPP
#include<iostream>
int const CAP = 100;
class bigint {
public:
  //A default constructor to initialize a bigint to zero.
  bigint();

  //A constructor to initialize a bigint to an int value you provide [0, maxint]. Example: bigint(128).
  bigint(int);

  //A constructor to initialize a bigint to a char[] you provide. You can assume what is provided is a
  //valid bigint. Example: bigint("299793").
  bigint(const char[]);

  //Overload output operator<<() as a friend function, so that takes a stream and bigint as input and
  //writes the bigint to the stream. It should print at most 50 digits per line.
  friend std::ostream& operator<<(std::ostream&,const bigint&);

  //Overload operator==() to compare if two bigints are equal.
  //It should return a bool - true if equal and false otherwise.
  bool operator==(const bigint&)const;

  //adds one big int to another bigint
  bigint operator +(const bigint &)const;

  //makes it so the number[x] works as bigint.number[x]
  int operator[](int)const;

  //makes it so the number[x]=i works as bigint.number[x]=i
  int& operator[](int);
private:
  int number[CAP];
};

std::istream& operator>>(std::istream&,bigint&);



#endif
