//Describe how you could use a single array to implement three stacks.


#include <iostream>
#include <string>
#include <map>
using namespace std;

class mystack
{
public:
	mystack()
	{
		p = new int[30];
		memset(p, 0, sizeof(int) * 10);
		this->totalSize = 30;
	}
	mystack(int inpara)
	{
		p = new int[inpara];
		memset(p, 0, sizeof(int) * inpara);
		this->totalSize = 90;
	}
	~mystack()
	{
		delete[] p;
	}
	void push(int index, int val)//index means to save to which stack
	{
		p[index*totalSize / 3 + currentIndex[index]] = val;//store data
		++currentIndex[index];//currentIndex means the index of one specific stack. And just like a offset.
	}
	int pop(int index)
	{
		--currentIndex[index];
		return p[index*totalSize / 3 + currentIndex[index]];
	}
	int top(int index)
	{
		return p[index*totalSize / 3 + currentIndex[index] - 1];
	}
	void empty(int index)
	{
		currentIndex[index] = 0;
	}
private:
	int *p;
	int currentIndex[3] = { 0 };
	int totalSize;
};


void main()
{
	mystack test;
	mystack test2(90);
	test.push(0,0);
	test.push(0,1);
	test.push(0,2);
	test.push(2, 3);
	test.push(2, 4);
	test.push(2, 5);
	cout << test.pop(2) << endl;
	cout << test.top(2) << endl;
	cout << test.pop(2) << endl;
	test.push(2, 6);
	cout << test.pop(2) << endl;
	test.empty(0);
	test.push(0, 8);
	cout << test.top(0);
}
