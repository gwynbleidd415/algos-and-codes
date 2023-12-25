#include <bits/stdc++.h>
using namespace std;

int findind(int lm[], int len, int ele)
{
	int s = 0;
	int e = len;
	while (s < e)
	{
		int m = (s + e) / 2;
		if (lm[m] >= ele)
			e = m - 1;
		else
			s = m + 1;
	}
	if (lm[s] >= ele)
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
	lm[0] = arr[0];
	int len = 0;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > lm[len])
		{
			++len;
			lm[len] = arr[i];
		}
		else
			lm[findind(lm, len, arr[i])] = arr[i];
	}
	cout << len + 1 << "\n";
	return 0;
}