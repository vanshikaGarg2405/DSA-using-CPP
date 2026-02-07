#include <bits/stdc++.h>
using namespace std;

void explainLists()
{
    list<int> ls;
    ls.push_back(2);      //{2}
    ls.push_front(5);     //{5, 2}
    ls.emplace_front(10); //{10, 5, 2}
    ls.emplace_back(3);   //{10, 5, 2, 3}

    for (list<int>::iterator it = ls.begin(); it != ls.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl
         << ls.back(); // 3
    cout << endl
         << ls.front(); // 3

    ls.pop_front();    //{5, 2, 3}
    ls.push_front(20); //{20, 5, 2, 3}
    ls.pop_back();     //{20, 5, 2}

    cout << endl;
    for (auto it = ls.begin(); it != ls.end(); it++)
    {
        cout << *(it) << " ";
    }
};

int main()
{
    explainLists();
}