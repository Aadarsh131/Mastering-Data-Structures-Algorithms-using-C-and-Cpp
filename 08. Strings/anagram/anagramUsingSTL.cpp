// using std::string::compare() function
#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string a, string b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a.compare(b) == 0)
        return true;
    return false;
}
int main()
{
    string a = "geeksforgeeks";
    string b = "forgeeksgeeks";
    if (isAnagram(a, b))
        cout << "YES, They are Anagram" << endl;
    else
        cout << "NO, They are not Anagram" << endl;
}
