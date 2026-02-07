#include <bits/stdc++.h>
using namespace std;

void explainStack()
{
    stack<int> st;
    st.push(1);    //{1}
    st.push(3);    //{3, 1}
    st.push(4);    //{4, 3, 1}
    st.emplace(2); //{2, 4, 3, 1}
    st.emplace(6); //{6, 2, 4, 3, 1}

    cout << st.top(); // 6

    st.pop(); //{2, 4, 3, 1}

    cout << endl
         << st.top(); // 2

    cout << endl
         << st.size(); // 4
    cout << endl
         << st.empty(); // 0

    stack<int> st1, st2;
    st1.swap(st2);
};

int main()
{
    explainStack();
}