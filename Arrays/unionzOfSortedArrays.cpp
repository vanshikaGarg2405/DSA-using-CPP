#include<bits/stdc++.h>
using namespace std;

void unionBrute(vector<int>& a, vector<int>& b, int n, int k) {
    set<int> s;
    for(int i = 0; i < n; i++) s.insert(a[i]);
    for(int i = 0; i < k; i++) s.insert(b[i]); 
    for (auto i : s) cout << i << " ";   
}

vector<int> unionOptimal(vector<int>&a, vector<int>& b, int n1, int n2) {
    vector<int> unionArr;
    int i = 0, j = 0;
    while(i < n1 && j < n2) {
        if(a[i] < b[j]) {
            if(unionArr.size() == 0 || unionArr.back() != a[i]) unionArr.push_back(a[i]);
            i++;
        }
        else {
            if(unionArr.size() == 0 || unionArr.back() != b[j]) unionArr.push_back(b[j]);
            j++;
        }
    }
    while(i < n1) {
        if(unionArr.size() == 0 || unionArr.back() != a[i]) unionArr.push_back(a[i]);
        i++;
    }
    while(j < n2) {
        if(unionArr.size() == 0 || unionArr.back() != b[j]) unionArr.push_back(b[j]);
        j++;
    }
    return unionArr;
}

int main() {
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];
    vector<int> unionA = unionOptimal(a, b, n, k);
    for(auto x : unionA) cout << x << " ";
    return 0;
}