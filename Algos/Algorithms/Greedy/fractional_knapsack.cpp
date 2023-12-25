/* Given are some items whose weight and values are mentioned. Maximum weight that can be selected is W. Choose the items such that their combined weight is less than or equal to W and their value is maximum. The items can be broken i.e. fractions of the items can be selected.*/

#include <bits/stdc++.h>
using namespace std;

bool cmpfunc(vector<double> a, vector<double> b)
{
	return (a[3] > b[3]);
}

int main()
{
	cout << "Enter the number of items\n";
	int n;
	cin >> n;
	cout << "Enter the amount available and their value\n";
	vector<vector<double>> knap(n, vector<double>(5, 0));
	for (int i = 0; i < n; ++i)
	{
		knap[i][0] = i + 1;
		cin >> knap[i][1] >> knap[i][2];
		knap[i][3] = knap[i][2] / knap[i][1];
	}
	cout << "Enter the weight\n";
	double w;
	cin >> w;
	double price = 0;
	sort(knap.begin(), knap.end(), cmpfunc);
	for (int i = 0; i < n; ++i)
	{
		if (knap[i][1] < w)
			knap[i][4] = knap[i][1], w -= knap[i][1], price += knap[i][2];
		else
		{
			knap[i][4] = w, price += w * knap[i][3];
			break;
		}
	}
	cout << "Price : " << price << "\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 5; ++j)
			cout << knap[i][j] << "\t";
		cout << "\n";
	}
	return 0;
}