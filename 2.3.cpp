//Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
//
//EXAMPLE
//
//Input : the node ‘c’ from the linked list a->b->c->d->e Result : nothing is returned, but the new linked list looks like a->b->d->e
//


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
void remove(node *inpara, int object)
{
	for (int i = 0; i < object-1; ++i)
	{
		inpara = inpara->next;
	}
	node *temp = inpara->next;
	inpara->next = inpara->next->next;
	delete temp;
}
void print(node *inpara)
{
	while (inpara->next!=NULL)
	{
		cout << "\t" << inpara->data;
		inpara = inpara->next;
	}
}
void main()
{
	int a[] = { 0,1,2,3 };
	node *rr= init(a,4);
	//findNthToLast(rr, 2);
	remove(rr, 2);
	cout << endl;
	print(rr);
}
