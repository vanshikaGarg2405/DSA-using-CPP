#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& matrix, int n, int m) {
    vector<int> ans;
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;
    while (top <= bottom && left <= right) {
        // Right
        for (int i = left; i <= right; i++) ans.push_back(matrix[top][i]);
        top++;
        // Bottom
        for (int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
        right--;
        // Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
            bottom--;
        }
        // Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
            left++;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter matrix elements: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> matrix[i][j];
    }
    vector<int> ans = spiralMatrix(matrix, n, m);
    for (auto x : ans) cout << x << " ";
    return 0;
}