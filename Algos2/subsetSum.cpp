#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the number of items : ";
	int n;
	cin >> n;
	int arr[n];
	cout << "Enter the items\n";
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << "Enter the sum : ";
	int s;
	cin >> s;
	int dp[n + 1][s + 1];
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= s; ++j)
			dp[i][j] = 0;
	for (int i = 0; i <= n; ++i)
		dp[i][0] = 1;
	// for (int i = 1; i <= n; ++i)
	// {
	// 	for (int j = 1; j <= s; ++j)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= s; ++j)
		{
			if (j >= arr[i - 1])
				dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	// for (int i = 0; i <= n; ++i)
	// {
	// 	for (int j = 0; j <= s; ++j)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }
	cout << "Number of subsets equal to sum : " << dp[n][s];
	return 0;
}