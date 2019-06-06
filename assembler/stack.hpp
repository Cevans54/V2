#ifndef STACK_HPP
#define STACK_HPP
#include<new>
#include <cassert>
template <typename T>
class node{

public:
  T data;
  node<T>*next;

  node():next(0){};
  node(const T& x):data(x),next(0){};
};




template<typename T>
class stack{
public:

  stack():tos(0){};

  stack(const stack<T>& actual){
    node<T> * temp =actual.tos;
    node<T>*bottom=0;
    tos = 0;
    while(temp!=0){
      if (tos==0){
	tos= new node<T>(temp->data);
        bottom = tos;
     }
      else{
	bottom->next= new node<T>(temp->data);
        bottom = bottom->next;
      }
      temp= temp ->next;
   }
}

~stack()
  {
    node<T> *temp;
    while(tos!=0){
      temp =tos;
      tos=tos->next;
      delete temp;
    }
  }

void swap(stack<T>& rhs){
 node<T> *temp=tos;
  tos=rhs.tos;
  rhs.tos = temp;
}
stack<T> operator=(stack<T>& rhs)
  {
    if(tos==rhs.tos)return *this;
 
    node<T> *temp;
    while(tos!=0){
      temp =tos;
      tos=tos->next;
      delete temp;
    }
    temp=rhs.tos;
    node<T>*bottom=0;
    tos = 0;
    while(temp!=0){

      if (tos==0){
        tos= new node<T>(temp->data);
        bottom = tos;}
      else{
        bottom->next= new node<T>(temp->data);
        bottom = temp->next;
       }
      temp= temp ->next;
    }
    return *this;  
}

bool isEmpty()const{return tos ==0;}

T pop()
  {
    assert(tos!=0);
    //take the result form the top of stack to be retruned
    T result = tos ->data;
    //creates a node pointer pointing at the node at the top of the stack
    node<T> *temp= tos;
    //pointing top of stack at the  futer down on the stack
    tos=tos->next;
    //useing temp to destroy the previos top of stack
    delete temp;
    //then retruns restults
    return result;     
  }
  void push(const T& x){
    //first you create a new node to be place on top of the stack using the input 
    node<T> *temp = new node <T>(x);
    //point the top of stak pointer at the top of stack
    temp->next = tos;
    //take address of tos ponts it at the temp
    tos=temp;
  }
  T top(){return tos -> data;}
  bool isfull(){
    node<T>temp=new(std::nothrow)node<T>;
    if(!temp) return true;
    else return false;
}

private:
  node<T> *tos;
};

#endif


















































