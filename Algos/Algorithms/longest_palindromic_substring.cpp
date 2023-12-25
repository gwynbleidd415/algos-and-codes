#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the string : ";
	string str;
	cin >> str;
	int n = str.length();
	int arr[n] = {0};
	arr[0] = 1;
	int i = 0, j = 1, k = 2;
	while (j < n)
	{
		while (i >= 0 && k < n && str[i] == str[k])
			--i, ++k;
		arr[j] = k - i - 1;
		if (arr[j] == 1)
		{
			++j;
			i = j - 1;
			k = j + 1;
			// cout << j << "\n";
			continue;
		}
		else
		{
			int x = 1;
			int y = arr[j] / 2;
			while (x <= y)
			{
				if (j + x + arr[j - x] / 2 < k - 1)
					arr[j + x] = arr[j - x];
				else if (j + x + arr[j - x] / 2 > k - 1)
					arr[j + x] = 2 * (k - 1 - (j + x)) + 1;
				else
				{
					j = j + x;
					i = 2 * j - k;
					// cout << j << "\n";
					break;
				}
				++x;
			}
			if (y < x)
			{
				j = k - 1;
				i = j - 1;
				k = j + 1;
			}
		}
		// cout << j << "\n";
	}
	for (int x = 0; x < n; ++x)
		cout << arr[x] << "\t";
	cout << "\n";
	return 0;
}