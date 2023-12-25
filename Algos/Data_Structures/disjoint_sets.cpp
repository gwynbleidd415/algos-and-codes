#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
	unordered_map<int, pair<int, int>> arr;

public:
	int find(int a)
	{
		if (arr.find(a) == arr.end())
			return INT_MIN;
		if (arr[a].first == a)
			return a;
		int p = arr[a].first;
		arr[a].first = find(p);
		if (arr[a].first != p)
			arr[p].second -= (arr[a].second + 1);
		return arr[a].first;
	}
	void makePair(int a, int p = INT_MIN)
	{
		if (p == INT_MIN)
		{
			arr.insert(make_pair(a, make_pair(a, 0)));
			return;
		}
		if (arr.find(p) == arr.end())
			makePair(p);
		int b = find(p);
		arr.insert(make_pair(a, make_pair(b, 0)));
		++(arr[b].second);
	}
	void unite(int a, int b)
	{
		if (arr.find(a) == arr.end() || arr.find(b) == arr.end())
			return;
		int c = find(a);
		int d = find(b);
		if (c == d)
			return;
		if (arr[c].second >= arr[d].second)
		{
			arr[d].first = c;
			arr[c].second += arr[d].second + 1;
		}
		else
		{
			arr[c].first = d;
			arr[d].second += arr[c].second + 1;
		}
	}
	void display()
	{
		for (auto itr : arr)
			cout << itr.first << "  " << itr.second.first << "  " << itr.second.second << "\n";
	}
};

int main()
{
	disjointSet d;
	int t = 1;
	while (t)
	{
		cout << "Choose.. \n1.Insert  2.Find  3.Merge  4.Display  5.Exit  : ";
		int wish;
		cin >> wish;
		int a;
		if (wish < 4)
		{
			cout << "Enter the number : ";
			cin >> a;
		}
		switch (wish)
		{
		case 1:
			d.makePair(a);
			break;
		case 2:
			cout << d.find(a) << "\n";
			break;
		case 3:
		{
			cout << "Enter the other number : ";
			int b;
			cin >> b;
			d.unite(a, b);
		}
		break;
		case 4:
			d.display();
			break;
		default:
			t = 0;
		}
	}
	return 0;
}