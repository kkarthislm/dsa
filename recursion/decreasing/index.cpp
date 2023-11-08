#include<iostream>

using namespace std;

void func(int x){
    if(x == 0) return;

    func(--x);
    cout<<x<<endl;
}

int main(){
    func(4);
}