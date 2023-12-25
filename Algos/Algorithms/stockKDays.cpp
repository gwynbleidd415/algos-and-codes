#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cout << "Enter the number of days known : ";
	cin >> n;
	cout << "Enter the number of days one can sell : ";
	cin >> k;
	cout << "Enter the stock prices for each day\n";
	int pr[n];
	for (int i = 0; i < n; ++i)
		cin >> pr[i];
	int arr[k + 1][n];
	for (int i = 0; i < n; ++i)
		arr[0][i] = 0;
	for (int i = 0; i <= k; ++i)
		arr[i][0] = 0;
	for (int i = 1; i <= k; ++i)
	{
		int maxdiff = -pr[0];
		for (int j = 1; j < n; ++j)
		{
			arr[i][j] = max(maxdiff + pr[j], arr[i][j - 1]);
			maxdiff = max(maxdiff, arr[i - 1][j] - pr[j]);
		}
	}
	cout << "Max Profit : " << arr[k][n - 1] << "\n";
	return 0;
}