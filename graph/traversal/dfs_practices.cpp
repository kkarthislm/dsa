#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    int rows, cols;
    void dfs(vector<vector<int>> &A, int i, int j)
    {
        if (i < 0 || j < 0 || i >= rows || j >= cols)
            return;

        if (A[i][j] != 1)
            return;

        A[i][j] = -1;
        dfs(A, i + 1, j);
        dfs(A, i - 1, j);
        dfs(A, i, j + 1);
        dfs(A, i, j - 1);
    }

public:
    int numEnclaves(vector<vector<int>> &A)
    {

        if (A.empty())
            return 0;

        rows = A.size();
        cols = A[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1)
                    dfs(A, i, j);
            }
        }

        int ans = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (A[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};

class Solution1
{
    //     int r, c;
    //     bool re;
    //     vector<vector<bool>> vis;

    // public:
    //     void dfs(int i, int j, vector<vector<int>> &grid)
    //     {
    //         cout << i << "," << j << endl;
    //         if (i < 0 || j < 0 || i >= r || j >= c)
    //         {
    //             re = false;
    //             return;
    //         }
    //         if (vis[i][j])
    //             return;
    //         vis[i][j] = true;
    //         if (grid[i][j] == 1)
    //         {
    //             if(re) re = true;
    //             return;
    //         };
    //         if (grid[i][j] == 0)
    //             grid[i][j] = -1;
    //         dfs(i + 1, j, grid);
    //         dfs(i - 1, j, grid);
    //         dfs(i, j + 1, grid);
    //         dfs(i, j - 1, grid);
    //     }
    //     int closedIsland(vector<vector<int>> &grid)
    //     {
    //         int result = 0;
    //         r = grid.size(), c = grid[0].size();
    //         vis.assign(r, vector<bool>(c, false));
    //         for (int i = 1; i < r - 1; i++)
    //         {
    //             for (int j = 1; j < c - 1; j++)
    //             {
    //                 if (grid[i][j] == 0)
    //                 {
    //                     re = true;
    //                     dfs(i, j, grid);
    //                     if (re)
    //                         result++;
    //                     re = false;
    //                 }
    //             }
    //         }
    //         return result;
    //     }

    //     int n, fill;
    //     vector<vector<bool>> vis;

    // public:
    //     void dfs(int i, int j, vector<vector<int>> &image)
    //     {
    //         cout << i << "," << j << endl;
    //         if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size())
    //         {
    //             return;
    //         }
    //         if(vis[i][j]) return;
    //         vis[i][j] = true;
    //         if (image[i][j] == n)
    //             image[i][j] = fill;
    //         if (i + 1 < image.size())
    //             dfs(i + 1, j, image);
    //         if (i - 1 >= 0)
    //             dfs(i - 1, j, image);
    //         if (j + 1 < image[0].size())
    //             dfs(i, j + 1, image);
    //         if (j - 1 >= 0)
    //             dfs(i, j - 1, image);
    //     }
    //     vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    //     {
    //         vis.assign(image.size(),vector<bool>(image[0].size(), false));
    //         n = image[sr][sc];
    //         fill = color;
    //         dfs(sr, sc, image);
    //         return image;
    //     }

    // int r,c, t = 0;
    //     vector<vector<bool>> vis;

    // public:
    //     void dfs(int i, int j, vector<vector<int>>& grid){
    //         if(i < 0 || j < 0 || i >= r || j >= c) return;
    //         if(vis[i][j]) return;
    //         vis[i][j] = true;

    //         if (grid[i][j] == 1){
    //             grid[i][j] = -1;
    //             t++;
    //         }else return;
    //         dfs(i+1,j,grid);
    //         dfs(i-1,j,grid);
    //         dfs(i,j+1,grid);
    //         dfs(i,j-1,grid);
    //     }
    //     int maxAreaOfIsland(vector<vector<int>>& grid) {
    //         int result = 0;
    //         r = grid.size(), c = grid[0].size();
    //         vis.assign(r,vector<bool>(c,false));
    //         for(int i = 0; i < r; i++){
    //             for(int j = 0; j < c; j++){
    //                 if(grid[i][j] == 1){
    //                     t = 0;
    //                     dfs(i, j, grid);
    //                     result = max(result,t);
    //                 }
    //             }
    //         }
    //         return result;
    //     }

    vector<bool> vis;

public:
    void dfs(int i, vector<vector<int>> &rooms)
    {
        vis[i] = true;
        for (int j = 0; j < rooms[i].size(); j++)
        {
            if (!vis[rooms[i][j]])
                dfs(rooms[i][j], rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vis.assign(rooms.size(), false);
        dfs(0, rooms);
        for (int i = 0; i < vis.size(); i++)
        {
            if (!vis[i])
                return false;
        }
        return true;
    }
};

int main()
{

    // Solution s;
    // vector<vector<int>> g = {{0,0,0},{0,1,0},{0,0,0}};
    // s.numEnclaves(g);

    Solution1 s;
    // vector<vector<int>> g = {
    //     {1, 1, 1},
    //     {1, 1, 0},
    //     {1, 0, 1}
    // };
    // s.floodFill(g,1,1,2);

    // vector<vector<int>> g = {
    //     {0,0,1,0,0,0,0,1,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,1,1,1,0,0,0},
    //     {0,1,1,0,1,0,0,0,0,0,0,0,0},
    //     {0,1,0,0,1,1,0,0,1,0,1,0,0},
    //     {0,1,0,0,1,1,0,0,1,1,1,0,0},
    //     {0,0,0,0,0,0,0,0,0,0,1,0,0},
    //     {0,0,0,0,0,0,0,1,1,1,0,0,0},
    //     {0,0,0,0,0,0,0,1,1,0,0,0,0}
    // };

    // s.maxAreaOfIsland(g);

    vector<vector<int>> g = {
        {1}, {2}, {3}, {}};
    s.canVisitAllRooms(g);

    return 0;
}