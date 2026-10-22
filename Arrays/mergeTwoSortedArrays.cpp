#include <bits/stdc++.h>
using namespace std;

void mergeBrute(vector<int>& arr1, vector<int>& arr2, int n, int m) {
    vector<int> ans(n + m);
    int left = 0;
    int right = 0;
    int index = 0;
    while(left < n && right < m) {
        if(arr1[left] <= arr2[right]) {
            ans[index] = arr1[left];
            left++; index++;
        }
        else {
            ans[index] = arr2[right];
            right++; index++;
        }
    }
    while(left < n) ans[index++] = arr1[left++];
    while(right < m) ans[index++] = arr2[right++];
    for(int i = 0; i < n + m; i++) {
        if(i < n) arr1[i] = ans[i];
        else arr2[i - n] = ans[i];
    }
}

void mergeOptimal1(vector<int>& arr1, vector<int>& arr2, int n, int m) {
    int left = n - 1;
    int right = 0;
    while(left >= 0 && right < m) {
        if(arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else break;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

void swapGrt(vector<int>& arr1, vector<int>& arr2, int idx1, int idx2) {
    if(arr1[idx1] > arr2[idx2]) swap(arr1[idx1], arr2[idx2]);
}
void mergeOptimal2(vector<int>& arr1, vector<int>& arr2, int n, int m) {
    int len = n + m;
    int gap = (len / 2) + (len % 2);
    while(gap > 0) {
        int left = 0;
        int right = left + gap;
        while (right < len) {
            if (left < n && right >= n) {
                if (arr1[left] > arr2[right - n]) swap(arr1[left], arr2[right - n]);
            }
            else if (left >= n) {
                if (arr2[left - n] > arr2[right - n]) swap(arr2[left - n], arr2[right - n]);
            }
            else {
                if (arr1[left] > arr1[right]) swap(arr1[left], arr1[right]);
            }
            left++;
            right++;
        }
        if(gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
}

int main(){
    int n, m;
    cout << "Enter no. of elemnets in array 1: ";
    cin >> n;
    cout << "Enter no. of elemnets in array 2: ";
    cin >> m;
    vector<int> arr1(n);
    cout << "Enter array 1 elements: ";
    for(int i = 0; i < n; i++) cin >> arr1[i];
    vector<int> arr2(m);
    cout << "Enter array 2 elements: ";
    for(int i = 0; i < m; i++) cin >> arr2[i];
    mergeOptimal2(arr1, arr2, n, m);
    for(int i = 0; i < n; i++) cout << arr1[i] << " ";
    for(int i = 0 ; i < m; i++) cout << arr2[i] << " ";
    return 0;
}