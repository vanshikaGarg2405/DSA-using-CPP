#include<bits/stdc++.h>
using namespace std;

int longestSubarrayBrute(vector<int>& a, int n, int k) {
    int len = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i ; j < n; j++) {
            sum += a[j];
            if(sum == k) len = max(len, j - i + 1);
        }
    }
    return len;
}

int longestSubarrayBetter(vector<int>& a, int n, int k) {
    map<long long, int> mpp;
    long long preSum = 0;
    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        preSum += a[i];
        if(preSum == k) maxLen = max(maxLen, i + 1);
        long long rem = preSum - k;
        if(mpp.find(rem) != mpp.end()) {
            int len = i - mpp[rem];
            maxLen = max(maxLen, len);
        }
        if(mpp.find(preSum) == mpp.end()) mpp[preSum] = i;
    }
    return maxLen;
}

int longestSubarrayOptimal(vector<int>& a, int n, int k) {
    int right = 0, left = 0;
    int maxLen= 0;
    long long sum = a[0];
    while(right < n) {
        while(left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        if(sum == k) maxLen = max(maxLen, right - left + 1);
        right++;
        if(right < n) sum += a[right];
    }
    return maxLen;
}

int main() {
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << longestSubarrayBrute(arr, n, k);
    return 0;
}