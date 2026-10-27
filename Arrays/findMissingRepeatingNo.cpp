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

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> ans = missRepeatBetter(arr, n);
    for(auto x : ans) cout << x << " ";
    return 0;
}