/* Find the minimum cost to reach the end of a 2-D array. Only traversal in right and down is allowed and the cost of each block is given*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number of rows and columns in the array\n";
	int r, c;
	cin >> r >> c;
	vector<vector<int>> arr(r, vector<int>(c, 0));
	cout << "Enter the elements of the array in row wise\n";
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> arr[i][j];
	vector<vector<int>> cost(r, vector<int>(c, -1));
	cost[0][0] = arr[0][0];
	for (int i = 1; i < c; ++i)
		cost[0][i] = cost[0][i - 1] + arr[0][i];
	for (int i = 1; i < r; ++i)
		cost[i][0] = cost[i - 1][0] + arr[i][0];
	for (int i = 1; i < r; ++i)
		for (int j = 1; j < c; ++j)
			cost[i][j] = min(cost[i - 1][j], cost[i][j - 1]) + arr[i][j];
	cout << "Ans : " << cost[r - 1][c - 1] << "\n";
	return 0;
}