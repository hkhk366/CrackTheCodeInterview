//Write a method to replace all spaces in a string with ‘%20’.


#include <iostream>
#include <string>
using namespace std;

void replace(char * in)
{
	int len = strlen(in); int totalspace = 0;
	for (int i = 0; i < len; ++i) 
		if (in[i]==' ')
			++totalspace;
	int totalindex = len + totalspace * 2;
	in[totalindex--] = '\0';
	for (int i = len; i >= 0; --i)
	{
		if (in[i]==' ')
		{
			in[totalindex--] = '0';
			in[totalindex--] = '2';
			in[totalindex--] = '%';
		}
		else
		{
			in[totalindex--] = in[i - 1];
		}
	}
}

int main()
{
	char s[100] = "He llo";
	//cout << strlen(s);
	replace(s);
	system("pause");
}