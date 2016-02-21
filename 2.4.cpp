//You have two numbers represented by a linked list, where each node contains a single digit.The digits are stored in reverse order, such that the 1’s digit is at the head of the list.Write a function that adds the two numbers and returns the sum as a linked list.
//
//EXAMPLE
//
//Input : (3 -> 1 -> 5), (5 -> 9 -> 2)
//
//Output : 8 -> 0 -> 8


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

void print(node *inpara)
{
	while (inpara->next!=NULL)
	{
		cout << "\t" << inpara->data;
		inpara = inpara->next;
	}
}

node* addlink(node *in1, node *in2)
{
	node *result = new node();
	node *finalresult = result;
	int over = 0;
	while (in1->next!=NULL || in2->next!=NULL)
	{
		result->data = in1->data + in2->data + over;
		if ((result->data)>=10)
		{
			over = static_cast<int>(result->data / 10);
			result->data -= 10;
		}
		else
		{
			over = 0;
		}
		if (in1->next!=NULL && in2->next!=NULL)
		{
			in1 = in1->next;
			in2 = in2->next;
		}
		else if (in1->next==NULL && in2->next!=NULL)
		{
			in2 = in2->next;
		}
		else if (in1->next!=NULL && in2->next==NULL)
		{
			in1 = in1->next;
		}
		result->next = new node();
		result = result->next;
	}
	return finalresult;
}
void main()
{
	int a[] = { 1,2,3};
	node *rr= init(a,3);
	int b[] = { 1,2,3};
	node *rr2 = init(b, 3);
	
	node *sss = addlink(rr, rr2);
	print(sss);
}
