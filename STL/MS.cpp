#include <bits/stdc++.h>
using namespace std;

void explainMultiSet()
{
    multiset<int> ms;
    ms.insert(3);
    ms.insert(2);
    ms.insert(4);
    ms.insert(1);
    ms.insert(3);

    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        cout << *(it) << " ";
    }

    int cnt = ms.count(3);
    cout << endl
         << cnt << endl;

    ms.erase(ms.find(3));

    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        cout << *(it) << " ";
    }
};

int main()
{
    explainMultiSet();
}
