/* Find the minimum cost to reach the end of a 2-D array. Only traversal in right and down is allowed and the cost of each block is given*/

#include <bits/stdc++.h>
using namespace std;

int find_cost(vector<vector<int>> arr, int r, int c, vector<vector<int>> cost)
{
	// if (r < 0 || c < 0)
	// 	return 0;
	// if (cost[r][c] == 0)
	// 	if (r == 0)
	// 		cost[r][c] = find_cost(arr, r, c - 1, cost) + arr[r][c];
	// 	else if (c == 0)
	// 		cost[r][c] = find_cost(arr, r - 1, c, cost) + arr[r][c];
	// 	else
	// 		cost[r][c] = arr[r][c] + min(find_cost(arr, r - 1, c, cost), find_cost(arr, r, c - 1, cost));
	// return cost[r][c];
	if (r < 0 || c < 0)
		return INT_MAX;
	if (cost[r][c] == -1)
		cost[r][c] = arr[r][c] + min(find_cost(arr, r - 1, c, cost), find_cost(arr, r, c - 1, cost));
	return cost[r][c];
}

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
	int ans = find_cost(arr, r - 1, c - 1, cost);
	cout << "Ans : " << ans << "\n";
	return 0;
}