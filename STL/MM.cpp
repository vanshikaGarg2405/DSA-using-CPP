#include <bits/stdc++.h>
using namespace std;

void explainMultiMap()
{
    multimap<int, pair<int, int>> mpp;
    mpp.insert({1, {2, 3}});
    mpp.insert({4, {1, 2}});
    mpp.insert({2, {4, 6}});
    mpp.insert({3, {3, 8}});
    mpp.insert({2, {1, 4}});

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    }
}

int main()
{
    explainMultiMap();
}