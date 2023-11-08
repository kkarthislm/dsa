// adjacency matrix/list incidence matrix
// recursion/stack

#include <iostream>
#include <vector>

typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

using namespace std;

// with adjacency list
void dfs_list(vector<vector<int>> &adjList, vector<bool> &vis, int n)
{
    if (vis[n])
        return;

    vis[n] = true;

    for (int i = 0; i < adjList[n].size(); i++)
        dfs_list(adjList, vis, adjList[n][i]);
}

// with adjacency matrix
void dfs_matrix(vector<vector<int>> &adjMat, vector<bool> &vis, int n)
{
    if (vis[n])
        return;

    vis[n] = true;

    for (int i = 0; i < adjMat[n].size(); i++)
        if (adjMat[n][i] == 1)
            dfs_matrix(adjMat, vis, adjMat[n][i]);
}

// with incidence matrix
void dfs_inc_matrix(vector<vector<int>> &adjMat, vector<bool> &vis, int n)
{
    if (vis[n])
        return;

    vis[n] = true;

    for (int i = 0; i < adjMat[n].size(); i++)
        if (adjMat[n][i] == 1)
            dfs_matrix(adjMat, vis, adjMat[n][i]);
}

int main()
{
    // nodes -> 0,1,2,3
    // edges -> 0-1, 0-2, 2-3, 1-3 (undirected)

    // adjacency list
    vvi adj = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    vb vis_adj;
    vis_adj.assign(adj.size(), false);
    for (int i = 0; i < adj.size(); i++)
    {
        dfs_list(adj, vis_adj, i);
    }

    // adjacency matrix
    vvi mat = {{0, 1, 1, 0},
               {1, 0, 0, 1},
               {1, 0, 0, 1},
               {0, 1, 1, 0}};

    vb vis_mat;
    vis_mat.assign(mat.size(), false);
    for (int i = 0; i < mat.size(); i++)
    {
        dfs_matrix(mat, vis_mat, i);
    }

    // incidence matrix
    vvi inc = {{1, 1, 0, 0},
               {1, 0, 0, 1},
               {0, 1, 1, 0},
               {0, 0, 1, 1}};
    vb vis_inc;
    vis_inc.assign(inc.size(), false);
    for (int i = 0; i < inc.size(); i++)
    {
        dfs_inc_matrix(inc, vis_inc, i);
    }
}