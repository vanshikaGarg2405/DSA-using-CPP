#include <bits/stdc++.h>
using namespace std;

int numAppOne(vector<int>& a, int n) {
    int cnt, num;
    for(int i = 0; i < n; i++) {
        num = a[i];
        cnt = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] == num) cnt++;
        }
        if(cnt == 1) return num;
    }
}

int numAppOneBetter(vector<int>& a, int n) {
    map<long long, int> mp;
    for(int i = 0; i < n; i++) mp[a[i]]++;
    for(auto it : mp) {
        if(it.second == 1) return it.first;
    }
}

int numpAppOneOptimal(vector<int>& a, int n) {
    int xor1 = 0;
    for(int i = 0; i < n; i++) xor1 = xor1 ^ a[i];
    return xor1;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << numAppOne(arr, n);
    return 0;
}