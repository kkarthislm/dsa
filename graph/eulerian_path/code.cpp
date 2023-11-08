#include <iostream>
#include <vector>
#include <limits.h>
#include <map>
#include <set>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        map<string, set<string>> hm;
        for (int i = 0; i < tickets.size(); i++)
        {
            hm[tickets[i][0]].insert(tickets[i][1]);
        }
        vector<string> result;

        stack<string> stk;
        // stk.push(hm.rbegin()->first);
        stk.push("JFK");

        while (!stk.empty())
        {
            string s = stk.top();
            if (hm[s].size())
            {
                auto t = hm[s].begin();
                stk.push(*t);
                hm[s].erase(t);
            }else{
                result.push_back(s);
                stk.pop();
            }
        }

        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << endl;
        }
    }
};

int main()
{
    vector<vector<string>> g = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    Solution s;
    s.findItinerary(g);
    return 0;
}
