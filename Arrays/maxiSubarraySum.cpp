#include <bits/stdc++.h>
using namespace std;

int maxiSubarraySumBrute(int n, vector<int>& arr) {
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) sum += arr[k];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

int maxiSubarraySumBetter(int n, vector<int>& arr) {
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

int maxiSubarraySumOptimal(int n, vector<int>& arr) {
    int sum = 0, maxi = INT_MIN;
    int ansS = -1;
    int ansE = -1;
    int start = 0;
    for(int i = 0; i < n; i++) {
        if(sum  == 0) start = i;
        sum += arr[i];
        if(sum > maxi) {
            maxi = sum;
            ansS = start;
            ansE = i;
        }
        if(sum < 0) sum = 0;
    }
    return maxi;
}
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << maxiSubarraySumOptimal(n, arr) << endl;
    return 0;
}