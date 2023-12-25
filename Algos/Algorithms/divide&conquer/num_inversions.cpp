/* Count the number of inversions in the array. Inversion is when arr[i]>arr[j] for each i<j.*/

#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int s, int e)
{
	int m = (s + e) / 2;
	int temp[e - s + 1];
	int count = 0;
	int i = 0, j = s, k = m + 1;
	while (k <= e && j <= m)
		if (arr[k] < arr[j])
			temp[i++] = arr[k++], count += m - j + 1;
		else
			temp[i++] = arr[j++];
	while (k <= e)
		temp[i++] = arr[k++];
	while (j <= m)
		temp[i++] = arr[j++];
	j = 0;
	for (i = s; i <= e; ++i)
		arr[i] = temp[j++];
	return count;
}

int count_inv(int arr[], int s, int e)
{
	if (e <= s)
		return 0;
	int m = (s + e) / 2;
	int c = count_inv(arr, s, m) + count_inv(arr, m + 1, e);
	c += merge(arr, s, e);
	return c;
}

int main()
{
	cout << "Enter the number of elements of the array : ";
	int n;
	cin >> n;
	cout << "Enter the elements of the array : ";
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int ans = count_inv(arr, 0, n - 1);
	cout << "Ans : " << ans << "\n";
	return 0;
}