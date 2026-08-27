#include <bits/stdc++.h>
using namespace std;

// Given row and col, tell the element at that place in pascal 
int nCr(int row, int col) {
    long long ans = 1;
    for(int i = 0; i < col; i++) {
        ans = ans * (row - i);
        ans = ans / (i + 1);
    }
    return ans;
}

// int main() {
//     int row, col;
//     cout << "Enter row and col: ";
//     cin >> row >> col;
//     cout << nCr(row - 1, col - 1);
//     return 0;
// }

// Print nth row of the pascal
vector<int> printRowBrute(int row) {
    vector<int> ans;
    for(int i = 1; i <= row; i++) ans.push_back(nCr(row - 1, i - 1));
    return ans;
}

vector<int> printRowOptimal(int row) {
    long long res = 1;
    vector<int> ans;
    ans.push_back(res);
    for(int i = 1; i < row; i++) {
        res = res * (row - i);
        res = res / i;
        ans.push_back(res);
    }
    return ans;
}

// int main() {
//     int row;
//     cout << "Enter row no.: ";
//     cin >> row;
//     vector<int> ans = printRowOptimal(row);
//     for(auto x : ans) cout << x << " ";
//     return 0;
// }

// Given n, print entire pascal
vector<vector<int>> printPascalBrute(int row) {
    vector<vector<int>> ans;
    for(int i = 1; i <= row; i++) {
        vector<int> temp;
        for(int col = 1; col <= i; col++) temp.push_back(nCr(i - 1, col - 1));
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<int>> printPascalOptimal(int row) {
    vector<vector<int>> ans;
    for(int i = 1; i <= row; i++) {
        vector<int> temp = printRowOptimal(i);
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    int row;
    cout << "Enter row no.: ";
    cin >> row;
    vector<vector<int>> ans = printPascalOptimal(row);
    for(auto x : ans) {
        for(auto y : x) cout << y << " ";
        cout << endl;
    }
    return 0;
}