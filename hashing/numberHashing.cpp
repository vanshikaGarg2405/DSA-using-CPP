#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // precompute
    int hashh[100000] = {0};
    for (int i = 0; i < n; i++) {
        hashh[arr[i]] += 1;
    }
    
    int q;
    cout << "Enter q: ";
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // Fetch
        cout << hashh[number] << " ";
    }
    return 0;
}