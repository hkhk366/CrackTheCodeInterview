//Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height.
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct NODE
{
	int data;
	NODE *left;
	NODE *right;
};

void createTree(NODE *core, const int arr[], const int totalNum, int start, int end, int totalHeight)
{
	if (start <= end)
	{
		int mid = (start + end) / 2;
		core->data = arr[mid];
		if (start <= mid - 1)
		{
			core->left = new NODE();
			createTree(core->left, arr, totalNum, start, mid - 1, totalHeight);
		}

		if (mid + 1 <= end)
		{
			core->right = new NODE();
			createTree(core->right, arr, totalNum, mid + 1, end, totalHeight);
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
void main()
{
	int test[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	/*cout << sizeof(test) / 4;*/
	NODE *core=new NODE();
	int high = 0;
	createTree(core, test, sizeof(test) / 4, 0, sizeof(test) / 4 - 1, high);
	cout << getHeight(core);
}