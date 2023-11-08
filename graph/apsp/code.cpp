#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            dis[i][i] = 0;
        }
        
        for (int i = 0; i < edges.size(); i++)
        {
            dis[edges[i][0]][edges[i][1]] = dis[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (dis[j][i] != INT_MAX && dis[i][k] != INT_MAX && dis[j][k] > dis[j][i] + dis[i][k])
                    {
                        dis[j][k] = dis[j][i] + dis[i][k];
                    }
                }
            }
        }
        int res = -1, min_cnt = n;
        for (int i = 0; i < dis.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < dis[i].size(); j++)
            {
                if (dis[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            if (min_cnt >= count)
            {
                min_cnt = count;
                res = i;
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> g = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    Solution s;
    s.findTheCity(5, g, 2);
    return 0;
}