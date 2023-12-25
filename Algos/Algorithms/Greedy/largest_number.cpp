/* Compose the largest number out of a set of given integers*/

#include <bits/stdc++.h>
using namespace std;

// void display(vector<vector<int>> arr)
// {
// 	for (auto itr : arr)
// 	{
// 		for (auto i : itr)
// 		{
// 			cout << i << "  ";
// 		}
// 		cout << "\n";
// 	}
// }

int find_sv(int num, int mc)
{
	int c = 0, r = num;
	while (r != 0)
		r /= 10, ++c;
	if (c == mc)
		return num;
	int res = num * (int)pow(10, mc - c);
	int dc = c;
	while (mc != dc)
		if (mc - dc >= c)
		{
			res += num * (int)pow(10, mc - dc - c);
			dc += c;
		}
		else
		{
			res += num / (int)pow(10, c - (mc - dc));
			dc = mc;
		}
	return res;
}

bool cmp_func(vector<int> a, vector<int> b)
{
	return a[1] > b[1];
}

int main()
{
	cout << "Enter the number of elements : ";
	int n;
	cin >> n;
	cout << "Enter the elements\n";
	vector<vector<int>> arr(n, vector<int>(2));
	int maxx = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i][0];
		if (arr[i][0] > maxx)
			maxx = arr[i][0];
	}
	int mc = 0;
	while (maxx != 0)
		maxx /= 10, ++mc;
	for (int i = 0; i < n; ++i)
		arr[i][1] = find_sv(arr[i][0], mc);
	sort(arr.begin(), arr.end(), cmp_func);
	for (int i = 0; i < n; ++i)
		cout << arr[i][0];
	cout << "\n";
	for (int i = 0; i < n; ++i)
		cout << arr[i][0] << " ";
	cout << "\n";
	return 0;
}