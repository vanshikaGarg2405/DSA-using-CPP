#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &a, int n) {
    int i = 0; 
    for (int j = 1; j < n; j++) {
        if (a[i] != a[j]) {
            a[i + 1] = a[j];
            i++;
        }
    }
    return i + 1;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << removeDuplicates(a, n);
    return 0;
}