#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of paths : ";
	cin >> n;
	int cst[n];
	cout << "Enter the maximum jump possible for each path\n";
	for (int i = 0; i < n; ++i)
		cin >> cst[i];
	int st = cst[0], mst = cst[0], jumps = ((n == 1) ? 0 : 1), mi = 0, j = 0;
	bool np = false;
	int arr[n];
	arr[j++] = 0;
	for (int i = 1; i < n; ++i)
		arr[i] = -1;
	for (int i = 1; i < n - 1; ++i)
	{
		--mst, --st;
		if (mst < cst[i])
		{
			mst = cst[i];
			mi = i;
		}
		if (st == 0)
		{
			if (mst == 0)
			{
				np = true;
				break;
			}
			st = mst;
			arr[j++] = mi;
			++jumps;
		}
	}
	arr[j++] = n - 1;
	if (np)
		cout << "Not Possible\n";
	else
	{
		cout << "Minimum Jumps : " << jumps << "\n";
		for (int i = 0; i < j; ++i)
			cout << arr[i] << " -> ";
		cout << "\n";
	}
	return 0;
}

// 1 3 5 8 9 2 6 7 6 8 9