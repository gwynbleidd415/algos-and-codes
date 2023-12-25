#include <iostream>
#include <string>
#include "./myHeaders/stack.h"
using namespace std;

int main()
{
	string str1, str2;
	cout << "Enter the string 1 : ";
	cin >> str1;
	cout << "Enter the string 2 : ";
	cin >> str2;
	int l1 = str1.length();
	int l2 = str2.length();
	int dp[l1 + 1][l2 + 1];
	for (int i = 0; i <= l1; ++i)
		for (int j = 0; j <= l2; ++j)
			dp[i][j] = 0;
	for (int i = 1; i <= l1; ++i)
		dp[i][0] = i;
	for (int j = 1; j <= l2; ++j)
		dp[0][j] = j;
	for (int i = 1; i <= l1; ++i)
		for (int j = 1; j <= l2; ++j)
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
	cout << "Minimum Operations : " << dp[l1][l2] << "\n";
	// for (int i = 0; i <= l1; ++i)
	// {
	// 	for (int j = 0; j <= l2; ++j)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }
	stack<string> st;
	int i = l1, j = l2, k = l1 - 1;
	while (i > 0 && j > 0)
	{
		if (str1[i - 1] == str2[j - 1])
			--i, --j, --k;
		else
		{
			if (dp[i][j] == dp[i - 1][j - 1] + 1)
			{
				st.push(string("Replace ") + str2[j - 1] + " at index " + to_string(k) + " with " + str1[i - 1]);
				--i, --j, --k;
			}
			else if (dp[i][j] == dp[i][j - 1] + 1)
			{
				st.push(string("Delete ") + str2[j - 1] + " at index " + to_string(k + 1));
				--j;
			}
			else
			{
				st.push(string("Insert ") + str1[i - 1] + " at index " + to_string(k));
				--i, --k;
			}
		}
	}
	while (j > 0)
	{
		st.push(string("Delete ") + str2[j - 1] + " at index " + to_string(k + 1));
		--j;
	}
	while (i > 0)
	{
		st.push(string("Insert ") + str1[i - 1] + " at index " + to_string(k));
		--i, --k;
	}
	while (!st.empty())
	{
		cout << st.top() << "\n";
		st.pop();
	}
	return 0;
}