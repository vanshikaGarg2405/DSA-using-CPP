#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElemBrute(vector<int>& arr, int n) {
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(ans.size() == 0 || ans[0] != arr[i]) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(arr[j] == arr[i]) cnt++;
            }
            if(cnt > n / 3) ans.push_back(arr[i]);
        }
        if(ans.size() == 2) break;
    }
    return ans;
}

vector<int> majorityElemBetter(vector<int>& arr, int n) {
    vector<int> ans;
    map<int, int> mpp;
    int mini = n / 3 + 1;
    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
        if(mpp[arr[i]] == mini) ans.push_back(arr[i]);
    }
    return ans;
}

vector<int> majorityElemOptimal(vector<int>& arr, int n) {
    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(cnt1 == 0 && ele2 != arr[i]) {
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if(cnt2 == 0 && ele1 != arr[i]) {
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i] == ele1) cnt1++;
        else if(arr[i] == ele2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(ele1 == arr[i]) cnt1++;
        if(ele2 == arr[i]) cnt2++;
    }
    int mini = (int)(n / 3) + 1;
    if(cnt1 >= mini) ans.push_back(ele1);
    if(cnt2 >= mini) ans.push_back(ele2);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> ans = majorityElemOptimal(arr, n);
    for(auto x : ans) cout << x << " ";
    return 0;
}