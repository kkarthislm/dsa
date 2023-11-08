#include <iostream>
#include <string>

using namespace std;

class IndirectRecursion
{
public:
    int func2(int x)
    {
        return func1(x+1);
    }

    int func1(int x)
    {
        if (x < 10)
        {
            cout << x << endl;
            x = func2(x + 1);
        }
        return x;
    }
};

int main()
{
    IndirectRecursion *indirect = new IndirectRecursion();
    indirect->func1(3);
}