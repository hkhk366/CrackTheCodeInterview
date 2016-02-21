//Implement an algorithm to find the nth to last element of a singly linked list.
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct node
{
	int data = 0;
	node *next=NULL;
}node1;

node* init(int a[], int len)
{
	node *result = new node();
	node *returnresult = result;
	for (int i = 0; i < len; ++i)
	{
		result->data = a[i];
		result->next = new node();
		result = result->next;
	}
	return returnresult;
}
void findNthToLast(node* inpara, int object)
{
	static int deep = 0;
	if (inpara->next != NULL)
	{
		findNthToLast(inpara->next, object);
		++deep;
	}
	if (deep==object)
	{
		cout << inpara->data;
	}
	
}
void main()
{
	int a[] = { 0,1,2,3 };
	node *rr= init(a,4);
	findNthToLast(rr, 2);
}
