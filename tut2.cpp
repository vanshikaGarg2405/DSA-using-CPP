#include<bits/stdc++.h>
using namespace std;
// bool isPrime(int n) {
//     if (n < 2) return false;
//     for(int i = 2; i * i <= n; i++) {
//         if(n % i == 0) return false;
//     }
//     return true;
// }
// int main() {
//     int n;
//     cin >> n;
//     vector<bool> isPrime(n + 1, true);
//     isPrime[0] = false;
//     isPrime[1] = false;
//     for(int i = 2; i * i <= n; i++) {
//         if(isPrime(i) == true) {
//             for(int j = i; i * j <= n; j++) isPrime(i * j) = false;
//         }
//     }
// }
long long power(int n, int p) {
    // WRITE YOUR CODE HERE
    long long res = 1;
    for(int i = 1; i <= p; i++) res *= n;
    return res;
}
int main() {
    int n, p;
    cin >> n >> p;
    cout << power(n, p) << endl;
}
// long long factorial(int n) {
//     // WRITE YOUR CODE HERE
//     long long res = 1;
//     for(int i = 1; i <= n; i++) {
//         res *= i;
//     }
//     return res;
// }
// int main() {
//     int n;
//     cin >> n;
//     cout << factorial(n) << endl;
// }