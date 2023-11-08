#include <iostream>
#include <string>

using namespace std;

class MyLinkedList {
public:
    class List{
    public:
        int data;
        List *next = nullptr;
        
        List(){}
        
        List(int val){data = val;}
        
        List(int val, List *node){
            data = val;
            next = node;
        }
    };
    
    List *linkedList;
    
    MyLinkedList() {
        linkedList = nullptr;
    }
    
    int get(int index) {
        List *temp = linkedList;
        while(index > 0 && temp != nullptr){
            temp = temp -> next;
            index--;
        }
        if(temp == nullptr) return -1;
        return temp -> data;
    }
    
    void addAtHead(int val) {
        linkedList = new List(val,linkedList);
    }
    
    void addAtTail(int val) {
        if(linkedList == nullptr){
            addAtHead(val);
        }else{
            List *temp = linkedList;
            while(temp -> next != nullptr){
                temp = temp -> next;
            }
            temp -> next = new List(val);   
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
        }else{
            List *temp = linkedList;
            List *pre;
            while(index > 0 && temp != nullptr){
                pre = temp;
                temp = temp -> next;
                index--;
            }
            List *t2 = temp;
            temp = new List(val, t2); 
            pre -> next = temp;      
        }
    }
    
    void deleteAtIndex(int index) {
        if(index == 0){
            linkedList = linkedList -> next;
        }else{
            List *temp = linkedList;
            List *pre;
            while(index > 0 && temp != nullptr){
                pre = temp;
                temp = temp -> next;
                index--;
            }
            if(temp != nullptr){
                temp = temp -> next;                
                pre -> next = temp;
            }
        }
    }
};

int main()
{

  MyLinkedList *obj = new MyLinkedList();
  obj->addAtHead(7);
  obj->addAtHead(2);
  obj->addAtHead(1);
  obj->addAtIndex(3,0);
  obj->deleteAtIndex(2);
  obj->addAtHead(6);
  obj->addAtTail(4);
  obj->get(4);
  obj->addAtHead(4);
  obj->addAtIndex(5,0);
  obj->addAtHead(6);

// ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead",
// "addAtTail","get","addAtHead","addAtIndex","addAtHead"]
// [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]


}
