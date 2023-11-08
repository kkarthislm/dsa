// adjacency matrix/list, incidence matrix
// queue

#include <iostream>
#include <vector>
#include <queue>

typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

using namespace std;

queue<int> q;

// with adjacency list
void bfs_list(vector<vector<int>> &adjList, vector<bool> &vis)
{
    q.push(adjList[0][0]);
    while (!q.empty())
    {
        int size;
        int n = q.front();
        q.pop();
        while (size > 0)
        {
            size--;
            if (vis[n])
                continue;
            vis[n] = true;
            for (int i = 0; i < adjList[n].size(); i++)
                q.push(adjList[n][i]);
        }
    }
}

// with adjacency matrix
void bfs_matrix(vector<vector<int>> &adjMat, vector<bool> &vis)
{

    q.push(adjMat[0][0]);
    while (!q.empty())
    {
        int size;
        int n = q.front();
        q.pop();
        while (size > 0)
        {
            size--;
            if (vis[n])
                continue;
            vis[n] = true;
            for (int i = 0; i < adjMat[n].size(); i++)
                if (adjMat[n][i] == 1)
                    q.push(adjMat[n][i]);
        }
    }
}

// with incidence matrix
void bfs_inc_matrix(vector<vector<int>> &adjMat, vector<bool> &vis)
{
    q.push(adjMat[0][0]);
    while (!q.empty())
    {
        int size;
        int n = q.front();
        q.pop();
        while (size > 0)
        {
            size--;
            if (vis[n])
                continue;
            vis[n] = true;
            for (int i = 0; i < adjMat[n].size(); i++)
                if (adjMat[n][i] == 1)
                    q.push(adjMat[n][i]);
        }
    }
}

int main()
{
    // nodes -> 0,1,2,3
    // edges -> 0-1, 0-2, 2-3, 1-3 (undirected)

    // adjacency list
    vvi adj = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    vb vis_adj;
    vis_adj.assign(adj.size(), false);
    bfs_list(adj, vis_adj);

    // adjacency matrix
    vvi mat = {{0, 1, 1, 0},
               {1, 0, 0, 1},
               {1, 0, 0, 1},
               {0, 1, 1, 0}};

    vb vis_mat;
    vis_mat.assign(mat.size(), false);
    bfs_matrix(mat, vis_mat);

    // incidence matrix
    vvi inc = {{1, 1, 0, 0},
               {1, 0, 0, 1},
               {0, 1, 1, 0},
               {0, 0, 1, 1}};
    vb vis_inc;
    vis_inc.assign(inc.size(), false);
    bfs_inc_matrix(inc, vis_inc);

    
}