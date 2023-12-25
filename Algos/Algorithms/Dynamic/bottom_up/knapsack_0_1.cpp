/* You are given n items, their weights and their values and a knapsack of capacity c. Fill the items such that max value is obtained. The items cant be divided into parts.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number of items : ";
	int n;
	cin >> n;
	cout << "Enter the weight and values of the items\n";
	int arr[n][2] = {{0, 0}};
	for (int i = 0; i < n; ++i)
		cin >> arr[i][0] >> arr[i][1];
	cout << "Enter the capacity of the knapsack : ";
	int c;
	cin >> c;
	vector<vector<int>> ks(n + 1, vector<int>(c + 1, -1));
	for (int i = 0; i <= c; ++i)
		ks[0][i] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= c; ++j)
		{
			if (j - arr[i - 1][0] < 0)
				ks[i][j] = ks[i - 1][j];
			else
				ks[i][j] = max(ks[i - 1][j], ks[i - 1][j - arr[i - 1][0]] + arr[i - 1][1]);
		}
	}
	cout << "Ans : " << ks[n][c] << "\n";
	return 0;
}