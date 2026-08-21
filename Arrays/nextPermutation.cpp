#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int>& arr, int n) {
    int index = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] < arr[i + 1]) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }
    for(int i = n - 1; i >= index; i--) {
        if(arr[i] > arr[index]) {
            swap(arr[i], arr[index]);
            break;
        }
    }
    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    nextPermutation(arr, n);
    for(auto x : arr) cout << x << " ";
    return 0;
}