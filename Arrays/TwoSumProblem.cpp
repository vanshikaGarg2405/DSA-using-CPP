#include<bits/stdc++.h>
using namespace std;

vector<int> twoSumYNBrute(vector<int>& a, int n, int target) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] + a[j] == target) {
                return {j, i};
            }
        }
    }
    return {-1, -1};
}

vector<int> twoSumBetter(vector<int>& a, int n, int target) {
    map<int, int> mpp;
    for(int i = 0; i < n; i++) {
        int num = a[i];
        int moreNeed = target - num;
        if(mpp.find(moreNeed) != mpp.end()) return {mpp[moreNeed], i};
        mpp[num] = i;
    }
    return {-1, -1};
}

vector<int> twoSumOptimal(vector<int>& a, int n, int target) {
    sort(a.begin(), a.end());
    for(auto it : a) cout << it << " ";
    cout << endl;
    int left = 0;
    int right = n - 1;
    while(left < right) {
        int sum = a[left] + a[right];
        if(sum == target) return {left, right};
        else if(sum < target) left++;
        else right--;
    }
    return {-1, -1};
}

int main() {
    int n, target;
    cout << "Enter n and target: ";
    cin >> n >> target;
    vector<int> a(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans = twoSumOptimal(a, n, target);
    cout << ans[0] << " " << ans[1] << endl;
}