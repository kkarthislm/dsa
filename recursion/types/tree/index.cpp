#include <iostream>
#include <string>

using namespace std;

class TreeRecursion
{
public:
    void func(int x)
    {
        if (x > 0)
        {
            cout << x << endl;
            func(x - 1);
            func(x - 1);
        }
    }
};

int main()
{
    TreeRecursion *tree = new TreeRecursion();
    tree->func(3);
}