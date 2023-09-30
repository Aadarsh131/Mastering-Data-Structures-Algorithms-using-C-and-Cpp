#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "aadarsshhh";
    map<char, int> a;
    multiset<int> b;
    for (auto i : str)
    {
        b.insert(i);
    }

    for (auto i : b)
    {
        a[i] = b.count(i);
    }

    for (auto i : a)
    {
        cout << i.first << ": " << i.second << " times" << endl;
    }
}