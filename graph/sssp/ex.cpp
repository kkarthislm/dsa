#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {

        // bellman-ford
        vector<vector<int>> dis;
        dis.assign(n, {});
        dis[src].assign(k + 1, 0);

        unordered_map<int, vector<pair<int, int>>> hm;
        for (int i = 0; i < flights.size(); i++)
        {
            hm[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        int s = 0;
        while (s < n - 1)
        {
            s++;
            for (int i = src; i < n; i++)
            {
                vector<pair<int, int>> adj = hm[i];
                for (int j = 0; j < adj.size(); j++)
                {
                    pair<int, int> eg = adj[j];
                    dis[eg.first].push_back(dis[i][dis[i].size() - 1] + eg.second);
                }
            }
        }

        int res = INT_MAX, j = 0;
        for (int i = 0; i < dis[dst].size(); i++)
        {
            if (j > k)
                break;
            j++;
            res = min(res, dis[dst][i]);
        }

        return res == INT_MAX ? -1 : res;
    }
};

int main()
{
    vector<vector<int>> g = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    Solution s;
    s.findCheapestPrice(4, g, 0, 3, 1);
    return 0;
}