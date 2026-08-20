#include <bits/stdc++.h>
using namespace std;

// positive and negative elements are equal
vector<int> rearrangeElementsBrute(vector<int> &arr, int n) {
    vector<int>pos, neg;
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    for(int i = 0; i < n / 2; i++) {
        arr[2 * i] = pos[i];
        arr[2 * i + 1] = neg[i];
    }
    return arr;
}

vector<int> rearrangeElementsOptimal(vector<int>& arr, int n) {
    vector<int> ans(n);
    int posIndex = 0, negIndex = 1;
    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
        else {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }
    return ans;
}

// pos and neq are not equal
vector<int> rearrangeElements(vector<int>& arr, int n) {
    vector<int> pos, neg;
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    if(pos.size() > neg.size()) {
        for(int i = 0; i < neg.size(); i++) {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for(int i = neg.size(); i < pos.size(); i++) {
            arr[index] = pos[i];
            index++;
        }
    }
    else {
        for(int i = 0; i < pos.size(); i++) {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for(int i = pos.size(); i < neg.size(); i++) {
            arr[index] = neg[i];
            index++;
        }
    }
    return arr;
}
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n; 
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> ans = rearrangeElements(arr, n);
    for(auto x : ans) cout << x << " ";
    return 0;
}