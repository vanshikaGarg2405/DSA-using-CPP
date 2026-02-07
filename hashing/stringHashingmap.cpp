#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter s: ";
    cin >> s;

    // precompute
    unordered_map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]] += 1;
    }

    int q;
    cout << "Enter q: ";
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // fetch
        cout << mpp[c] << " ";
    }
    return 0;
}