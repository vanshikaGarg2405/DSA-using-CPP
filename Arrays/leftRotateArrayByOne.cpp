#include <bits/stdc++.h>
using namespace std;

void rotateLeftByOne(vector<int> &a, int n) {
    int temp = a[0];
    for (int i = 1; i < n; i++) {
        a[i - 1] = a[i];
    }
    a[n - 1] = temp;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    rotateLeftByOne(a, n);
    for(auto x : a) cout << x << " ";
    return 0; 
}