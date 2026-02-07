#include <bits/stdc++.h>
using namespace std;

void explainPQ()
{
    // MAXIMUM HEAP
    priority_queue<int> pq;
    pq.push(2);     //{2}
    pq.push(5);     //{5, 2}
    pq.emplace(10); //{10, 5, 2}
    pq.push(3);     //{10, 5, 3, 2}

    cout << pq.top() << endl; // 10

    pq.pop(); //{5, 3, 2}

    cout << pq.top(); // 5

    // MINIMUM HEAP
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(5);    //{5}
    pq1.push(8);    //{5, 8}
    pq1.push(3);    //{3, 5, 8}
    pq1.emplace(1); //{1, 3, 5, 8}

    cout << endl
         << pq1.top(); // 1
};

int main()
{
    explainPQ();
}