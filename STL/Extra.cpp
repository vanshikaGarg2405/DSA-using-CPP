#include <bits/stdc++.h>
using namespace std;

void explainExtra()
{
    // Sorting
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);
    v.push_back(2);
    v.push_back(10);
    v.push_back(6);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }

    // sort(v.begin(), v.end());

    // cout << endl;
    // for (auto it = v.begin(); it != v.end(); it++)
    //{
    //     cout << *(it) << " ";
    // }

    sort(v.begin() + 2, v.begin() + 5);
    cout << endl;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;

    // they are same
    if (p1.first > p1.second)
        return true;
    return false;
}

void SortingMyWay()
{
    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};

    // sort it according to second element
    // if second element is same, then sort
    // it according to first element in descending

    sort(a, a + 3, comp);
    for (int i = 0; i < 3; i++)
    {
        cout << "{" << a[i].first << ", " << a[i].second << "}" << " ";
    }
}

void CountSetBits()
{
    int num = 7;
    int cnt = __builtin_popcount(num);
    cout << cnt;

    long long num1 = 2937481982185698;
    int cnt1 = __builtin_popcountll(num1);
    cout << endl
         << cnt1;
}

void permutations() {
    string s = "213";

    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}

void maxMinElement() {
    int a[] = {2, 3, 19, 3, 20};
    int max = *max_element(a, a + 5);
    int min = *min_element(a, a + 5);
    cout << max << endl << min;
}

int main()
{
    explainExtra();
    cout << endl;
    SortingMyWay();
    cout << endl;
    CountSetBits();
    cout << endl;
    permutations();
    maxMinElement();
}