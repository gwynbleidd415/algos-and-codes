#include <iostream>
using namespace std;

int main()
{
	string str1, str2, str3;
	cout << "Enter the string 1 : ";
	cin >> str1;
	cout << "Enter the string 2 : ";
	cin >> str2;
	cout << "Enter the string 3 : ";
	cin >> str3;
	int n = str1.length(), m = str2.length(), o = str3.length();
	if (o != n + m)
		cout << "False\n";
	else
	{
		bool dp[n + 1][m + 1];
		dp[0][0] = true;
		for (int i = 1; i <= m; ++i)
			if (dp[0][i - 1] == true && str3[i - 1] == str2[i - 1])
				dp[0][i] = true;
			else
				dp[0][i] = false;
		for (int i = 1; i <= n; ++i)
			if (dp[i - 1][0] == true && str3[i - 1] == str1[i - 1])
				dp[i][0] = true;
			else
				dp[i][0] = false;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (dp[i][j - 1] == true && str3[i + j - 1] == str2[j - 1])
					dp[i][j] = true;
				else if (dp[i - 1][j] == true && str3[i + j - 1] == str1[i - 1])
					dp[i][j] = true;
				else
					dp[i][j] = false;
			}
		}
		cout << (dp[n][m] == true ? "True" : "False") << "\n";
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= m; ++j)
				cout << dp[i][j] << "  ";
			cout << "\n";
		}
	}
}