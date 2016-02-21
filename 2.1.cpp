//Write code to remove duplicates from an unsorted linked list.
//
//FOLLOW UP
//
//How would you solve this problem if a temporary buffer is not allowed ?
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
void removedulicate(node *inpara)
{
	map<int, int> tempmap;
	while (inpara->next!=NULL)
	{
		/*cout << inpara->data;*/
		if (tempmap.find(inpara->data)==tempmap.end())
		{
			tempmap.insert(make_pair(inpara->data, inpara->data));
			inpara = inpara->next;
		}
		else
		{
			inpara->next= inpara->next->next;
		}

	}
}
void main()
{
	int a[] = { 0,2,2,2 };
	node *rr= init(a,4);
	removedulicate(rr);
}