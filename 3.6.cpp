//Write a program to sort a stack in ascending order. You should not make any assumptions about how the stack is implemented. The following are the only functions that should be used to write this program: push | pop | peek | isEmpty.


#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class myQueue
{
private:
	stack<T> s1;
	stack<T> s2;
public:
	void push(T inpara)
	{
		s1.push(inpara);
	}
	T pop()
	{
		T result = s1.top();
		s1.pop();
		return result;
	}
	bool isEmpty()
	{
		if (s1.empty() == true)
			return true;
		else
			return false;
	}
	stack<T> sort()
	{
		while (!s1.empty())
		{
			T data = s1.top();
			s1.pop();
			while (!s2.empty() && s2.top() > data)
			{
				s1.push(s2.top());
				s2.pop();
			}
			s2.push(data);
		}
		return s2;
	}

	
};

void main()
{
	myQueue<int> test;
	test.push(7);
	test.push(3);
	test.push(9);
	test.push(4);
	stack<int> ss = test.sort();
	int size = ss.size();
	for (int i = 0; i < size; ++i)
	{
		cout << ss.top();
		ss.pop();
	}

}