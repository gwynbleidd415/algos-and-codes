/* Perform binary search in a given array*/

#include <bits/stdc++.h>
using namespace std;

bool find_el(int arr[], int s, int e, int f)
{
	if (s > e)
		return false;
	int m = (s + e) / 2;
	if (arr[m] == f)
		return true;
	else if (arr[m] < f)
		return find_el(arr, m + 1, e, f);
	else
		return find_el(arr, s, m - 1, f);
}

int main()
{
	cout << "Enter the size of array : ";
	int n;
	cin >> n;
	cout << "Enter the elements of the array\n";
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	cout << "Enter the element to find : ";
	int f;
	cin >> f;
	cout << (find_el(arr, 0, n - 1, f) ? "Found\n" : "Not Found\n");
	// ITERATIVE METHOD
	// int s = 0, e = n - 1, fnd = 0;
	// while (e >= s)
	// {
	// 	int m = (s + e) / 2;
	// 	if (arr[m] == f)
	// 	{
	// 		fnd = 1;
	// 		break;
	// 	}
	// 	else if (arr[m] > f)
	// 		e = m - 1;
	// 	else
	// 		s = m + 1;
	// }
	// cout << (fnd ? "Found\n" : "Not Found\n");
	return 0;
}