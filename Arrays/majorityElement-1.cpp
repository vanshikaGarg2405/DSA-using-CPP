#include <bits/stdc++.h>
using namespace std;

int majorityElementBrute(int n ,vector<int> &arr) {
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(arr[j] == arr[i]) cnt++;
        }
        if(cnt > n / 2) return arr[i];
    }
    return -1;
}

int majorityElementBetter(int n, vector<int> &arr) {
    map<int, int> mpp;
    for(int i = 0; i < n; i++) mpp[arr[i]]++;
    for(auto it : mpp) {
        if(it.second > n  / 2) return it.first;
    }
    return -1;
}

int majorityElementOptimal(int n, vector<int>& arr) {
    int cnt = 0;
    int ele;
    for(int i = 0; i < n; i++) {
        if(cnt == 0) {
            cnt = 1;
            ele = arr[i];
        }
        if(arr[i] == ele) cnt++;
        else cnt--;
    }
    int cnt1 = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == ele) cnt1++;
    }
    if(cnt1 > n / 2) return ele;
    return -1;
}
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter array elements: ";
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << majorityElementOptimal(n, arr) << endl;
    return 0;
}