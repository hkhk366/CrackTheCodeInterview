//You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1
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

bool matchSubTree(NODE *core, NODE *core2)
{
	if (core == NULL && core2 == NULL)
		return true;
	else if (core == NULL && core2 != NULL)
		return false;
	else if (core!=NULL && core2 == NULL) 
		return true;
	else if (core->data != core2->data) 
		return false;
	else return matchSubTree(core->left, core2->left) && matchSubTree(core->right, core2->right);
}

bool findContainTree(NODE *core, NODE* core2)
{
	if (core == NULL) 
		return false;
	if (core2 == NULL) 
		return true;
	if (core->data==core2->data)
	{
		if (matchSubTree(core,core2))
		{
			return true;
		}
	}
	else
	{
		return 
			findContainTree(core->left, core2) 
			|| findContainTree(core->right, core2);
	}
}

void main()
{
	int test[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	int test2[] = { 0, 1, 2 };
	int test3[] = { 0, 2, 5 };
	NODE *core = new NODE();
	NODE *core2 = new NODE();
	NODE *core3 = new NODE();
	createTree(core, test, sizeof(test) / 4, 0, sizeof(test) / 4 - 1);
	createTree(core2, test2, sizeof(test2) / 4, 0, sizeof(test2) / 4 - 1);
	createTree(core3, test3, sizeof(test3) / 4, 0, sizeof(test3) / 4 - 1);
	cout << findContainTree(core, core2) << endl;
	cout << findContainTree(core, core3) << endl;
}