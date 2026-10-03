#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingBrute(vector<vector<int>>& arr, int n) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]) continue;
        for(int j = i + 1; j < n; j++) {
            if(arr[j][0] <= end) end = max(end, arr[j][1]);
            else break;
        }
        ans.push_back({start, end});
    }
    return ans;
}

vector<vector<int>> mergeOverlappingOptimal(vector<vector<int>>& arr, int n) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        if(ans.empty() || arr[i][0] > ans.back()[1]) ans.push_back(arr[i]);
        else ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
    return ans;
}


int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));
    cout << "Enter intervals: ";
    for(auto &x: arr) cin >> x[0] >> x[1];
    vector<vector<int>> ans = mergeOverlappingOptimal(arr, n);
    cout << "Answer array: \n";
    for(auto x: ans) cout << x[0] << " " << x[1] << endl;
    return 0;
}