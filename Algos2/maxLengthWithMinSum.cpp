#include <iostream>
#include "myHeaders/mergeSort.h"
using namespace std;

struct sumi
{
	int i, sum;
};

bool cmpfunc(sumi a, sumi b)
{
	if (a.sum == b.sum)
		return a.i < b.i;
	return a.sum < b.sum;
}

int main()
{
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	int arr[n];
	cout << "Enter the elements\n";
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cout << "Enter the minimum value : ";
	int k;
	cin >> k;
	sumi isum[n];
	isum[0].sum = arr[0];
	isum[0].i = 0;
	for (int i = 1; i < n; ++i)
		isum[i].i = i, isum[i].sum = isum[i - 1].sum + arr[i];
	mergeSort<sumi>(isum, n, cmpfunc);
	int ind[n];
	ind[0] = isum[0].i;
	for (int i = 1; i < n; ++i)
		if (isum[i].i < ind[i - 1])
			ind[i] = isum[i].i;
		else
			ind[i] = isum[i].i;
	int x = -1, y = -1;
	int summ = 0;
	for (int i = 0; i < n; ++i)
	{
		summ += arr[i];
		if (summ >= k)
			x = 0, y = i;
		else
		{
			int nsum = summ - k;
			int s = 0, e = n - 1;
			while (s < e)
			{
				int m = (s + e + 1) / 2;
				if (isum[m].sum > nsum)
					e = m - 1;
				else
					s = m;
			}
			if (isum[s].sum <= nsum)
			{
				int t = ind[s] + 1;
				if (y - x + 1 < i - t + 1)
					y = i, x = t;
			}
		}
	}
	cout << "Maximum Length : " << (y - x + 1) << " From : " << x << " To : " << y << "\n";
	return 0;
}