/* Convert one string to another only insertion deletion replacement of characters are allowed. Find minimum number of operations.*/

#include <bits/stdc++.h>
using namespace std;

int calc_ops(string str1, string str2, int *arr[], int n, int m)
{
	if (arr[n][m] == 0 && n > 0 && m > 0)
	{
		if (str1[n - 1] == str2[m - 1])
			arr[n][m] = calc_ops(str1, str2, arr, n - 1, m - 1);
		else
			arr[n][m] = min(calc_ops(str1, str2, arr, n - 1, m), min(calc_ops(str1, str2, arr, n, m - 1), calc_ops(str1, str2, arr, n - 1, m - 1))) + 1;
	}
	return arr[n][m];
}

int main()
{
	string str1, str2;
	cout << "Enter the two strings first the one to convert to\n";
	cin >> str1 >> str2;
	int n = str1.length();
	int m = str2.length();
	int *arr[n + 1];
	for (int i = 0; i <= n; ++i)
		arr[i] = new int[m + 1];
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			arr[i][j] = 0;
	for (int i = 0; i <= n; ++i)
		arr[i][0] = i;
	for (int i = 0; i <= m; ++i)
		arr[0][i] = i;
	int ans = calc_ops(str1, str2, arr, n, m);
	cout << ans << "\n";
	return 0;
}