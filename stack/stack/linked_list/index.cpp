// stack last in first out
// ops -> push, pop, top, isEmpty

#include<iostream>
using namespace std;

template <class T>
class Stack{
    template <class U>
    class List{
    public:
        T data;
        List *next = nullptr;

        List(T val, List *node){
            data = val;
            next = node;
        }    
    };
    List<T> *list = nullptr;
  public:
    Stack();
    void push(T val);
    T top();
    void pop();
    bool isEmpty();
};

template <class T>
Stack<T>::Stack(){
    list = nullptr;
}

template <class T>
void Stack<T>::push(T val){
    list = new List(val, list);
}

template <class T>
T Stack<T>::top(){
    return list -> data;
}

template <class T>
void Stack<T>::pop(){
    list = list -> next;
}

template <class T>
bool Stack<T>::isEmpty(){
    return list == nullptr;
}

int main(){

};
