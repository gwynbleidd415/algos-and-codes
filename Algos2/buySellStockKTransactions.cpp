#include <iostream>
#include "myHeaders/stack.h"
using namespace std;

int main()
{
	cout << "Enter the number of days : ";
	int d;
	cin >> d;
	int pr[d];
	cout << "Enter the stock prices for each day\n";
	for (int i = 0; i < d; ++i)
		cin >> pr[i];
	cout << "Enter the maximum number of transactions : ";
	int k;
	cin >> k;
	pair<int, int> dp[k + 1][d];
	for (int i = 0; i <= k; ++i)
		dp[i][0] = {0, -1};
	for (int i = 0; i < d; ++i)
		dp[0][i] = {0, -1};
	for (int i = 1; i <= k; ++i)
	{
		int temp = -pr[0];
		int ind = 0;
		for (int j = 1; j < d; ++j)
		{
			dp[i][j].first = dp[i][j - 1].first;
			dp[i][j].second = -1;
			if (temp + pr[j] > dp[i][j].first)
			{
				dp[i][j].first = temp + pr[j];
				dp[i][j].second = ind;
			}
			if (temp < dp[i - 1][j].first - pr[j])
			{
				temp = dp[i - 1][j].first - pr[j];
				ind = j;
			}
		}
	}
	cout << "Maximum profit : " << dp[k][d - 1].first << "\n";
	stack<string> st;
	int x = k, y = d - 1;
	while (y >= 0)
	{
		if (dp[x][y].second == -1)
			--y;
		else
		{
			st.push("Sell on day : " + to_string(y));
			st.push("Purchase on day : " + to_string(dp[x][y].second));
			y = dp[x][y].second;
			--x;
		}
	}
	cout << "<======================SALES======================>\n";
	while (!st.empty())
	{
		cout << st.top() << "\n";
		st.pop();
	}
	// for (int i = 0; i <= k; ++i)
	// {
	// 	for (int j = 0; j < d; ++j)
	// 		cout << "{" << dp[i][j].first << ", " << dp[i][j].second << "}  ";
	// 	cout << "\n";
	// }
	return 0;
}

// 2 5 7 1 4 3 1 3