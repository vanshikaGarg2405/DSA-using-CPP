#include <bits/stdc++.h>
using namespace std;

void secondlargest(vector<int> &a, int n) {
    int largest = INT_MIN, slargest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > largest) {
            slargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > slargest) {
            slargest = a[i];
        }
    }
    cout << slargest;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    secondlargest(a, n);
    return 0;
}