/* You are given n lines which lie on the same axix. The starting and ending position of the lines are given. Find out minimum number of points such that each line has atleast one point.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number of lines : ";
	int n;
	cin >> n;
	cout << "Enter the starting and ending position of the lines\n";
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(b, a));
	}
	sort(arr.begin(), arr.end());
	int end = arr[0].first;
	int count = 1;
	vector<int> ans;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i].second > end)
			++count, ans.push_back(end), end = arr[i].first;
	}
	ans.push_back(end);
	cout << "Count : " << count << "\n";
	cout << "The order : ";
	for (auto itr : ans)
		cout << itr << " ";
	cout << "\n";
	return 0;
}
