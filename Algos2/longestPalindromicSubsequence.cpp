#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Enter the string : ";
	string str;
	cin >> str;
	int l = str.length();
	int dp[l][l];
	for (int i = 0; i < l; ++i)
		dp[i][i] = 1;
	for (int i = 1; i < l; ++i)
	{
		for (int j = 0; j < l - i; ++j)
		{
			if (str[j] == str[j + i])
			{
				if (i == 1)
					dp[j][j + i] = 2;
				else
					dp[j][j + i] = dp[j + 1][j + i - 1] + 2;
			}
			else
				dp[j][j + i] = max(dp[j][j + i - 1], dp[j + 1][j + i]);
		}
	}
	int n = dp[0][l - 1];
	cout << "Longest palindromic subsequence length : " << n << "\n";
	char arr[n];
	int x = 0, y = l - 1, z = 0;
	while (x <= y)
	{
		if (str[x] == str[y])
		{
			arr[z] = arr[n - z - 1] = str[x];
			++z, ++x, --y;
		}
		else
		{
			if (dp[x][y] == dp[x][y - 1])
				--y;
			else
				++x;
		}
	}
	cout << "The sequence : ";
	for (int i = 0; i < n; ++i)
		cout << arr[i];
	cout << "\n";
	return 0;
}