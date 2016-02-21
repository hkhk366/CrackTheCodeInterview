//How would you design a stack which, in addition to push and pop, also has a function min which returns the minimum element? Push, pop and min should all operate in O(1) time.


#include <iostream>
#include <string>
#include <map>
using namespace std;

class mystack
{
public:
	mystack()
	{
		p = new int[10];
		q = new int[10];
		memset(p, 0, sizeof(int) * 10);
		memset(q, 0, sizeof(int) * 10);
	}
	~mystack()
	{
		delete[] p;
		delete[] q;
	}
	void push(int val)
	{
		p[index[0]++] = val;
		if (val < min())
			q[index[1]++] = val;
	}
	int pop()
	{
		int temp = p[--index[0]];
		if (temp == min())
			--index[1];
		return temp;
	}
	int top()
	{
		return  p[index[0] - 1];
	}
	void empty()
	{
		index[0] = index[1] = 0;
	}
	int min()
	{
		if (index[1] != 0)
			return q[index[1] - 1];
		else
			return INT_MAX;
	}
private:
	int *p,*q;//p is array to store data. q is array to save the smallest data from top of p to bottom of p.
	int size;
	int index[2] = {0};//index[0] for p. index[1] for q.
};

void main()
{
	mystack test;
	test.push(7);
	test.push(5);
	test.push(6);
	test.push(1);
	cout << test.min() << endl;
	cout << test.top() << endl;
	cout << test.pop() << endl;
	cout << test.min() << endl;
	cout << test.top() << endl;
}
