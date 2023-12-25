/* Given a string, find the longest palindromic substring in it.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the string : ";
	string str;
	cin >> str;
	int n = str.length();
	vector<vector<int>> arr(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		arr[i][i] = 1;
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (str[i] == str[j] && arr[i + 1][j - 1] == j - i - 1)
				arr[i][j] = arr[i + 1][j - 1] + 2;
			else
				arr[i][j] = max(arr[i + 1][j], arr[i][j - 1]);
		}
	}
	cout << "Ans : " << arr[0][n - 1] << "\n";
	return 0;
}