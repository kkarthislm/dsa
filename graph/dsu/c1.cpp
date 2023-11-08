#include <vector>
#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class AccountsManager
{
public:
    // email and index
    unordered_map<string, int> m1;

    // email and index:name
    unordered_map<string, pair<int, string>> m2;

    // index and email
    vector<string> emails;
};

class Solution
{

    // store the root
    vector<int> r;

    // store the root size
    vector<int> sz;

    // store the num of roots
    int numOfRoots;

    // return the root
    int find(int n)
    {
        return r[n] == n ? n : r[n] = find(r[n]);
    }

    // unify
    void make_union(int i, int j)
    {
        int x = find(i);
        int y = find(j);

        if (x != y)
        {
            if (sz[x] > sz[y])
                swap(x, y);
            r[x] = y;
            sz[y] += sz[x];
            numOfRoots--;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        AccountsManager mangr;
        numOfRoots = 0;
        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mangr.m1.count(accounts[i][j]) == 0)
                {
                    mangr.m1.insert({accounts[i][j], numOfRoots});
                    mangr.m2.insert({accounts[i][j], {i, accounts[i][j]}});
                    mangr.emails.push_back(accounts[i][j]);
                    numOfRoots++;
                }
            }
        }
        sz.assign(numOfRoots, 1);
        r.assign(numOfRoots, 0);
        for (int i = 0; i < numOfRoots; i++)
            r[i] = i;
        for (int i = 0; i < accounts.size() && accounts[i].size() > 2; i++)
        {
            for (int j = 2; j < accounts[i].size(); j++)
            {
                make_union(mangr.m1[accounts[i][j - 1]], mangr.m1[accounts[i][j]]);
            }
        }

        vector<bool> visited;
        visited.assign(numOfRoots, false);
        vector<vector<string>> result;
        
        for (int j = 0; j < r.size(); j++)
            find(j);
        for (int l = 0; l < accounts.size(); l++)
        {
            vector<string> v1;
            set<string> s1;
            int r1 = find(mangr.m1.at(accounts[l][1]));
            if (visited[r1] == false)
            {
                for (int j = 0; j < r.size(); j++)
                {
                    if (r[j] == r1)
                    {
                        s1.insert(mangr.emails.at(j));
                    }
                }
                v1.push_back(accounts[l][0]);
                for (auto &it : s1)
                    v1.push_back(it);
                result.push_back(v1);
                visited[r1] = true;
            }
        }
        return result;
    }
};

// class DSU
// {
// private:
//     // store root nodes
//     vector<int> root;

//     // store size of a group/root
//     vector<int> rootSize;

//     // store roots count
//     int numOfRoots;

//     // store size of this set
//     int size;

// public:
//     // initialize for n nodes
//     void init(int n)
//     {
//         root.resize(n);
//         rootSize.resize(n);
//         size = numOfRoots = n;
//         for (int i = 0; i < n; i++)
//         {
//             root
//             {i] = i;
//                 rootSize[i] = 1;
//             }
//         }
//     }

//     // find the root
//     int find(int node)
//     {
//         int t = node;
//         while (node != root[node])
//         {
//             node = root[node];
//         }

//         // path compression
//         while (root[t] != node)
//         {
//             int up = root[t];
//             root[t] = root[node];
//             t = up;
//         }

//         return root[node];
//     }

//     // group two nodes
//     void make_union(int node1, int node2)
//     {
//         int rootOfN1 = find(node1);
//         int rootOfN2 = find(node2);
//         if (rootOfN1 != rootOfN2)
//         {
//             if (rootSize[rootOfN1] < rootSize[rootOfN2])
//             {
//                 rootSize[rootOfN2] += rootSize[rootOfN1];
//                 root[node1] = rootOfN2;
//             }
//             else
//             {
//                 rootSize[rootOfN1] += rootSize[rootOfN2];
//                 root[node2] = rootOfN1;
//             }
//             numOfRoots--;
//         }
//     }

//     int getNumOfRoots()
//     {
//         return numOfRoots;
//     }

//     int removeStones(vector<vector<int>> &stones)
//     {
//         init(stones.size());
//         for (int i = 0; i < stones.size(); i++)
//         {
//             make_union(stones[i][0], stones[i][1]);
//         }
//         return 1 + numOfRoots;
//     }

//     int makeConnected(int n, vector<vector<int>> &cons)
//     {
//         init(n);
//         int extra_links = 0;
//         for (int i = 0; i < cons.size(); i++)
//         {
//             if (find(cons[i][0]) == find(cons[i][1]))
//             {
//                 extra_links++;
//             }
//             else
//             {
//                 make_union(cons[i][0], cons[i][1]);
//             }
//         }
//         int rem = numOfRoots - 1;

//         return rem == 0 || rem <= extra_links ? extra_links : -1;
//     }
// }

class Solution
{
public:
    // store the root
    vector<int> r;

    // store the root size
    vector<int> sz;

    // store the num of roots
    int numOfRoots;

    // return the root
    int find(int n)
    {
        return r[n] == n ? n : r[n] = find(r[n]);
    }

    // unify
    void make_union(int i, int j)
    {
        int x = find(i);
        int y = find(j);

        if (x != y)
        {
            if (sz[x] > sz[y])
                swap(x, y);
            r[x] = y;
            sz[y] += sz[x];
            numOfRoots--;
        }
    }

    bool equationsPossible(vector<string> &eqs)
    {
        int size = 26;
        numOfRoots = size;
        sz.assign(size, 1);
        r.assign(size, 0);
        for (int i = 0; i < size; i++)
            r[i] = i;

        for (int i = 0; i < eqs.size(); i++)
        {
            if (eqs[i][1] == '=' && eqs[i][2] == '=')
            {
                make_union(((int)eqs[i][0]) - 97, ((int)eqs[i][3]) - 97);
            }
        }

        for (int i = 0; i < eqs.size(); i++)
        {
            if (eqs[i][1] == '!' && eqs[i][2] == '=')
            {
                if (find(((int)eqs[i][0]) - 97) == find(((int)eqs[i][3]) - 97))
                {
                    return false;
                }
            }
        }

        return true;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>> &acs)
    {

        vector<vector<string>> result;

        unordered_map<string, int> m;
        unordered_map<int, pair<string, string>> m1;
        int count = 0;
        for (int i = 0; i < acs.size(); i++)
        {
            for (int j = 1; j < acs[i].size(); j++)
            {
                if (m.count(acs[i][j]) == 0)
                {
                    m.insert({acs[i][j], count});
                    m1.insert({count, {acs[i][0], acs[i][j]}});
                    count++;
                }
            }
        }
        numOfRoots = m.size();
        sz.assign(numOfRoots, 1);
        r.assign(numOfRoots, 0);
        for (int i = 0; i < numOfRoots; i++)
            r[i] = i;
        for (int i = 0; i < acs.size() && acs[i].size() > 2; i++)
        {
            for (int j = 2; j < acs[i].size(); j++)
            {
                make_union(m[acs[i][j - 1]], m[acs[i][j]]);
            }
        }

        set<int> visited;
        for (int i = 0; i < acs.size(); i++)
        {
            vector<string> v1;
            set<string> s1;
            int r1 = find(m.at(acs[i][1]));
            if (visited.count(r1) == 0)
            {
                for (int j = 0; j < r.size(); j++)
                {
                    if (r[j] == r1)
                    {
                        s1.insert(m1.at(j).second);
                    }
                }
                v1.push_back(acs[i][0]);
                for (auto &it : s1)
                    v1.push_back(it);
                result.push_back(v1);
                visited.insert(r1);
            }
        }
        return result;
    }
};

int main()
{
    // Solution s;
    // vector<vector<int>> graph ({{1,2},{2,3},{3,4},{1,4},{1,5}});
    // s.findRedundantConnection(graph);

    // DSU d;
    // vector<vector<int>> graph({{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}});
    // d.init(6);
    // d.removeStones(graph);

    // vector<vector<int>> graph({{1, 4}, {0, 3}, {1, 3}, {3, 7}, {2, 7}, {0, 1}, {2, 4}, {3, 6}, {5, 6}, {6, 7}, {4, 7}, {0, 7}, {5, 7}});
    // d.init(11);
    // d.makeConnected(11, graph);

    Solution s;
    // vector<string> graph({"a==b","b!=a"});

    // bool res = s.equationsPossible(graph);
    // cout<<res<<endl;
    vector<vector<string>> graph({{"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe1@m.co"},
                                  {"Kevin", "Kevin3@m.co", "Kevin5@m.co", "Kevin0@m.co"},
                                  {"Ethan", "Ethan5@m.co", "Ethan4@m.co", "Ethan0@m.co"},
                                  {"Hanzo", "Hanzo3@m.co", "Hanzo1@m.co", "Hanzo0@m.co"},
                                  {"Fern", "Fern5@m.co", "Fern1@m.co", "Fern0@m.co"}});

    graph = {{"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"John", "johnsmith@mail.com", "john00@mail.com"}, {"Mary", "mary@mail.com"}, {"John", "johnnybravo@mail.com"}};
    graph = {
    // {"David","David0@m.co","David5@m.co","David0@m.co"},
    // {"Fern","Fern5@m.co","Fern2@m.co","Fern6@m.co"},
    // {"Gabe","Gabe0@m.co","Gabe6@m.co","Gabe8@m.co"},
    // {"John","John4@m.co","John2@m.co","John0@m.co"},
    // {"Lily","Lily4@m.co","Lily2@m.co","Lily0@m.co"},
    // {"Lily","Lily4@m.co","Lily6@m.co","Lily7@m.co"},
    {"Alex","Alex7@m.co","Alex5@m.co","Alex7@m.co"},
    {"Alex","Alex0@m.co","Alex4@m.co","Alex5@m.co"}
    };
    // s.accountsMerge(graph);

    return 0;
};



class Solution {
    int size; // size of the set
    int us; // number of unique sets
    vector<int> p; // maintain parent log 
    vector<int> path; // path size log

public:

    int find(int x){
        return x == p[x] ? x : find(p[x]);
    }

    void make_union(int x, int y){
        x = find(x); 
        y = find(y);
        if(x != y){
            if(path[x] < path[y]) swap(x,y);
            p[x] = y;
            path[y] += path[x];
            us--;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        size = us = isConnected.size();
        p.assign(size,0);
        path.assign(size,1);
        for(int i = 0; i < size; i++){
            p[i] = i;
        }
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(isConnected[i][j] == 1) make_union(i,j);
            }
        }

        return us;
    }
};