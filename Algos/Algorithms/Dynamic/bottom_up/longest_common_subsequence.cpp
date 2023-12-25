/* Given 2 strings find the longest common subsequence between them.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the two strings\n";
	string str1, str2;
	cin >> str1 >> str2;
	int n, m;
	n = str1.length(), m = str2.length();
	vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (str1[i - 1] == str2[j - 1])
				arr[i][j] = arr[i - 1][j - 1] + 1;
			else
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
	cout << "Ans : " << arr[n][m] << "\n";
	return 0;
}