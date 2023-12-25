#include <iostream>
#include "myHeaders/stack.h"
using namespace std;

struct sWords
{
	string word;
	int l;
};

int main()
{
	cout << "Enter the string : ";
	string str;
	getline(cin, str);
	cout << "Enter the max number of characters : ";
	int mc;
	cin >> mc;
	int n = 1;
	for (int i = 0; i < str.length(); ++i)
		if (str[i] == ' ')
			++n;
	sWords words[n];
	int i = 0, j = 1, k = 0;
	for (j = 0; j < str.length(); ++j)
		if (str[j] == ' ')
		{
			words[k].word = str.substr(i, j - i);
			words[k].l = j - i;
			++k, i = j + 1;
		}
	words[k].word = str.substr(i, j - i);
	words[k].l = j - i;
	pair<unsigned int, unsigned int> dp[n][n];
	for (i = 0; i < n; ++i)
		dp[i][i] = {(mc - words[i].l) * (mc - words[i].l), words[i].l};
	for (i = 1; i < n; ++i)
		for (j = 0; j < n - i; ++j)
		{
			dp[j][j + i].second = dp[j][j + i - 1].second + words[j + i].l + 1;
			if (dp[j][j + i].second <= mc)
				dp[j][j + i].first = (mc - dp[j][j + i].second) * (mc - dp[j][j + i].second);
			else
				dp[j][j + i].first = INT32_MAX;
		}
	pair<int, int> btj[n + 1];
	btj[0] = {0, -1};
	for (i = 0; i < n; ++i)
	{
		btj[i + 1].first = dp[i][i].first + btj[i].first;
		btj[i + 1].second = i;
		for (j = i - 1; j >= 0; --j)
		{
			unsigned int temp = dp[j][i].first + btj[j].first;
			if (temp < btj[i + 1].first)
			{
				btj[i + 1].first = temp;
				btj[i + 1].second = j;
			}
		}
	}
	stack<int> st;
	int x = n - 1;
	while (x != -1)
	{
		st.push(x);
		x = btj[x + 1].second - 1;
	}
	while (!st.empty())
	{
		int t = st.top();
		for (i = btj[t + 1].second; i <= t; ++i)
			cout << words[i].word << " ";
		cout << "\n";
		st.pop();
	}
	// for (i = 0; i <= n; ++i)
	// 	cout << btj[i].first << " " << btj[i].second << "\n";
	// for (i = 0; i < n; ++i)
	// {
	// 	for (j = 0; j < n; ++j)
	// 		cout << dp[i][j].first << " ";
	// 	cout << "\n";
	// }
}