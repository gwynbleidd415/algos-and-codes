/* Given a string, find the longest palindromic substring in it.*/

#include <bits/stdc++.h>
using namespace std;

int palindromic(string str, int n, int m, vector<vector<int>> arr)
{
	if (m < 0 || n > m)
		return 0;
	if (n == m)
		return 1;
	if (arr[n][m] == 0)
	{
		int val = palindromic(str, n + 1, m - 1, arr);
		if (str[n] == str[m] && val == m - n - 1)
			arr[n][m] = val + 2;
		else
			arr[n][m] = max(palindromic(str, n + 1, m, arr), palindromic(str, n, m - 1, arr));
	}
	return arr[n][m];
}

int main()
{
	cout << "Enter the string : ";
	string str;
	cin >> str;
	int n = str.length();
	vector<vector<int>> arr(n, vector<int>(n, 0));
	int ans = palindromic(str, 0, n - 1, arr);
	cout << "Ans : " << ans << "\n";
	return 0;
}