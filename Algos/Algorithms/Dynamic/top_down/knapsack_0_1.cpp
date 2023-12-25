/* You are given n items, their weights and their values and a knapsack of capacity c. Fill the items such that max value is obtained. The items cant be divided into parts.*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<vector<int>> ks, vector<vector<int>> arr, int n, int c)
{
	if (n > 0 && c >= 0 && ks[n][c] == -1)
	{
		if (c - arr[n - 1][0] < 0)
			ks[n][c] = knapsack(ks, arr, n - 1, c);
		else
			ks[n][c] = max(knapsack(ks, arr, n - 1, c), knapsack(ks, arr, n - 1, c - arr[n - 1][0]) + arr[n - 1][1]);
	}
	return ks[n][c];
}

int main()
{
	cout << "Enter the number of items : ";
	int n;
	cin >> n;
	cout << "Enter the weight and values of the items\n";
	vector<vector<int>> arr(n, vector<int>(2, 0));
	for (int i = 0; i < n; ++i)
		cin >> arr[i][0] >> arr[i][1];
	cout << "Enter the capacity of the knapsack : ";
	int c;
	cin >> c;
	vector<vector<int>> ks(n + 1, vector<int>(c + 1, -1));
	for (int i = 0; i <= c; ++i)
		ks[0][i] = 0;
	int ans = knapsack(ks, arr, n, c);
	cout << "Ans : " << ans << "\n";
	return 0;
}
