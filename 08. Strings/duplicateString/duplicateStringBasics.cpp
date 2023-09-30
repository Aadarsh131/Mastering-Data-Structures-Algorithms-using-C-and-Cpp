#include <bits/stdc++.h>
using namespace std;
// some ways to find duplicates-
// 1. compare with other letters
// 2. using hashtable
// 3. using Bits
// 4. using sorting and comparing neighbour(src: gfg)

void printDuplicates_approach4(string s)
{
	int len = s.length();
	sort(s.begin(), s.end());

	for (int i = 0; i < len; i++)
	{
		int count = 1;
		while (s[i] == s[i + 1])
		{
			count++;
			i++;
		}
		cout << s[i] << ": " << count << " times" << endl;
	}
}
int main()
{

	// 4. using sorting and comparing neighbour
	// approach: first we sort the char array and then loop over the neighbour chars, while storing and incrementing its count until a new char is found
	string s4 = "aadarshh";
	printDuplicates_approach4(s4);

	// skipped all other methods for now
}