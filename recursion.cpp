#include <bits/stdc++.h>
using namespace std;

void f()
{
    cout << "1";
    f();
}

int cnt = 0;
void f1()
{
    if (cnt == 5)
        return;
    cout << cnt << endl;
    cnt++;
    f1();
}

void name(int i, int n)
{
    // Time complexity - o(N)
    // Space complexity - o(N)
    if (i > n)
    {
        return;
    }
    cout << "Vanshika" << endl;
    name(i + 1, n);
}

void oneToN(int i, int n)
{
    if (i > n)
    {
        return;
    }
    cout << i << endl;
    oneToN(i + 1, n);
}

void nToOne(int n, int i)
{
    if (n < i)
    {
        return;
    }
    cout << n << endl;
    nToOne(n - 1, i);
}

void oneToNBT(int i, int N) {
    if (i < 1) 
        return;
    oneToNBT(i - 1, N);
    cout << i << endl;
}

void NToOneBT(int i, int n) {
    if ( i > n) {
        return;
    }
    NToOneBT(i + 1, n);
    cout << i << endl;
}

void parameterisedSum(int i , int sum) {
    if (i < 1) {
        cout << "Sum = " << sum;
        return;
    }
    parameterisedSum(i - 1, sum + i);
}

int functionalSum(int n) {
    if (n == 0) {
        return 0;
    }
    return (n + functionalSum(n - 1));
}

void parameterisedFactorial(int i, int fact) {
    if (i < 1) {
        cout << "factorial = " << fact;
        return;
    }
    parameterisedFactorial(i - 1, fact * i);
}

int functionalFactorial(int n) {
    // Time Complexity - o(N)
    // Stack Complexity - o(N)
    if (n == 0) {
        return 1;
    }
    return (n * functionalFactorial(n - 1));
}

void reverseArray(int i, int arr[], int n) {
    if (i >= n / 2) {
        return;
    }
    swap(arr[i], arr[n-i-1]);
    reverseArray(i + 1, arr, n);
}

bool palindromeString(int i, string &s) {
    if (i >= s.size() / 2) return true;
    if (s[i] != s[s.size() - i - 1]) return false;
    return palindromeString(i + 1, s);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << fibonacci(n);
}