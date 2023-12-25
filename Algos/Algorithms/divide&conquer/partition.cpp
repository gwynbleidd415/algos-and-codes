/* Print 1 if it is possible to evenly split the values in an array into 3 parts otherwise 0*/

#include <bits/stdc++.h>
using namespace std;

int check_part(int arr[], int e, int a, int b, int c)
{
	if (e == -1)
		if (a == 0 && b == 0 && c == 0)
			return 1;
		else
			return 0;
	if (a == b && b == c)
		return check_part(arr, e - 1, a, b, c - arr[e]);
	int x = 0, y = 0, z = 0;
	if (a == b || a == c)
	{
		// int x = 0, y = 0;
		if (b >= arr[e])
			x = check_part(arr, e - 1, a, b - arr[e], c);
		if (x == 0 && c >= arr[e])
			y = check_part(arr, e - 1, a, b, c - arr[e]);
	}
	else
	{
		if (a >= arr[e])
			x = check_part(arr, e - 1, a - arr[e], b, c);
		if (x == 0 && b >= arr[e])
			y = check_part(arr, e - 1, a, b - arr[e], c);
		if (x == 0 && y == 0 && c >= arr[e])
			z = check_part(arr, e - 1, a, b, c - arr[e]);
	}
	if (x || y || z)
		return 1;
	else
		return 0;
}

int main()
{
	cout << "Enter the size of the array : ";
	int n;
	cin >> n;
	cout << "Enter the elements of the array\n";
	int arr[n];
	int sum = 0;
	for (int i = 0; i < n; ++i)
		cin >> arr[i], sum += arr[i];
	if (sum % 3 != 0)
		cout << "0\n";
	else
		cout << check_part(arr, n - 1, sum / 3, sum / 3, sum / 3) << "\n";
	return 0;
}