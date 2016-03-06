//You are given a binary tree in which each node contains a value. Design an algorithm to print all paths which sum up to that value. Note that it can be any path in the tree - it does not have to start at the root.
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

void findSumPath(NODE *core, const int objectNum)
{
	if (core == NULL) return;
	NODE *op = core; 
	int temp=0;
	int index = 0;
	while (op!=NULL)
	{
		temp += op->data;
		if (temp==objectNum)
		{
			NODE *tmp = core;
			for (int i = 0; i <= index; ++i)
			{
				cout << "\t" << tmp->data;
				tmp = tmp->paraent;
			}
			cout << endl;
		}
		op = op->paraent;
		++index;
	}
	findSumPath(core->left, objectNum);
	findSumPath(core->right, objectNum);
}

void main()
{
	int test[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	NODE *core = new NODE();
	createTree(core, test, sizeof(test) / 4, 0, sizeof(test) / 4 - 1);
	findSumPath(core, 5);
}