/* Given 2 strings find the longest common subsequence between them.*/

#include <bits/stdc++.h>
using namespace std;

int subsequence(string str1, string str2, int n, int m, vector<vector<int>> arr)
{
	if (n > 0 && m > 0 && arr[n][m] == 0)
	{
		if (str1[n - 1] == str2[m - 1])
			arr[n][m] = subsequence(str1, str2, n - 1, m - 1, arr) + 1;
		else
			arr[n][m] = max(subsequence(str1, str2, n - 1, m, arr), subsequence(str1, str2, n, m - 1, arr));
	}
	return arr[n][m];
}

int main()
{
	cout << "Enter the two strings\n";
	string str1, str2;
	cin >> str1 >> str2;
	int n, m;
	n = str1.length(), m = str2.length();
	vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
	int ans = subsequence(str1, str2, n, m, arr);
	cout << "Ans : " << ans << "\n";
	return 0;
}