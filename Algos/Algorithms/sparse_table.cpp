#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of elements of the array : ";
	cin >> n;
	int arr[n];
	cout << "Enter the elements of the array\n";
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int m = (int)log2(n) + 1;
	int mm = (int)pow(2, m);
	int mat[n][m];
	for (int i = 0; i < n; ++i)
		mat[i][0] = arr[i];
	int i = 0, j = 1, k = 2;
	while (k < mm)
	{
		i = 0;
		while (i + j < n)
		{
			mat[i][j] = min(mat[i][j - 1], mat[i + k / 2][j - 1]);
			++i;
		}
		++j;
		k *= 2;
	}
	int t = 1;
	while (t)
	{
		cout << "1.Find    2.Exit    : ";
		int wish;
		cin >> wish;
		if (wish == 1)
		{
			cout << "Enter the ranges : ";
			int a, b;
			cin >> a >> b;
			int x = (int)log2(b - a + 1);
			int ans = min(mat[a][x], mat[b - (int)pow(2, x) + 1][x]);
			cout << "Ans : " << ans << "\n";
		}
		else
			t = 0;
	}
	return 0;
}