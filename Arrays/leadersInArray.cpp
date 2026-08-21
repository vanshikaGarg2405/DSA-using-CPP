#include <bits/stdc++.h>
using namespace std;

vector<int> leadersBrute(vector<int>& arr, int n) {
    //bool leader = true;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        bool leader = true;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                leader = false;
                break;
            }
        }
        if(leader == true) ans.push_back(arr[i]);
    }
    return ans;
}

vector<int> leadersOptimal(vector<int>& arr, int n) {
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] > maxi) {
            ans.push_back(arr[i]);
            //maxi = arr[i];
        }
        maxi = max(maxi, arr[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> ans = leadersOptimal(arr, n);
    for(auto x : ans) cout << x << " ";
    return 0;
}