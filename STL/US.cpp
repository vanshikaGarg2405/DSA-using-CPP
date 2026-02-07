#include <bits/stdc++.h>
using namespace std;

void explainUnorderedSet()
{
    unordered_set<int> us;
    us.insert(3);
    us.insert(10);
    us.insert(4);
    us.emplace(3);
    us.insert(2);

    for (auto it = us.begin(); it != us.end(); it++)
    {
        cout << *(it) << " ";
    }
};

int main()
{
    explainUnorderedSet();
}