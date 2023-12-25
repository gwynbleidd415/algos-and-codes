#include <bits/stdc++.h>
using namespace std;

class segment
{
	vector<int> v;
	int n;

public:
	segment(int arr[], int n)
	{
		v = vector<int>(4 * n, 0);
		this->n = n;
		buildSegment(arr, 0, 0, n - 1);
	}

private:
	void buildSegment(int arr[], int i, int s, int e)
	{
		if (s == e)
			v[i] = arr[s];
		else
		{
			int m = (s + e) / 2;
			buildSegment(arr, i * 2 + 1, s, m);
			buildSegment(arr, i * 2 + 2, m + 1, e);
			v[i] = v[i * 2 + 1] + v[i * 2 + 2];
		}
	}

public:
	int findSum(int s, int e, int i = 0, int si = 0, int ei = -1)
	{
		if (ei == -1)
			ei = n - 1;
		if (s == si && ei == e)
			return v[i];
		int m = (si + ei) / 2;
		if (e <= m)
			return findSum(s, e, i * 2 + 1, si, m);
		if (s > m)
			return findSum(s, e, i * 2 + 2, m + 1, ei);
		return findSum(s, m, i * 2 + 1, si, m) + findSum(m + 1, e, i * 2 + 2, m + 1, ei);
	}
	void updateSegment(int p, int val, int i = 0, int si = 0, int ei = -1)
	{
		if (ei == -1)
			ei = n - 1;
		if (ei == si)
			v[i] += val;
		else
		{
			int m = (si + ei) / 2;
			if (p <= m)
				updateSegment(p, val, i * 2 + 1, si, m);
			else
				updateSegment(p, val, i * 2 + 2, m + 1, ei);
			v[i] = v[i * 2 + 1] + v[i * 2 + 2];
		}
	}
	void display()
	{
		for (auto itr : v)
			cout << itr << " ";
		cout << "\n";
	}
};

int main()
{
	cout << "Enter the number of elements : ";
	int n;
	cin >> n;
	cout << "Enter the elements\n";
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	segment s(arr, n);
	int t = 1;
	while (t)
	{
		cout << "Choose..\n1.SUM  2.UPDATE  3.DISPLAY  4.EXIT  : ";
		int wish;
		cin >> wish;
		switch (wish)
		{
		case 1:
		{
			cout << "Enter the range : ";
			int a, b;
			cin >> a >> b;
			cout << s.findSum(a, b) << "\n";
		}
		break;
		case 2:
		{
			cout << "Enter the position and value : ";
			int p, v;
			cin >> p >> v;
			s.updateSegment(p, v);
		}
		break;
		case 3:
			s.display();
			break;
		default:
			t = 0;
		}
	}
	return 0;
}