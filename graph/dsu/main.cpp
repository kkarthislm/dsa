/*
 * make disjoint set
 * keys -> find, union, path compression (find), union by size/rank (union)
 */

#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class DSU
{
private:
    // store root nodes
    vector<int> root;

    // store size of a group/root
    vector<int> rootSize;

    // store roots count
    int numOfRoots;

    // store size of this set
    int size;

public:
    // initialize for n nodes
    void init(int n)
    {
        root.resize(n);
        rootSize.resize(n);
        rootSize.assign(n, 1);
        size = numOfRoots = n;
        for (int i = 0; i < n; i++)
        {
            root[i] = i;
        }
    }

    // find the root
    int find(int node)
    {
        return root[node] == node ? node : node = find(root[node]);
    }

    // group two nodes
    void make_union(int node1, int node2)
    {
        node1 = find(node1);
        node1 = find(node2);
        if (node1 != node2)
        {
            if (rootSize[node1] < rootSize[node2]) swap(node1, node2);
            root[node2] = node1;
            rootSize[node2] += rootSize[node1];
            numOfRoots--;
        }
    }

    int getNumOfRoots()
    {
        return numOfRoots;
    }
};

int main(){
    // DSU s;
    // vector<vector<int>> graph ({{1,2},{2,3},{3,4},{1,4},{1,5}});
    // s.findRedundantConnection(graph);
};