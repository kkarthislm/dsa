#include <iostream>
#include <string>

using namespace std;

class HeadRecursion
{
public:
    void func(int x)
    {
        if (x > 0)
        {
            func(x-1);
        }
        cout << x << endl;
    }
};

int main()
{
    HeadRecursion *head = new HeadRecursion();
    head->func(100);

}