#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of coins : ";
	cin >> n;
	int val[n];
	cout << "Enter the values of the coins\n";
	for (int i = 0; i < n; ++i)
		cin >> val[i];
	int dp[n][n];
	int summ[n + 1];
	summ[0] = 0;
	for (int i = 1; i <= n; ++i)
		summ[i] = summ[i - 1] + val[i - 1];
	for (int i = 0; i < n; ++i)
		dp[i][i] = val[i];
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < n - i; ++j)
			dp[j][j + i] = summ[j + i + 1] - summ[j] - min(dp[j + 1][j + i], dp[j][j + i - 1]);
	cout << "Maximum value of coins : " << dp[0][n - 1] << "\n";
	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }
	int x = 0, y = n - 1;
	bool evn = true;
	while (x <= y)
	{
		int temp = summ[y + 1] - summ[x];
		if (temp - dp[x + 1][y] == dp[x][y])
		{
			if (evn)
				cout << "User chooses : " << x << "\n";
			else
				cout << "Opponent chooses : " << x << "\n";
			++x;
		}
		else
		{
			if (evn)
				cout << "User chooses : " << y << "\n";
			else
				cout << "Opponent chooses : " << y << "\n";
			--y;
		}
		evn = !(evn);
	}
	return 0;
}