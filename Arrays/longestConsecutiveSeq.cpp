#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& arr, int x) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == x) return true;
    }
    return false;
}
int longestConsBrute(vector<int>& arr, int n) {
    int longest = 1;
    int x, cnt;
    for(int i = 0; i < n; i++) {
        x = arr[i];
        cnt = 1;
        while(linearSearch(arr, x + 1) == true) {
            x = x + 1;
            cnt++;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

int longestConsBetter(vector<int>& arr, int n) {
    int longest = 1;
    int cntCur = 0;
    int lastSmaller = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] - 1 == lastSmaller) {
            cntCur += 1;
            lastSmaller = arr[i];
        }
        else if(arr[i] != lastSmaller) {
            cntCur = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, cntCur);
    }
    return longest;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter arrays elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    cout << longestConsBetter(arr, n); 
    return 0;
}