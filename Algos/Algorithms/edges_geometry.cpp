#include <bits/stdc++.h>
using namespace std;

int crossProd(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	int w, x, y, z;
	w = c.first - b.first;
	x = c.second - b.second;
	y = a.first - b.first;
	z = a.second - b.second;
	int val = w * z - x * y;
	if (val == 0)
		return 0;
	return (val < 0) ? 1 : 2;
}

bool maxDist(pair<int, int> c, pair<int, int> b, pair<int, int> a)
{
	return (((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second)) > (b.first - c.first) * (b.first - c.first) + (b.second - c.second) * (b.second - c.second));
}

int main()
{
	cout << "Enter the number of points : ";
	int n;
	cin >> n;
	vector<pair<int, int>> arr;
	cout << "Enter the points\n";
	int left = 0;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
		if (arr[left].first > a)
			left = i;
		else if (arr[left].first == a && arr[left].second > b)
			left = i;
	}
	swap(arr[0], arr[left]);
	// int x = 1;
	int ind = 1;
	for (int i = 2; i < n; ++i)
	{
		int x = crossProd(arr[ind], arr[0], arr[i]);
		if (x == 1)
			ind = i;
		else if (x == 0 && maxDist(arr[ind], arr[0], arr[i]))
			ind = i;
	}
	swap(arr[1], arr[ind]);
	int i;
	for (i = 1; i < n; ++i)
	{
		ind = 0;
		for (int j = i + 1; j < n; ++j)
		{
			int x = crossProd(arr[ind], arr[i], arr[j]);
			if (x == 1)
				ind = j;
			else if (x == 0 && maxDist(arr[ind], arr[i], arr[j]))
				ind = j;
		}
		if (ind == 0)
			break;
		else
			swap(arr[i + 1], arr[ind]);
	}
	for (int j = 0; j <= i; ++j)
		cout << arr[j].first << " , " << arr[j].second << "\n";
	return 0;
}

// 0 3
// 2 2
// 1 1
// 2 1
// 3 0
// 0 0
// 3 3