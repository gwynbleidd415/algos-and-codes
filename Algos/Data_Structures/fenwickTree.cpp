#include <bits/stdc++.h>
using namespace std;

class fenwick
{
	vector<int> v;
	int n;

public:
	fenwick(int arr[], int n)
	{
		v = vector<int>(n, 0);
		this->n = n;
		// USING SUM FUNCTION
		// v[0] = arr[0];
		// for (int i = 1; i < n; ++i)
		// 	v[i] = arr[i] + findSum(i - 1, (i & (i + 1)));
		// USING INCREMENT FUNCTION
		for (int i = 0; i < n; ++i)
			increase(i, arr[i]);
	}
	int findSum(int a, int b = 0)
	{
		int sum = 0, min = 0;
		for (int i = a; i >= 0; i = (i & (i + 1)) - 1)
			sum += v[i];
		for (int i = b - 1; i >= 0; i = (i & (i + 1)) - 1)
			min += v[i];
		return sum - min;
	}
	void increase(int a, int val)
	{
		for (int i = a; i < n; i = i | (i + 1))
			v[i] += val;
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
	int arr[n];
	cout << "Enter the elements\n";
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	fenwick f(arr, n);
	int t = 1;
	while (t)
	{
		cout << "Choose..\n1.Sum  2.Sum Range  3.Increase  4.Display  5.Exit  : ";
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
			cout << f.findSum(a) << "\n";
			break;
		case 2:
		{
			cout << "Enter the next number : ";
			int b;
			cin >> b;
			cout << f.findSum(b, a) << "\n";
		}
		break;
		case 3:
		{
			cout << "Enter the value : ";
			int val;
			cin >> val;
			f.increase(a, val);
			arr[a] += val;
		}
		break;
		case 4:
			f.display();
			break;
		default:
			t = 0;
			break;
		}
	}
	return 0;
}