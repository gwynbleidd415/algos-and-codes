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
					dp[j][j + 1] = 2;
				else if (dp[j + 1][j + i - 1] == i - 1)
					dp[j][j + i] = i + 1;
				else
					dp[j][j + i] = max(dp[j][j + i - 1], dp[j + 1][j + i]);
			}
			else
				dp[j][j + i] = max(dp[j][j + i - 1], dp[j + 1][j + i]);
		}
	}
	cout << "Max Substr : " << dp[0][l - 1] << "\n";
	for (int i = 0; i <= l - dp[0][l - 1]; ++i)
	{
		if (dp[i][i + dp[0][l - 1] - 1] == dp[0][l - 1])
		{
			cout << i << " -> " << i + dp[0][l - 1] - 1 << "\n";
			break;
		}
	}
	return 0;
}