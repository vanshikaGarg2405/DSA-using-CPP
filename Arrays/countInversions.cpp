#include<bits/stdc++.h>
using namespace std;

int countInversions(vector<int>& arr, int n) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "No. of pairs: " << countInversions(arr, n);
    return 0;
}