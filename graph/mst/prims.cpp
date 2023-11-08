#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int result = 0;
        int sz = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis;
        vis.assign(sz, false);
        for (int i = 1; i < sz; i++)
        {
            int cost = abs(points[i][0] - points[0][0]) + abs(points[i][1] - points[0][1]);
            pq.push({cost, 0});
        }
        int selEdges = 0;
        while (!pq.empty() && selEdges < sz - 1)
        {
            pair<int, int> n = pq.top();
            pq.pop();
            if (vis[n.second])
                continue;
            result += n.first;
            selEdges++;
            vis[n.second] = true;

            for (int i = 0; i < sz; i++)
            {
                if (vis[i])
                    continue;
                for (int j = 0; j < sz; j++)
                {
                    if (vis[j] || i == j)
                        continue;
                    int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    pq.push({cost, i});
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> g = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    s.minCostConnectPoints(g);
    return 0;
}