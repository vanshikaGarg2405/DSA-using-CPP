#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, maxi = INT_MIN;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 1; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    int profit = maxi - arr[0];
    cout << profit;
}