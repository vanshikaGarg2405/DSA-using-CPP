#include <bits/stdc++.h>
using namespace std;

int countSubarrayBrute(vector<int>& arr, int n, int target) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) sum += arr[k];
            if(sum == target) cnt++;
        }
    }
    return cnt;
}

int countSubarrayBetter(vector<int>& arr, int n, int target) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == target) cnt++;
        }
    }
    return cnt;
}

int countSubarrayOptimal(vector<int>& arr, int n, int target) {
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        preSum += arr[i];
        int remove = preSum - target;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
}

int main(){
    int n, target;
    cout << "Enter n and target: ";
    cin >> n >> target;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << countSubarrayOptimal(arr, n, target);
    return 0;
}