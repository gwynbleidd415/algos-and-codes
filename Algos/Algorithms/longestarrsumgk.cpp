#include <bits/stdc++.h>
using namespace std;

bool cmpfunc(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int findMinInd(vector<pair<int, int>> v, int arr[], int n, int val)
{
	int s = 0, e = n - 1, m;
	while (s < e)
	{
		m = (s + e) / 2;
		if (val <= v[m].first)
			e = m;
		else
			s = m + 1;
	}
	if (arr[s] < val)
		return s;
	return -1;
}

int main()
{
	cout << "Enter the number of elements of array : ";
	int n;
	cin >> n;
	cout << "Enter the elements of the array\n";
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << "Enter the value of k : ";
	int k;
	cin >> k;
	vector<pair<int, int>> v;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		v.push_back({sum, i});
	}
	sort(v.begin(), v.end(), cmpfunc);
	int minind[n];
	minind[0] = v[0].second;
	for (int i = 1; i < n; ++i)
		minind[i] = min(minind[i - 1], v[i].second);
	sum = 0;
	int mlen = -1, ml;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
		if (sum >= k)
		{
			if (i + 1 > mlen)
			{
				mlen = i + 1;
				ml = 0;
			}
		}
		else
		{
			int ui = findMinInd(v, arr, n, sum - k);
			if (ui != -1 && minind[ui] < i && i - minind[ui] > mlen)
			{
				mlen = i - minind[ui];
				ml = minind[ui] + 1;
			}
		}
	}
	for (int i = ml; i < ml + mlen; ++i)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}