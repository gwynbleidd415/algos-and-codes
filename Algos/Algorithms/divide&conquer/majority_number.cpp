/* Given an array, check if it contains a number which has frequency greater than half the size of array.*/

#include <bits/stdc++.h>
using namespace std;

int find_major(int arr[], int s, int e)
{
	if (s == e)
		return arr[s];
	int m = (s + e) / 2;
	int a = find_major(arr, s, m);
	int b = find_major(arr, m + 1, e);
	if (a == -1)
		return b;
	else if (b == -1)
		return a;
	int ca = 0, cb = 0;
	for (int i = s; i <= e; ++i)
		if (arr[i] == a)
			++ca;
		else if (arr[i] == b)
			++cb;
	if ((e - s + 2) / 2 <= ca)
		return a;
	else if ((e - s + 2) / 2 <= cb)
		return b;
	return -1;
}

int main()
{
	cout << "Enter the size of the array : ";
	int n;
	cin >> n;
	cout << "Enter the elements of the array : ";
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int ans = find_major(arr, 0, n - 1);
	if (ans == -1)
		cout << "No major found\n";
	else
		cout << "Major : " << ans << "\n";
	return 0;
}