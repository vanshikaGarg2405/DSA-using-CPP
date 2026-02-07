#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> &a, int n) {
    int largest = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > largest) largest = a[i];
    }
    return largest;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << largest(a, n);
    return 0;
}