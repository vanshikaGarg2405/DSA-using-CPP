#include <bits/stdc++.h>
using namespace std;

void explainVectors()
{
    vector<int> v;      //{}
    v.push_back(5);     //{5}
    v.emplace_back(10); //{5, 10}
    v.push_back(2);     //{5, 10, 2}
    v.emplace_back(6);  //{5, 10, 2, 6}
    // cout << v[0] << " " << v[1] << endl;

    vector<pair<int, int>> vec;
    vec.push_back({2, 3});  //{{2, 3}}
    vec.emplace_back(4, 8); //{{2, 3}, {4, 8}}

    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << endl;
    cout << v.back() << endl;

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    // v - 5, 10, 2, 6
    v.erase(v.begin() + 1); //{5, 2, 6}

    v.erase(v.begin() + 1, v.begin() + 2); //{5, 6}
    cout << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl;
    vector<int> vec1(3, 100);             // {100, 100, 100}
    vec1.insert(vec1.begin(), 300);       //{300, 100, 100, 100}
    vec1.insert(vec1.begin() + 1, 2, 50); //{300, 50, 50, 100, 100, 100}

    vector<int> copy(3, 10);                                       //{10, 10, 10}
    vec1.insert(vec1.begin() + 2, copy.begin(), copy.begin() + 2); //{300, 50, 10, 10, 50, 100, 100, 100}

    vec1.pop_back();

    for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl
         << vec1.size() << endl; // 7

    v.swap(vec1);
    // v - {300, 50, 10, 10, 50, 100, 100}
    // vec1 - {5, 6}
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl;

    for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++)
    {
        cout << *(it) << " ";
    }

    v.clear();
    cout << endl
         << v.empty();
};

int main()
{
    explainVectors();
}