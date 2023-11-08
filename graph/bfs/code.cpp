
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
      
      int r = heights.size(), c = heights[0].size();
      queue<pair<int,int>> q;
      vector<vector<int>> step = {{1,0},{-1,0},{0,1},{0,-1}};
      vector<vector<int>> cost(r,vector<int>(c,INT_MAX));
      
      q.push({0,0});
      cost[0][0] = 0;

      
      while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first, j = p.second;
        int e = cost[i][j];
        for(int k = 0; k < 4; k++){
          int ii = i+step[k][0], jj = j+step[k][1];
          if(ii < r && ii >= 0 && jj < c && jj > 0){
            int effort = abs(e-heights[ii][jj]);
            if(effort >= cost[ii][jj]) continue;
            q.push({ii,jj});
            cost[ii][jj] = effort;
          }
        }
      }
      return cost[r-1][c-1]; 
    }
};


int main()
{
    // incidence matrix
    vector<vector<int>> inc = {{1,2,3},{3,8,4},{5,3,5}};

    Solution s;
    int res = s.minimumEffortPath(inc);
    cout << "res:" << res << endl;
    
}