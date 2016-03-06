//Write an algorithm to find the ¡®next¡¯ node (i.e., in-order successor) of a given node in a binary search tree where each node has a link to its parent.
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <list>
using namespace std;

struct NODE
{
	int data;
	NODE *left;
	NODE *right;
	NODE *paraent;
};

void createTree(NODE *core, const int arr[], const int totalNum, int start, int end)
{
	if (start <= end)
	{
		int mid = (start + end) / 2;
		core->data = arr[mid];
		if (start <= mid - 1)
		{
			core->left = new NODE();
			(core->left)->paraent = core;
			createTree(core->left, arr, totalNum, start, mid - 1);
		}

		if (mid + 1 <= end)
		{
			core->right = new NODE();
			(core->right)->paraent = core;
			createTree(core->right, arr, totalNum, mid + 1, end);
		}
	}
}

int getHeight(NODE *core)
{
	if (core == NULL)
		return 0;
	int a = getHeight(core->left) + 1;
	int b = getHeight(core->right) + 1;
	return (a > b ? a : b);
}

NODE* findOneNode(NODE *core, int inpara)
{
	if (core->data == inpara) return core;
	else if (core->data > inpara)
	{
		findOneNode(core->left, inpara);
	}
	else if (core->data < inpara)
	{
		findOneNode(core->right, inpara);
	}
}

int getSuccessor(NODE *in)
{
	if (in->right)
	{
		NODE *p = in->right;
		while (p->left)
		{
			p = p->left;
		}
		return p->data;
	}
	else
	{
		NODE *p = in->paraent;
		while (p->data<in->data)
		{
			p = p->paraent;
		}
		return p->data;
	}
}
void main()
{
	int test[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	/*cout << sizeof(test) / 4;*/
	NODE *core = new NODE();
	createTree(core, test, sizeof(test) / 4, 0, sizeof(test) / 4 - 1);
	cout << findOneNode(core, 2) << endl;//print out one node's addresss
	cout << getSuccessor(findOneNode(core, 7)) << endl;
}