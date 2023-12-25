/* Given few coins use their minimum combination to pay your dues*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number of coins : ";
	int n;
	cin >> n;
	int coins[n];
	cout << "Enter the values of the coins\n";
	for (int i = 0; i < n; ++i)
		cin >> coins[i];
	cout << "Enter the value to give : ";
	int val;
	cin >> val;
	int min_vals[val + 1] = {0};
	for (int i = 0; i < n; ++i)
		if (coins[i] <= val)
			min_vals[coins[i]] = 1;
	for (int i = 1; i <= val; ++i)
	{
		int minn = INT_MAX;
		for (int j = 0; j < n; ++j)
			if (coins[j] <= i && (min_vals[i - coins[j]] + 1) < minn)
				minn = min_vals[i - coins[j]] + 1;
		min_vals[i] = minn;
	}
	int ans = min_vals[val];
	cout << "Ans : " << ans << "\n";
	return 0;
}