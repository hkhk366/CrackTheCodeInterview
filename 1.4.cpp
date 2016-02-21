//Write a method to decide if two strings are anagrams or not.


#include <iostream>
#include <string>
using namespace std;


bool isAnagram(string s, string t)
{
	int check[256];
	cout << sizeof(check);
	memset(check, 0, sizeof(check));
	for (int i = 0; i < s.size();++i)
	{
		++check[s[i]];
	}
	for (int i = 0; i < t.size();++i)
	{
		--check[t[i]];
	}
	for (int i = 0; i < 256; ++i)
	{
		if (check[i] != 0)
			return false;
	}
	return true;
}

int main()
{
	string a = "abc";
	string b = "dba";
	bool test=isAnagram(a, b);

	return 0;
}