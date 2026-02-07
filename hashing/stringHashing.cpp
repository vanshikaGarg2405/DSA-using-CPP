#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;

    // pre-compute
    int hashh[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hashh[s[i]] += 1;
    }

    int q;
    cout << "Enter q: ";
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // fetch
        cout << hashh[c] << " ";
    }
}