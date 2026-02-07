#include <bits/stdc++.h>
using namespace std;

// Pairs
void explainPairs()
{
    pair<int, int> p = {1, 2};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {2, 4}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;

    pair<pair<int, int>, pair<int, int>> p2 = {{1, 2}, {4, 5}};
    cout << p2.first.first << " "
         << p2.second.first << " "
         << p2.first.second << " "
         << p2.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}};
    cout << arr[2].first << " " << arr[1].second;
}

int main()
{
    explainPairs();
}