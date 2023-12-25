#include <bits/stdc++.h>
using namespace std;

int findind(int arr[], int lm[], int len, int i)
{
	int s = 0;
	int e = len;
	while (s < e)
	{
		int m = (s + e) / 2;
		if (arr[lm[m]] >= arr[i])
			e = m - 1;
		else
			s = m + 1;
	}
	if (e < 0)
		e = 0;
	if (arr[lm[s]] >= arr[i])
		return s;
	else
		return s + 1;
}

int main()
{
	cout << "Enter the number of elements : ";
	int n;
	cin >> n;
	int arr[n];
	cout << "Enter the elements\n";
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int lm[n];
	lm[0] = 0;
	int len = 0;
	int str[n];
	str[0] = -1;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > arr[lm[len]])
		{
			// cout << i << '\n';
			++len;
			lm[len] = i;
		}
		else if (arr[i] < arr[lm[0]])
			lm[0] = i;
		else
			lm[findind(arr, lm, len, i)] = i;
		cout << arr[lm[len]] << "\n";
	}
	cout << len + 1 << "\n";
	return 0;
}