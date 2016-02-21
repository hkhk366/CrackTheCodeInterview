//Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer.NOTE: One or two additional variables are fine.An extra copy of the array is not.
//
//FOLLOW UP
//
//Write the test cases for this method.


#include <iostream>
#include <string>
using namespace std;

string removeduplicate(string s)
{
	int bit = 0;
	string result;
	for (int i = 0; i < s.length(); ++i)
	{
		int movenum = s[i] - 'a';
		if ((bit&(1 << movenum)) == 0)
		{
			bit |= (1 << movenum);
			result += s[i];
		}
	}
	return result;
}

int main()
{
	string s2 = "aaabbb";
	cout << removeduplicate(s2);
	return 0;
}