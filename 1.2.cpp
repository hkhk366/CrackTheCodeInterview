//Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <malloc.h>
using namespace std;

void reverse3(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < (len / 2);++i)
	{
		char temp=s[i];
		//s[i] = s[len - i - 1];
		//s[len - i - 1] = temp;
		s[i] = s[i] ^ s[len - i - 1];
		s[len - i - 1] = s[i] ^ s[len - i - 1];
		s[i] = s[i] ^ s[len - i - 1];
	}
}

int main()
{
	char a[] = "abcd";
	reverse3(a);

}