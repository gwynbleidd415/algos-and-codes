#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str, pat;
	cout << "Enter the string : ";
	cin >> str;
	cout << "Enter the pattern : ";
	cin >> pat;
	int l = str.length();
	int n = pat.length();
	bool dp[l + 1][n + 1];
	for (int i = 1; i <= l; ++i)
		dp[i][0] = false;
	int cc = 0, ii = n;
	for (int i = 1; i < n; i += 2)
	{
		if (pat[i] != '*')
		{
			ii = i;
			break;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (i & 1 || i > ii)
			dp[0][i] = false;
		else
			dp[0][i] = true;
	}
	dp[0][0] = true;
	for (int i = 1; i <= l; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (str[i - 1] == pat[j - 1] || pat[j - 1] == '.')
				dp[i][j] = dp[i - 1][j - 1];
			else if (pat[j - 1] == '*')
			{
				if (pat[j - 2] == str[i - 1] || pat[j - 2] == '.')
					dp[i][j] = (dp[i][j - 2] | dp[i - 1][j]);
				else
					dp[i][j] = dp[i][j - 2];
			}
			else
				dp[i][j] = false;
		}
	}
	cout << "Pattern " << (dp[l][n] ? "Matches" : "Dosent Match") << "\n";
	// for (int i = 0; i <= l; ++i)
	// {
	// 	for (int j = 0; j <= n; ++j)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }
	return 0;
}