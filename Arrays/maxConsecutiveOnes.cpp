#include <bits/stdc++.h>
using namespace std;

int maxConsOne(vector<int>& a, int n) {
    int cnt = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else cnt = 0;
    }
    return maxi;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << maxConsOne(arr, n);
    return 0;
}