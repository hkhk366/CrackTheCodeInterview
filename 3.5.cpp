//Implement a MyQueue class which implements a queue using two stacks.


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
		//cout << s1.size() << endl;
	}
	T pop()
	{
		if (s2.size()!=0)
		{
			T result = s2.top();
			s2.pop();
			return result;
		}
		else
		{
			int size = s1.size();
			for (int i = 0; i < size; ++i)
			{
				s2.push(s1.top());
				s1.pop();
			}
			T result = s2.top();
			s2.pop();
			return result;
		}

	}
};

void main()
{
	myQueue<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	cout << test.pop() << endl;
	cout << test.pop() << endl;
	cout << test.pop() << endl;
	test.push(4);
	test.push(5);
	cout << test.pop() << endl;
}