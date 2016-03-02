//Implement a function to check if a tree is balanced. For the purposes of this question, a balanced tree is defined to be a tree such that no two leaf nodes differ in distance from the root by more than one.


#include<iostream>
using namespace std;
struct tree
{
	int data;
	tree *left;
	tree *right;
	int depth;
	tree()
	{
		this->left = NULL;
		this->right = NULL;
	}
};

void insert(tree *inTree, tree *inFather, int inInt, int inDepth, int inSignal)
{
	if (inTree == NULL)
	{
		tree *temp = new tree();
		if (inSignal == 1)
		{
			inFather->left = temp;
			temp->data = inInt;
			temp->depth = inDepth;
		}
		else if (inSignal == 2)
		{
			inFather->right = temp;
			temp->data = inInt;
			temp->depth = inDepth;
		}
		return;
	}
	if (inInt < inTree->data)
	{
		insert(inTree->left, inTree, inInt, inTree->depth + 1, 1);
	}
	else
	{
		insert(inTree->right, inTree, inInt, inTree->depth + 1, 2);
	}
}

void findMaxAndMin(tree *inTree, int &inMax, int &inMin)
{
	if (inTree->left==NULL && inTree->right==NULL)
	{
		if (inTree->depth<inMin)
		{
			inMin = inTree->depth;
		}
		if (inTree->depth>inMax)
		{
			inMax = inTree->depth;
		}
		return;
	}
	if (inTree->left!=NULL)
	{
		findMaxAndMin(inTree->left, inMax, inMin);
	}
	if (inTree->right!=NULL)
	{
		findMaxAndMin(inTree->right, inMax, inMin);
	}

}
bool isBalance(int inMax,int inMin)
{
	if (inMax-inMin>1)
	{
		return false;
	} 
	else
	{
		return true;
	}
}
void main()
{
	tree t;
	tree *op = &t;
	int test[] = { 5, 3, 8, 1, 4 };

	///////////////////////////////////////////////////////////////////
	t.data = test[0]; t.depth = 0;//write root information
	int defaultDepth = 0; 
	for (int i = 1; i < sizeof(test) / 4; ++i)
	{
		insert(op, op, test[i], defaultDepth, 0);
	}
	///////////////////////////////////////////////////////////////////Create the tree
	

	int max = INT_MIN; int min = INT_MAX;
	findMaxAndMin(op, max, min);
	cout << isBalance(max, min);

}