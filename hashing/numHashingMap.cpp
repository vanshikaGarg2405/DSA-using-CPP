#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[n];
    map<int, int> mpp;
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]] += 1;
    }

    // for (auto it : mpp) {
    //     cout << it.first << " -> " << it.second << endl;
    // }

    int q;
    cout << "Enet q: ";
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << " ";
    }
    return 0;
}