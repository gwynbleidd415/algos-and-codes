/* Given a strings find the longest palindromic subsequence in it.*/

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
		if (str[n] == str[m])
			arr[n][m] = palindromic(str, n + 1, m - 1, arr) + 2;
		else
			arr[n][m] = max(palindromic(str, n + 1, m, arr), palindromic(str, n, m - 1, arr));
	}
	return arr[n][m];
}

int main()
{
	cout << "Enter the strings : ";
	string str;
	cin >> str;
	int n = str.length();
	vector<vector<int>> arr(n, vector<int>(n, 0));
	int ans = palindromic(str, 0, n - 1, arr);
	cout << "Ans : " << ans << "\n";
	return 0;
}