/* Convert one string to another only insertion deletion replacement of characters are allowed. Find minimum number of operations.*/

#include <bits/stdc++.h>
using namespace std;

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
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (str1[i - 1] == str2[j - 1])
				arr[i][j] = arr[i - 1][j - 1];
			else
				arr[i][j] = min(arr[i - 1][j], min(arr[i - 1][j - 1], arr[i][j - 1])) + 1;
	cout << "Ans : " << arr[n][m] << "\n";
	return 0;
}