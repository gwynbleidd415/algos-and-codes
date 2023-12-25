#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the number of elements : ";
	int n;
	cin >> n;
	int el[n];
	cout << "Enter the elements\n";
	for (int i = 0; i < n; ++i)
		cin >> el[i];
	int arr[n];
	for (int i = 0; i < n; ++i)
		arr[i] = 1;
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (el[i] > el[j] && arr[i] <= arr[j])
				arr[i] = arr[j] + 1;
	int maxx = arr[0];
	for (int i = 1; i < n; ++i)
		if (maxx < arr[i])
			maxx = arr[i];
	cout << "Longest Subsequence : " << maxx << "\n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << '\n';
	return 0;
}