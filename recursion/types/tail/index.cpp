#include <iostream>
#include <string>

using namespace std;

class TailRecursion
{
public:
    void func(int x)
    {
        if (x == 0)
        {
            return;
        }
        cout << x << endl;
        func(x - 1);
    }
};

int main()
{
    TailRecursion *tail = new TailRecursion();
    tail->func(100);
}