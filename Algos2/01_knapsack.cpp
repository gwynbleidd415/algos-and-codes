#include <iostream>
using namespace std;

struct items
{
	int i, wt, val;
};

int main()
{
	cout << "Enter the number of elements : ";
	int n;
	cin >> n;
	cout << "Enter the elements weights and values\n";
	items arr[n];
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		arr[i].i = i + 1;
		arr[i].wt = a;
		arr[i].val = b;
	}
	cout << "Enter the capacity of the knapsack : ";
	int c;
	cin >> c;
	int dp[n + 1][c + 1];
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= c; ++j)
			dp[i][j] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			if (j >= arr[i - 1].wt)
				dp[i][j] = max(arr[i - 1].val + dp[i - 1][j - arr[i - 1].wt], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << "<=======================Items=======================>\n";
	for (int i = 0; i < n; ++i)
		cout << arr[i].i << "\t" << arr[i].wt << "\t" << arr[i].val << "\n";
	cout << "\nMax Profit : " << dp[n][c] << "\n";
	return 0;
}