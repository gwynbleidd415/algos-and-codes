/* Given few coins use their minimum combination to pay your dues*/

#include <bits/stdc++.h>
using namespace std;

// class min_comb
// {
// 	vector<int> arr;

// public:
int calc_min(int coins[], int val, int e, int min_vals[])
{
	if (e < 0 || val < 0)
		return INT_MAX - 1;
	if (val == 0)
		return 0;
	if (min_vals[val] == 0)
	{
		int a = calc_min(coins, val - coins[e], e, min_vals) + 1;
		int b = calc_min(coins, val, e - 1, min_vals);
		min_vals[val] = min(a, b);
	}
	return min_vals[val];
}
// };

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
	int ans = calc_min(coins, val, n - 1, min_vals);
	cout << "Ans : " << ans << "\n";
	return 0;
}