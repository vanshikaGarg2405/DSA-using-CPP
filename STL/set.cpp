#include <bits/stdc++.h>
using namespace std;

void explainSet()
{
    set<int> st;
    st.insert(2);
    st.insert(3);
    st.insert(2);
    st.insert(5);
    st.insert(1);

    for (auto it = st.begin(); it != st.end(); it++)
    {
        cout << *(it) << " ";
    }

    int cnt = st.count(2);
    cout << endl
         << cnt << endl;

    auto it = st.find(1);
    auto it1 = st.find(3);
    st.erase(it, it1);

    for (auto it2 = st.begin(); it2 != st.end(); it2++)
    {
        cout << *(it2) << " ";
    }
};

int main()
{
    explainSet();
}