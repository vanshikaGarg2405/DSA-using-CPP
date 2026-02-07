#include<bits/stdc++.h>
using namespace std;

vector<int> intersectionBrute(vector<int>& a, vector<int>& b, int n1, int n2) {
    vector<int> visArr(n2, 0);
    vector<int> ans;
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) {
            if(a[i] == b[j] && visArr[j] == 0) {
                ans.push_back(a[i]);
                visArr[j] = 1;
                break;
            }
            if(b[j] > a[i]) break;
        }
    }
    return ans;
}

vector<int> intersectionOptimal(vector<int>& a, vector<int>& b, int n1, int n2) {
    int i = 0, j = 0;
    vector<int> ans;
    while(i < n1 && j < n2) {
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++;
        else {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
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
    vector<int> intersectionA = intersectionOptimal(a, b, n, k);
    for(auto x : intersectionA) cout << x << " ";
    return 0;
}