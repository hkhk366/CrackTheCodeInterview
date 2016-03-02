//Given a binary search tree, design an algorithm which creates a linked list of all the nodes at each depth (i.e., if you have a tree with depth D, you¡¯ll have D linked lists).
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

vector<list<NODE *>> findLink(NODE *core)
{
	int index = 0;
	vector<list<NODE *>> result;
	list<NODE *> temp;
	temp.push_back(core);
	result.push_back(temp);
	while (!result[index].empty())
	{
		list<NODE *> list;
		for (auto it = result[index].begin(); it != result[index].end(); ++it)
		{
			if (((NODE *)(*it))->left != NULL)
				list.push_back(((NODE *)(*it))->left);
			if (((NODE *)(*it))->right != NULL)
				list.push_back(((NODE *)(*it))->right);
		}
		++index;
		result.push_back(list);
	}
	result.pop_back();
	return result;
}
void printlink(vector<list<NODE *>> inpara)
{
	vector < list<NODE *> >::iterator it1;
	list<NODE *>::iterator it2;
	for (it1 = inpara.begin(); it1 != inpara.end(); ++it1)
	{
		for (it2 = it1->begin(); it2 != it1->end(); ++it2)
		{
			cout << "\t" << (int)((NODE *)(*it2)->data);
		}
		cout << endl;
	}
}
void main()
{
	int test[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	/*cout << sizeof(test) / 4;*/
	NODE *core = new NODE();
	int high = 0;
	createTree(core, test, sizeof(test) / 4, 0, sizeof(test) / 4 - 1, high);
	/*cout << getHeight(core) << endl;*/
	printlink(findLink(core));

}