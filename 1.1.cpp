//Implement an algorithm to determine if a string has all unique characters.What if you can not use additional data structures ?


#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>


using namespace std;


bool verify(string in)
{
	bool bit[256];
	memset(bit, 0, sizeof(bit));
	for (int i = 0; i < in.length();++i)
	{
		if (bit[in[i]] ==false)
		{
			bit[in[i]] = true;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cout << verify("abcdefga");
}