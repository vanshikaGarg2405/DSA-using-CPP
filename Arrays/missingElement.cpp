#include <bits/stdc++.h>
using namespace std;

int missingNoBrute(vector<int>& a, int n) {
    int flag;
    for(int i = 1; i < n; i++) {
        flag = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] == i) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    }
}

int missingNoBetter(vector<int>& a, int n) {
    int hash[n + 1] = {0};
    for(int i = 0; i < n - 1; i++) hash[a[i]]++;
    for(int i = 1; i < n; i++) {
        if(hash[i] == 0) return i;
    }
}

int missingNoOptimalSum(vector<int>& a, int n) {
    int sum = (n * (n + 1)) / 2;
    int sumelem = 0;
    for(int i = 0; i < n; i++) {
        sumelem += a[i];
    }
    return sum - sumelem;
}

int missingNoOptimalXOR(vector<int>& a, int n) {
    int xor1 = 0;
    int xor2 = 0;
    int N = n - 1;
    for(int i = 0; i < N; i++) {
        xor1 = xor1 ^ a[i];
        xor2 = xor2 ^ (i + 1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << missingNoBrute(arr, n);
    return 0;
}