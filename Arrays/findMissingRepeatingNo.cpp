#include <bits/stdc++.h>
using namespace std;

vector<int> missRepeatBrute(vector<int>& arr, int n) {
    int missing = -1, repeating = -1;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] == i) cnt++;
        }
        if(cnt == 2) repeating = i;
        else if(cnt == 0) missing = i;
        if(repeating != -1 && missing != -1) break;
    }
    return {repeating, missing};
}

vector<int> missRepeatBetter(vector<int>& arr, int n) {
    vector<int> hashArr(n + 1, 0);
    for(int i = 0; i < n; i++) hashArr[arr[i]]++;
    int repeating = -1, missing = -1;
    for(int i = 1; i <= n; i++) {
        if(hashArr[i] == 2) repeating = i;
        else if(hashArr[i] == 0) missing = i;
        if(repeating != -1 && missing != -1) break;
    }
    return {repeating, missing};
}

vector<int> missRepeatOptimalMaths(vector<int>& arr, int n) {
    long long Sn = (n * (n + 1)) / 2;
    long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long S = 0, S2 = 0;
    for(int i = 0; i < n; i++) {
        S += (long long)arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    long long val1 = S - Sn;
    long long val2 = S2 - S2n;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> ans = missRepeatOptimalMaths(arr, n);
    for(auto x : ans) cout << x << " ";
    return 0;
}