//Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
#include <iostream>
#include <queue>
using namespace std;

#define NODENUM 5;

bool BFSsearch(int inG[5][5], int inV[], int inStartPoint, int inEndPoint)
{
	queue<int> core;
	core.push(inStartPoint);
	inV[inStartPoint] = 1;
	while (!core.empty())
	{
		int temp = core.front();
		core.pop();
		for (int i = 0; i < 5; ++i)
		{
			if (inG[temp][i] != 0 && inV[i] == 0)
			{
				core.push(i);
				if (i == inEndPoint)
				{
					return true;
				}

			}
		}
	}
	return false;
}


void main()
{
	int visited[5] = { 0 };
	int graph[5][5] =
	{
		{ 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0 },
	};
	int starpoint = 2; int endpoint = 4;
	cout << BFSsearch(graph, visited, starpoint, endpoint);
}
