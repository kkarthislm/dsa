#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int> q;
    priority_queue<pair<int, int>> qpair;
    priority_queue<int, vector<int>, greater<int>> minq;

    priority_queue<pair<int, pair<int, int>>> pqpair;

    for (int i = 0; i < 10; i++)
    {
        // q.push(i);
        // minq.push(i);
        // qpair.push({i, i + 1});
        pqpair.push({i%2, {i + 1, i + 2}});
    }
    for (int i = 0; i < 10; i++)
    {
        // cout << q.top() << endl;
        // cout << minq.top() << endl;
        // cout << qpair.top().first << "," << qpair.top().second << endl;
        // q.pop();
        // minq.pop();
        // qpair.pop();
        cout << pqpair.top().first << "," << pqpair.top().second.first << "," << pqpair.top().second.second << endl;
        pqpair.pop();
    }

    return 0;
}