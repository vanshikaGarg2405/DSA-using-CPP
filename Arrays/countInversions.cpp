#include<bits/stdc++.h>
using namespace std;

int countInversionsBrute(vector<int>& arr, int n) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) cnt++;
        }
    }
    return cnt;
}

// Full merge sort, only some lines are added for counting pairs
int merge(vector<int> &arr, int low, int mid, int high)  {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0; // variable where no of pairs stored
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //counting
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) arr[i] = temp[i - low];
    return cnt; //counting
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);  //counting
    cnt += mergeSort(arr, mid + 1, high);  //counting
    cnt += merge(arr, low, mid, high);  //counting
    return cnt;  //counting
}

int countInversionsOptimal(vector<int>& arr, int n) {
    return mergeSort(arr, 0, n - 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "No. of pairs: " << countInversionsOptimal(arr, n);
    return 0;
}