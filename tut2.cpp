// #include<bits/stdc++.h>
// using namespace std;
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
// long long power(int n, int p) {
//     // WRITE YOUR CODE HERE
//     long long res = 1;
//     for(int i = 1; i <= p; i++) res *= n;
//     return res;
// }
// int main() {
//     int n, p;
//     cin >> n >> p;
//     cout << power(n, p) << endl;
// }
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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> solve(int n, int m, vector<vector<int>>& scores,
                              vector<int>& times) {
        
        // {score, time, participant_id}
        vector<tuple<int, int, int>> participants;

        for (int i = 0; i < n; i++) {
            int total = 0;

            for (int j = 0; j < m; j++) {
                total += scores[i][j];
            }

            // If time > 300, score is halved
            if (times[i] > 300) {
                total /= 2;
            }

            participants.push_back({total, times[i], i + 1});
        }

        // Sort by:
        // 1. Higher score first
        // 2. Lower time first
        // 3. Participant ID (for deterministic ordering)
        sort(participants.begin(), participants.end(),
             [](const auto& a, const auto& b) {
                 if (get<0>(a) != get<0>(b))
                     return get<0>(a) > get<0>(b);

                 if (get<1>(a) != get<1>(b))
                     return get<1>(a) < get<1>(b);

                 return get<2>(a) < get<2>(b);
             });

        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            int score = get<0>(participants[i]);
            int time = get<1>(participants[i]);
            int id = get<2>(participants[i]);

            result.push_back({i + 1, id, score, time});
        }

        return result;
    }
};