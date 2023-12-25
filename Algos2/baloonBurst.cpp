#include <iostream>
// #include "myHeaders/stack.h"
using namespace std;

void printOrder(pair<int, int> **dp, int x, int y)
{
	if (x > y)
		return;
	printOrder(dp, x, dp[x][y].second - 1);
	printOrder(dp, dp[x][y].second + 1, y);
	cout << "Burst Baloon : " << dp[x][y].second << "\n";
}

int main()
{
	cout << "Enter the number of baloons : ";
	int n;
	cin >> n;
	int val[n + 2];
	val[0] = val[n + 1] = 1;
	cout << "Enter the value of each baloon\n";
	for (int i = 1; i <= n; ++i)
		cin >> val[i];
	// pair<int, int> dp[n][n];
	pair<int, int> **dp;
	dp = new pair<int, int> *[n];
	for (int i = 0; i < n; ++i)
		dp[i] = new pair<int, int>[n];
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 		cout << dp[i][j].first << " ";
	// 	cout << "\n";
	// }
	for (int i = 0; i < n; ++i)
		dp[i][i] = {val[i] * val[i + 1] * val[i + 2], i};
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n - i; ++j)
		{
			int mult = val[j] * val[j + i + 2];
			int maxx = val[j + 1] * mult + dp[j + 1][j + i].first, ml = j;
			int temp = val[j + i + 1] * mult + dp[j][j + i - 1].first;
			if (temp > maxx)
			{
				maxx = temp;
				ml = j + i;
			}
			for (int k = j + 1; k < j + i; ++k)
			{
				temp = dp[k + 1][j + i].first + dp[j][k - 1].first + mult * val[k + 1];
				if (temp > maxx)
				{
					maxx = temp;
					ml = k;
				}
			}
			dp[j][j + i] = {maxx, ml};
		}
	}
	// stack<int> st;
	cout << "Best Score : " << dp[0][n - 1].first << "\n";
	printOrder(dp, 0, n - 1);
	// int x = 0, y = n - 1;
	// while (x <= y)
	// {
	// 	// st.push(dp[x][y].second);
	// }
	return 0;
}