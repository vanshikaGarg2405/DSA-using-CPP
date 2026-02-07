#include <bits/stdc++.h>
using namespace std;

void rotateLeftByDBrute(vector<int>& a, int n, int d) {
    d = d % n;
    int temp[d];
    for(int i = 0; i < d; i++) temp[i] = a[i];
    for(int i = d; i < n; i++) a[i - d] = a[i];
    for(int i = n - d; i < n; i++) a[i] = temp[i - (n - d)];
}

void rotateLeftByDOptimal(vector<int>& a, int n, int d) {
    d = d % n;
    reverse(a.begin(), a.begin() + d);
    reverse(a.begin() + d, a.end());
    reverse(a.begin(), a.end());
}

int main() {
    int n, d;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter d: ";
    cin >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    rotateLeftByDBrute(a, n, d);
    for(auto x : a) cout << x << " ";
    return 0;
}