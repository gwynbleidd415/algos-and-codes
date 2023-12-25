/* Help a thief in stealing. There are n houses in a line and the value of loot in them are given. The thief cant steal from two adjacent houses. Choose the houses he must steal from to maximize the profit.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of houses : ";
	cin >> n;
	cout << "Enter the values of the houses\n";
	int hv[n];
	for (int i = 0; i < n; ++i)
		cin >> hv[i];
	int sh[n] = {0};
	sh[0] = hv[0];
	sh[1] = max(hv[0], hv[1]);
	for (int i = 2; i < n; ++i)
		sh[i] = max(sh[i - 2] + hv[i], sh[i - 1]);
	cout << "Max profit : " << sh[n - 1] << "\n";
	return 0;
}