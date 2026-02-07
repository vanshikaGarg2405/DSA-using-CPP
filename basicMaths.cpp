#include <bits/stdc++.h>
using namespace std;

void extractionOfDigits()
{
    int n, last_digit;
    cout << "Enter n: ";
    cin >> n;

    while (n > 0)
    {
        last_digit = n % 10;
        cout << last_digit << endl;
        n = n / 10;
    }
}

// void countNoOfDigits() {
//     int n, last_digit, cnt = 0;
//     cout << "Enter n: ";
//     cin >> n;
//
//     while (n > 0) {
//         last_digit = n % 10;
//         cout << last_digit << endl;
//         cnt += 1;
//         n = n / 10;
//     }
//     cout << "Number of digits: " << cnt << endl;
// }

void numberOfDigits()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int count = (int)(log10(n) + 1);
    cout << "Number of digits: " << count << endl;
}

void reverseNumber()
{
    int n, last_digit, reverse_num = 0;
    cout << "Enter n: ";
    cin >> n;

    while (n > 0)
    {
        last_digit = n % 10;
        n = n / 10;
        reverse_num = (reverse_num * 10) + last_digit;
    }
    cout << "Reverse No.: " << reverse_num << endl;
}

void checkPolindrome()
{
    int n, last_digit, reverse_num = 0;
    cout << "Enter n: ";
    cin >> n;
    int num = n;

    while (n > 0)
    {
        last_digit = n % 10;
        n = n / 10;
        reverse_num = (reverse_num * 10) + last_digit;
    }

    cout << reverse_num << endl;

    if (num == reverse_num)
    {
        cout << num << " = " << reverse_num << endl
             << num << " is polindrome." << endl;
    }
    else
    {
        cout << num << " is not polindrome.";
    }
}

void armstrongNo()
{
    int n, last_digit, sum = 0;
    cout << "Enter n: ";
    cin >> n;
    int num = n;

    while (n > 0)
    {
        last_digit = n % 10;
        n = n / 10;
        sum = sum + (last_digit * last_digit * last_digit);
    }

    if (sum == num)
    {
        cout << num << " is an Armstrong no.";
    }
    else
    {
        cout << num << " is not an Armstrong no.";
    }
}

void findDivisors()
{
    int n;
    vector<int> v;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (n / i != i)
            {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
}

void checkPrime()
{
    int n, cnt = 0;
    cout << "Enter n: ";
    cin >> n;
    int num = n;


    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if (n / i != i)
            {
                cnt++;
            }
        }
    }

    cout << "No. of divisors: " << cnt << endl;

    if (cnt == 2)
    {
        cout << num << " is prime.";
    }
    else
    {
        cout << num << " is composite.";
    }
}

void calculateHCF() {
    int n1, n2;
    cout << "Enter n1: ";
    cin >> n1;
    cout << "Enter n2: ";
    cin >> n2;

    for (int i = min(n1, n2); i >= 1; i--) {
        if (n1 % i == 0 && n2 % i == 0) {
            cout << i;
            break;
        }
    }
}

void calculateGCD() {
    int n1, n2;
    cout << "Enter n1 and n2: ";
    cin >> n1 >> n2;

    while (n1 > 0 && n2 > 0) {
        if (n1 > n2) {
            n1 = n1 % n2;
        } else {
            n2 = n2 % n1;
        }
    }

    if (n1 == 0) {
        cout << "GCD/HCF = " << n2;
    } else {
        cout << "GCD/HCF = " << n1;
    }
}

int main()
{
    checkPrime();
}