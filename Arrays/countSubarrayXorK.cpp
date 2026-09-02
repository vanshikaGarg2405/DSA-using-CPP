#include <bits/stdc++.h>
using namespace std;

int countSubarrayBrute(vector<int>& arr, int n, int k) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int XOR = 0;
            for(int k = i; k <= j; k++) XOR ^= arr[k];
            if(XOR == k) cnt++;
        }
    }
    return cnt;
}

int countSubarrayBetter(vector<int>& arr, int n, int k) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int XOR = 0;
        for(int j = i; j < n; j++) {
            XOR ^= arr[j];
            if(XOR == k) cnt++;
        }
    }
    return cnt;
}

int countSubarrayOptimal(vector<int>& arr, int n, int k) {
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        xr ^= arr[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main() {
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << countSubarrayOptimal(arr, n, k);
    return 0;
}