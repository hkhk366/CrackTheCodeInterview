//Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
//
//DEFINITION
//
//Circular linked list : A(corrupt) linked list in which a node’s next pointer points to an earlier node, so as to make a loop in the linked list.
//
//EXAMPLE
//
//Input : A->B->C->D->E->C[the same C as earlier]
//
//Output : C


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
node *loopStartPoint(node *inpara) 
{
	map<int, int> hash;
	while (inpara->next!=NULL)
	{
		if (hash.find(inpara->data)==hash.end())
		{
			hash.insert(make_pair(inpara->data,inpara->data));
		}
		else
		{
			return inpara;
		}
		inpara = inpara->next;
	}
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
	int a[] = { 1,2,3,4,3};
	node *rr= init(a,5);
	node *ss = loopStartPoint(rr);

}
