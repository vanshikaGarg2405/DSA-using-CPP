#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrixBrute(vector<vector<int>>& matrix, int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) ans[j][(n - 1) - i] = matrix[i][j];
    }
    return ans;
}

vector<vector<int>> rotateMatrixOptimal(vector<vector<int>>& matrix, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) swap(matrix[i][j], matrix[j][i]);
    }
    for(int i = 0; i < n; i++) reverse(matrix[i].begin(), matrix[i].end());
    return matrix;
}
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter matrix elements: ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> matrix[i][j];
    }
    //vector<vector<int>> ans = rotateMatrixBrute(matrix, n);
    rotateMatrixOptimal(matrix, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}