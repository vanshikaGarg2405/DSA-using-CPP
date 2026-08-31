#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSumBrute(vector<int>& arr, int n) {
    set<vector<int>> st;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSumBetter(vector<int>& arr, int n) {
    set<vector<int>> st;
    for(int i = 0; i < n; i++) {
        set<int> hashSet;
        for(int j = i + 1; j < n; j++) {
            int third = -(arr[i] + arr[j]);
            if(hashSet.find(third) != hashSet.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSumOptimal(vector<int>& arr, int n) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        if(i > 0 && arr[i] == arr[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;
        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0) j++;
            else if(sum > 0) k--;
            else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && arr[j] == arr[j - 1]) j++;
                while(j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<int>> ans = threeSumOptimal(arr, n);
    for(auto x : ans) {
        for(auto y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}