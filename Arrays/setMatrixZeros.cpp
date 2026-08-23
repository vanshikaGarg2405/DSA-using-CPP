#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> markRow(vector<vector<int>>& matrix, int i, int m) {
    for(int j = 0; j < m; j++) {
        if(matrix[i][j] != 0) matrix[i][j] = -1;
    }
    return matrix;
}

vector<vector<int>> markCol(vector<vector<int>>& matrix, int j, int n) {
    for(int i = 0; i < n; i++) {
        if(matrix[i][j] != 0) matrix[i][j] = -1;
    }
    return matrix;
}

vector<vector<int>> setMatrixBrute(vector<vector<int>>& matrix, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                markRow(matrix, i, m);
                markCol(matrix, j, n);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == -1) matrix[i][j] = 0;
        }
    }
    return matrix;
}

vector<vector<int>> setMatrixBetter(vector<vector<int>>& matrix, int n, int m) {
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j ++) {
            if(row[i] == 1 || col[j] == 1) matrix[i][j] = 0;
        }
    }
    return matrix;
}

vector<vector<int>> setMatrixOptimal(vector<vector<int>>& matrix, int n, int m) {
    int col0 = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                if(j != 0) matrix[0][j] = 0;
                else col0 = 0;
            }
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] != 0) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
    }
    if(matrix[0][0] == 0) {
        for(int j = 0; j < m; j++) matrix[0][j] = 0;
    }
    if(col0 == 0) {
        for(int i = 0; i < n; i++) matrix[i][0] = 0;
    }
    return matrix;
}

int main(){
    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter matrix elements: ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> matrix[i][j];
    }
    setMatrixOptimal(matrix, n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}