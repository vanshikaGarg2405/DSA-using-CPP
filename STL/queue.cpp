#include <bits/stdc++.h>
using namespace std;

void explainQueue()
{
    queue<int> q;
    q.push(1);    //{1}
    q.push(3);    //{1, 3}
    q.emplace(5); //{1, 3, 5}

    q.back() += 6; // 5 becomes 5 + 6 = 11

    cout << q.back() << endl; // 11

    q.pop(); //{3, 11}

    cout << q.front(); // 3
};

int main()
{
    explainQueue();
}