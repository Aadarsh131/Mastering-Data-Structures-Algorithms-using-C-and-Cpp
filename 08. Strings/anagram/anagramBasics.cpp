#include <iostream>
#include <bits/stdc++.h>
#define NO_OF_CHARS 256
using namespace std;

bool compareString(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 != n2)
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < n1; i++)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

bool areAnagram(char *str1, char *str2)
{
    // string length check
    int size1 = sizeof(str1) / sizeof(str1[0]);
    int size2 = sizeof(str2) / sizeof(str2[0]);
    if (size1 != size2)
        return false;

    // Create 2 count arrays and initialize all values as 0
    int count1[NO_OF_CHARS] = {0};
    int count2[NO_OF_CHARS] = {0};
    int i;

    // For each character in input strings, increment count
    // in the corresponding count array
    for (i = 0; str1[i] && str2[i]; i++)
    {
        count1[str1[i]]++; // eg. count1[97]++
        count2[str2[i]]++;
    }

    // Compare count arrays
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count1[i] != count2[i])
            return false;

    return true;
}

int main()
{
    // sort and compare 
    //time complexity- O(N logN), because of the sort()
    //space complexity- O(1)
    string s1 = "decimal";
    string s2 = "medical";

    if (compareString(s1, s2))
        cout << s1 << " and " << s2 << " are anagrams" << endl;
    else
        cout << s1 << " and " << s2 << " are NOT anagrams" << endl;

    // counting frequency using extra 2 array
    // The idea is based in an assumption that the set of possible characters in both strings is small. that the characters are stored using 8 bit and there can be 256 possible characters.
    //time complextiy- O(N)
    //space complexity- O(256) i.e O(1)
    char str1[] = "gram";
    char str2[] = "arm";
    if (areAnagram(str1, str2))
        cout << "The two strings are anagram of each other";
    else
        cout << "The two strings are not anagram of each "
                "other";
}