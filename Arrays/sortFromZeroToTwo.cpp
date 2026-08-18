#include<bits/stdc++.h>
using namespace std;
void sortZOTBrute(vector<int>& a, int n) {
   sort(a.begin(), a.end());
   for(auto it : a) cout << it << " ";
}

vector<int> sortZOTBetter(vector<int>& a, int n) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) cnt0++;
        else if(a[i] == 1) cnt1++;
        else cnt2++;
    }
    for(int i = 0; i < cnt0; i++) a[i] = 0;
    for(int i = cnt0; i < cnt0 + cnt1; i++) a[i] = 1;
    for(int i = cnt0 + cnt1; i < n; i++) a[i] = 2;
    return a;
}

vector<int> sortZOTOptimal(vector<int>& a, int n) {
    int mid = 0, low = 0, high = n - 1;
    while(mid <= high) {
        if(a[mid] == 0) {
            swap(a[mid], a[low]);
            mid++;
            low++;
        }
        else if(a[mid] == 1) mid++;
        else {
            swap(a[mid], a[high]);
            high--;
        }
    }
    return a;
}

int main() {
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    //cout << "Enter k: ";
    //cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> res = sortZOTOptimal(a, n);
    for(auto i : res) cout << i << " ";
    return 0;
}