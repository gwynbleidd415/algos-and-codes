#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number of elements : ";
	int n;
	cin >> n;
	bitset<1000000> sb;
	for (int i = 2; i <= n; ++i)
	{
		if (sb[i] == 0)
		{
			int j = 2;
			while (i * j <= n)
				sb[i * j] = 1, ++j;
		}
	}
	for (int i = 2; i <= n; ++i)
		if (sb[i] == 0)
			cout << i << " ";
	cout << "\n";
	return 0;
}