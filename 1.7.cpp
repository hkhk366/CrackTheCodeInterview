//Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.


#include <iostream>
#include <string>
using namespace std;

void zero(int **a, int m, int n)
{
	bool row[5], col[5];
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] == 0) {
				row[i] = true;
				col[j] = true;
			}
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (row[i] || col[j])
				a[i][j] = 0;
}

int main()
{
	int a = 3; int c = 5;
	int *p;
	p = &a;
	p = &c;
	return 0;
}