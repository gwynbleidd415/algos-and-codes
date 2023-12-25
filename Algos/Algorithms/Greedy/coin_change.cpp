/* Given are the coins 1,2,5,10,20,50,100,500,1000. You have unlimited supply of these coins. Now you have to pay someone amount x. Choose from these coins the amount x such that the total number of coins selected is minimum possible.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the amount\n";
	int amt;
	cin >> amt;
	int arr[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
	int cnt[9] = {0};
	int n = 9;
	int i = 0;
	int count = 0;
	while (amt > 0 && i < 9)
	{
		if (amt >= arr[i])
		{
			cnt[i] = amt / arr[i];
			count += cnt[i];
			amt = amt % arr[i];
		}
		++i;
	}
	cout << "Minimum number of coins : " << count << "\nCoins used :\n";
	for (int i = 0; i < 9; ++i)
		if (cnt[i] > 0)
			cout << arr[i] << "\t" << cnt[i] << "\n";
}