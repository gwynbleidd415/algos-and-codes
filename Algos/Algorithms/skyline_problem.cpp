#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int x, y;
	bool t;
};

bool cmpfunc(edge a, edge b)
{
	if (a.x < b.x)
		return true;
	if (a.x == b.x)
	{
		if (a.y < b.y)
		{
			if (a.t == false && b.t == false)
				return true;
		}
		if (a.y >= b.y)
		{
			if (a.t == true && b.t == true)
				return true;
			if (a.t == true && b.t == false)
				return true;
		}
	}
	return false;
}

int main()
{
	cout << "Enter the number of buildings : ";
	int n;
	cin >> n;
	edge arr[n * 2];
	cout << "Enter the starting, ending and height of the buildings\n";
	for (int i = 0; i < n; ++i)
	{
		int s, e, h;
		cin >> s >> e >> h;
		arr[i * 2].x = s;
		arr[i * 2].y = h;
		arr[i * 2].t = true;
		arr[i * 2 + 1].x = e;
		arr[i * 2 + 1].y = h;
		arr[i * 2 + 1].t = false;
	}
	sort(arr, arr + n * 2, cmpfunc);
	map<int, int> hp;
	map<int, int>::iterator it;
	hp.insert(pair<int, int>(0, 10000));
	for (int i = 0; i < 2 * n; ++i)
	{
		int maxx = hp.rbegin()->first;
		it = hp.find(arr[i].y);
		if (arr[i].t == true)
		{
			if (it == hp.end())
				hp.insert(pair<int, int>(arr[i].y, 1));
			else
				it->second += 1;
		}
		else
		{
			if (it->second == 1)
				hp.erase(it);
			else
				it->second -= 1;
		}
		if (maxx != hp.rbegin()->first)
			cout << arr[i].x << " , " << max(hp.rbegin()->first, arr[i].y) << "\n";
	}
	return 0;
}

// 1 5 11
// 2 7 6
// 3 9 13
// 12 16 7
// 14 25 3
// 19 22 18
// 23 29 13
// 24 28 4