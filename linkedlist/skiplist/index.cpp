#include<iostream>
#include<vector>

using namespace std;

#define MAX_LEVELS 4

class Skiplist {
public:
    class List{
    public:
        int data;
        vector<List*> levels;

        List(){}

        List(int num){
            data = num;
            levels.assign(MAX_LEVELS, nullptr);
        }

        List(int num, List *node, int l){
            data = num;
            levels[l] = node;
        }

        List(int num, List *node){
            data = num;
            levels.assign(MAX_LEVELS, node);
        }
    };
    
    List *list;
    
    Skiplist() {
        list = nullptr;
    }

    bool flip(){
        int r = rand();
        return (r & (r-1)) == 0 ? true : false; 
    }
    
    bool search(int target) {
        
    }
    
    void add(int num) {
        if(list == nullptr){
            list = new List(num);
        }else {
            if(list->data > num){
                list = new List(num ,list);
            }else{
                List *pre = list;
                List *next = nullptr;
                for(auto it : list->levels){
                    if(it == nullptr) {
                        continue;
                    }
                    for(auto it2 : it->levels){
                        if(it == nullptr){
                            continue;
                        }else{
                            if(it->data > num){
                                continue;
                            }
                            pre = it;
                        }
                    }
                }
                List *temp = new List(num, next);
                int i = MAX_LEVELS;
                for(auto it : pre->levels){
                    if(flip()){
                        pre->levels[--i] = temp;
                    }
                }
            }
        }
    }
    
    bool erase(int num) {
        
    }
};

int main(){

}