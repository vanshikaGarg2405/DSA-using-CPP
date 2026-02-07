#include <bits/stdc++.h>
using namespace std;

void explainDeque()
{
    deque<string> dq;
    dq.push_back("vanshika");
    dq.emplace_front("kanika");
    dq.push_front("mummy");
    dq.emplace_back("papa");
    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *(it) << " ";
    }
};

int main()
{
    explainDeque();
}