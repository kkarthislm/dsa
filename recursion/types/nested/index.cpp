#include <iostream>
#include <string>

using namespace std;

class NestedRecursion
{
public:
    int func(int x)
    {
        if (x > 0)
        {
            cout << x << endl;
            func(func(x - 1));
        }
        return x;
    }
};

int main()
{
    NestedRecursion *nested = new NestedRecursion();
    nested->func(3);
}