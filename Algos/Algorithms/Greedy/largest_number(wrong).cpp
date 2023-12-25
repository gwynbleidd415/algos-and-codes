/* Compose the largest number out of a set of given integers*/

#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> arr)
{
	for (auto itr : arr)
	{
		for (auto i : itr)
		{
			cout << i << "  ";
		}
		cout << "\n";
	}
}

int main()
{
	cout << "Enter the number of elements : ";
	int n;
	cin >> n;
	cout << "Enter the elements\n";
	vector<vector<int>> arr(5);
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		if (a == 0)
			arr[0].push_back(0);
		else
		{
			int b = a, c = 0;
			while (b != 0)
				b /= 10, ++c;
			arr[c - 1].push_back(a);
		}
	}
	// display(arr);
	for (int i = 0; i < 5; ++i)
		sort(arr[i].begin(), arr[i].end(), greater<int>());
	// display(arr);
	int ind[5] = {0};
	for (int i = 0; i < 5; ++i)
		if (arr[i].empty())
			ind[i] = -1;
	int a;
	for (int i = 0; i < 5; ++i)
		if (ind[i] != -1)
		{
			a = i;
			break;
		}
	int narr[n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 5; ++j)
			if (ind[j] != -1)
			{
				if (j > a)
				{
					// int x;
					// if(j==a+1)
					// 	x = arr[j][ind[j]];
					// else
					// x = arr[j][ind[j]] / (int)pow(10, j-a-1);
					int x = (int)pow(10, j - a);
					if (arr[j][ind[j]] / x > arr[a][ind[a]])
						a = j;
					else if (x == arr[a][ind[a]])
					{
						int y = arr[j][ind[j]] % x;
						//
					}
				}
				else if (j < a && arr[j][ind[j]] > arr[a][ind[a]] % (int)pow(10, j + 1))
					a = j;
			}
		narr[i] = arr[a][ind[a]];
		++ind[a];
		if (ind[a] == arr[a].size())
		{
			ind[a] = -1;
			for (int k = 0; k < 5; ++k)
				if (ind[k] != -1)
				{
					a = k;
					break;
				}
		}
	}
	cout << "Ans : ";
	for (int i = 0; i < n; ++i)
		cout << narr[i];
	cout << "\n";
	return 0;
}