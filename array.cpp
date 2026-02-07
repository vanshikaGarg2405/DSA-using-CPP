#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> &a, int n) {
    int largest = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > largest) largest = a[i];
    }
    return largest;
}

void secondlargest(vector<int> &a, int n) {
    int largest = INT_MIN, slargest = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] > largest) {
            slargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > slargest) {
            slargest = a[i];
        }
    }
    cout << slargest;
}

int isSorted(vector<int> &a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) {}
        else return false;
    }
    return true;
} 

int removeDuplicates(vector<int> &a, int n) {
    int i = 0; 
    for (int j = 1; j < n; j++) {
        if (a[i] != a[j]) {
            a[i + 1] = a[j];
            i++;
        }
    }
    return i + 1;
}

void rotateLeftByOne(vector<int> &a, int n) {
    int temp = a[0];
    for (int i = 1; i < n; i++) {
        a[i - 1] = a[i];
    }
    a[n - 1] = temp;
}

void rotateLeftByDBrute(vector<int>& a, int n, int d) {
    d = d % n;
    int temp[d];
    for(int i = 0; i < d; i++) temp[i] = a[i];
    for(int i = d; i < n; i++) a[i - d] = a[i];
    for(int i = n - d; i < n; i++) a[i] = temp[i - (n - d)];
}

void rotateLeftByDOptimal(vector<int>& a, int n, int d) {
    d = d % n;
    reverse(a.begin(), a.begin() + d);
    reverse(a.begin() + d, a.end());
    reverse(a.begin(), a.end());
}

void zeorsToEndBrute(vector<int>& a, int n) {
    vector<int> temp;
    for(int i = 0; i < n; i++) {
        if (a[i] != 0) {
            temp.push_back(a[i]);
        }
    }
    for(int i = 0; i < temp.size(); i++) a[i] = temp[i];
    for(int i = temp.size(); i < n; i++) a[i] = 0;
}

void zerosToEndOptimal(vector<int>& a, int n) {
    int j = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            j = i;
            break;
        }
    }
    for(int i = j + 1; i < n; i++) {
        if(a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
}

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

int missingNoBrute(vector<int>& a, int n) {
    int flag;
    for(int i = 1; i < n; i++) {
        flag = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] == i) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    }
}

int missingNoBetter(vector<int>& a, int n) {
    int hash[n + 1] = {0};
    for(int i = 0; i < n - 1; i++) hash[a[i]]++;
    for(int i = 1; i < n; i++) {
        if(hash[i] == 0) return i;
    }
}

int missingNoOptimalSum(vector<int>& a, int n) {
    int sum = (n * (n + 1)) / 2;
    int sumelem = 0;
    for(int i = 0; i < n; i++) {
        sumelem += a[i];
    }
    return sum - sumelem;
}

int missingNoOptimalXOR(vector<int>& a, int n) {
    int xor1 = 0;
    int xor2 = 0;
    int N = n - 1;
    for(int i = 0; i < N; i++) {
        xor1 = xor1 ^ a[i];
        xor2 = xor2 ^ (i + 1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

int maxConsOne(vector<int>& a, int n) {
    int cnt = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else cnt = 0;
    }
    return maxi;
}

int numAppOne(vector<int>& a, int n) {
    int cnt, num;
    for(int i = 0; i < n; i++) {
        num = a[i];
        cnt = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] == num) cnt++;
        }
        if(cnt == 1) return num;
    }
}

int numAppOneBetter(vector<int>& a, int n) {
    map<long long, int> mp;
    for(int i = 0; i < n; i++) mp[a[i]]++;
    for(auto it : mp) {
        if(it.second == 1) return it.first;
    }
}

int numpAppOneOptimal(vector<int>& a, int n) {
    int xor1 = 0;
    for(int i = 0; i < n; i++) xor1 = xor1 ^ a[i];
    return xor1;
}

int longestSubarrayBrute(vector<int>& a, int n, int k) {
    int len = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i ; j < n; j++) {
            sum += a[j];
            if(sum == k) len = max(len, j - i + 1);
        }
    }
    return len;
}

int longestSubarrayBetter(vector<int>& a, int n, int k) {
    map<long long, int> mpp;
    long long preSum = 0;
    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        preSum += a[i];
        if(preSum == k) maxLen = max(maxLen, i + 1);
        long long rem = preSum - k;
        if(mpp.find(rem) != mpp.end()) {
            int len = i - mpp[rem];
            maxLen = max(maxLen, len);
        }
        if(mpp.find(preSum) == mpp.end()) mpp[preSum] = i;
    }
    return maxLen;
}

int longestSubarrayOptimal(vector<int>& a, int n, int k) {
    int right = 0, left = 0;
    int maxLen= 0;
    long long sum = a[0];
    while(right < n) {
        while(left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        if(sum == k) maxLen = max(maxLen, right - left + 1);
        right++;
        if(right < n) sum += a[right];
    }
    return maxLen;
}

vector<int> twoSumYNBrute(vector<int>& a, int n, int target) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] + a[j] == target) {
                return {j, i};
            }
        }
    }
    return {-1, -1};
}

vector<int> twoSumBetter(vector<int>& a, int n, int target) {
    map<int, int> mpp;
    for(int i = 0; i < n; i++) {
        int num = a[i];
        int moreNeed = target - num;
        if(mpp.find(moreNeed) != mpp.end()) return {mpp[moreNeed], i};
        mpp[num] = i;
    }
    return {-1, -1};
}

vector<int> twoSumOptimal(vector<int>& a, int n, int target) {
    sort(a.begin(), a.end());
    for(auto it : a) cout << it << " ";
    cout << endl;
    int left = 0;
    int right = n - 1;
    while(left < right) {
        int sum = a[left] + a[right];
        if(sum == target) return {left, right};
        else if(sum < target) left++;
        else right--;
    }
    return {-1, -1};
}

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