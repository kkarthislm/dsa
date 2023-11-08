#include <iostream>
#include <string>

using namespace std;

string decode()
{
    string s = "a2b3c4d5e6f7g8h9";
    int k = 10;
    string res = "";
    for (char c : s)
    {
        // aabaabaabc
        if (c <= 57 && c >= 50)
        {
            string r1 = res;
            int i = int(c) - 48;
            while (i > 1)
            {
                i--;
                res += r1;
                if (res.length() >= k)
                {
                    res.assign(1, res[k - 1]);
                    return res;
                }
            }
            res.erase()
        }
        else
        {
            res += c;
            if (res.length() >= k)
            {
                res.assign(1, res[k - 1]);
                return res;
            }
        }
        if (res.length() >= k)
        {
            res.assign(1, res[k - 1]);
            return res;
        }
    }
    res.assign(1, res[k - 1]);
    return res;
}

int main()
{
    cout << decode();
    return 0;
}