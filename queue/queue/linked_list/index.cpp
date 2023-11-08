// Queue first in first out
// ops -> push, front, peek, isEmpty

#include<iostream>
using namespace std;

template <class T>
class Queue{
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
    List<T> *tail = nullptr;
  public:
    Queue();
    void push(T val);
    T peek();
    void front();
    bool isEmpty();
};

template <class T>
Queue<T>::Queue(){
    list = nullptr;
    tail = nullptr;
}

template <class T>
void Queue<T>::push(T val){
    if(tail == nullptr){
        list = tail = new List(val, nullptr);
    }else{
        tail -> next = new List(val, nullptr);
        tail = tail -> next;
    }
}

template <class T>
T Queue<T>::peek(){
    return list -> data;
}

template <class T>
void Queue<T>::front(){
    list = list -> next;
}

template <class T>
bool Queue<T>::isEmpty(){
    return list == nullptr;
}

int main(){

};
