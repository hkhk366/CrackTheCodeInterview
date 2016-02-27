//Imagine a(literal) stack of plates.If the stack gets too high, it might topple.Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.Implement a data structure SetOfStacks that mimics this.SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity.SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack(that is, pop() should return the same values as it would if there were just a single stack).
//
//FOLLOW UP
//
//Implement a function popAt(int index) which performs a pop operation on a specific sub - stack.


#include <iostream>
#include <string>
#include <map>
using namespace std;

class setOfStack
{
private:
	int *data;
	setOfStack *next;
	setOfStack *prev;
	setOfStack *curr;
public:
	setOfStack()
	{
		this->data = new int;
		this->next = NULL;
		this->prev = NULL;
		this->curr = this;
	}
	~setOfStack()
	{
		delete this->data;
		delete this->next;
		delete this->prev;
	}
	void push(int inpara)
	{
		*curr->data = inpara;
		setOfStack *p=new setOfStack();
		curr->next = p;
		p->prev = curr;
		this->curr = p;
	}
	int pop()
	{
		int result = *curr->prev->data;
		curr->prev->next = NULL;
		curr = curr->prev;
		return result;
	}
	int popat(int inpara)
	{
		setOfStack *index = this;
		for (int i = 0; i < inpara - 1; ++i)
		{
			index = index->next;
		}
		if (index->prev!=NULL)
		{
			index->prev->next = index->next;
		}

		if (index->next!=NULL)
		{
			index->next->prev = index->prev;
		}

		return *index->data;
	}
};


void main()
{
	setOfStack test;
	test.push(3);
	test.push(6);
	test.push(8);
	cout << test.pop() << endl;
	cout << test.pop() << endl;
	cout << test.pop() << endl;
	test.push(2);
	test.push(1);
	cout << test.pop() << endl;
	cout << test.pop() << endl;
	test.push(5);
	test.push(4);
	test.push(3);
	test.push(2);
	test.push(1);
	cout << test.popat(3) << endl;
	cout << test.popat(3) << endl;
}