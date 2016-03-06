//Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.
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

bool recuriveFind(NODE *in1,NODE *in2)
{
	if (in1==NULL) return false;
	if (in1 == in2) return true;
	else return recuriveFind(in1->left, in2) || recuriveFind(in1->right, in2);
}
int findSameAncestor(NODE *in1,NODE *in2)
{
	if (in1 == in2) return in1->data;
	else
	{
		while (in1->paraent)
		{
			if (recuriveFind(in1->paraent,in2))
			{
				return (in1->paraent)->data;
			}
			in1 = in1->paraent;
		}
	}
}
void main()
{
	int test[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	/*cout << sizeof(test) / 4;*/
	NODE *core = new NODE();
	createTree(core, test, sizeof(test) / 4, 0, sizeof(test) / 4 - 1);
	//cout << findOneNode(core, 2) << endl;//print out one node's addresss
	cout << findSameAncestor(findOneNode(core,2), findOneNode(core,6));
}