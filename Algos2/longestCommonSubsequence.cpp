#include <iostream>
#include <string>
using namespace std;

struct flist
{
	char ch;
	flist *next;
};

int main()
{
	string str1, str2;
	cout << "Enter the first string : ";
	cin >> str1;
	cout << "Enter the second string : ";
	cin >> str2;
	int l1 = str1.length();
	int l2 = str2.length();
	int dp[l1 + 1][l2 + 1];
	for (int i = 0; i <= l1; ++i)
		for (int j = 0; j <= l2; ++j)
			dp[i][j] = 0;
	for (int i = 1; i <= l1; ++i)
		for (int j = 1; j <= l2; ++j)
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
	cout << "Length of longest subsequence : " << dp[l1][l2] << "\n";
	flist *str = NULL;
	int i = l1, j = l2;
	while (i > 0 && j > 0)
	{
		if (str1[i - 1] == str2[j - 1])
		{
			flist *temp = new flist();
			temp->ch = str1[i - 1];
			temp->next = str;
			str = temp;
			--i, --j;
		}
		else
		{
			if (dp[i][j] == dp[i][j - 1])
				--j;
			else
				--i;
		}
	}
	while (str != NULL)
	{
		cout << str->ch;
		str = str->next;
	}
	cout << "\n";
	return 0;
}