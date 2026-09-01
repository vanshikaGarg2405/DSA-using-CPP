#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSumBrute(vector<int>& arr, int n, int target) {
    set<vector<int>> st;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                for(int l = k + 1; l < n; l++) {
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == target) {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<long long>> fourSumBetter(vector<int>& arr, int n, int target) {
    set<vector<long long>> st;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for(int k = j + 1; k < n; k++) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                long long four = target - sum;
                if(hashset.find(four) != hashset.end()) {
                    vector<long long> temp = {arr[i], arr[j], arr[k], four};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<long long>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSumOptimal(vector<int>& arr, int n, int target) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        if(i > 0 && arr[i] == arr[i - 1]) continue;
        for(int j = i + 1; j < n; j++) {
            if(j > i + 1 && arr[j] == arr[j - 1]) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum == target) {
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && arr[k] == arr[k - 1]) k++;
                    while(k < l && arr[l] == arr[l + 1]) l--;
                }
                else if(sum < target) k++;
                else l--;
            }
        }
    }
    return ans;
}

int main(){
    int n, target;
    cout << "Enter n and target: ";
    cin >> n >> target;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<int>> ans = fourSumOptimal(arr, n, target);
    for(auto x : ans) {
        for(auto y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}