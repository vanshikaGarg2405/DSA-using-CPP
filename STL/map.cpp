#include <bits/stdc++.h>
using namespace std;

void explainMap()
{
    map<int, int> m;

    m[1] = 2;
    m.insert({4, 1});
    m.insert({3, 2});
    m.insert({5, 3});

    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << m[1] << endl;
    cout << m[4] << endl;
};

int main()
{
    explainMap();
}