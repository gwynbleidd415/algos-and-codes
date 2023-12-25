#include <bits/stdc++.h>
using namespace std;

bool backQueen(int arr[], int n, int k)
{
	if (k == n)
		return true;
	int i = 0, j = 0;
	while (i < n)
	{
		while (j < k && i < n)
		{
			if (arr[j] == i || arr[j] - j == i - k || arr[j] + j == i + k)
			{
				++i;
				j = 0;
			}
			else
				++j;
		}
		if (i < n)
		{
			arr[k] = i;
			if (backQueen(arr, n, k + 1))
				return true;
			arr[k] = -1;
			++i;
		}
	}
	return false;
}

int main()
{
	cout << "Enter the number of queens : ";
	int n;
	cin >> n;
	int arr[n];
	if (backQueen(arr, n, 0))
	{
		cout << "Possible :\n";
		for (int i = 0; i < n; ++i)
			cout << i << " , " << arr[i] << "\n";
	}
	else
		cout << "Not Possible\n";
	return 0;
}