/* Given an array find the maximum product between two numbers in the array.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number of elements of the array : ";
	int n;
	cin >> n;
	cout << "Enter the elements of the array\n";
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int m1, m2;
	m1 = arr[0], m2 = arr[1];
	for (int i = 1; i < n; ++i)
		if (arr[i] > m1)
		{
			m2 = m1;
			m1 = arr[i];
		}
		else if (arr[i] > m2)
			m2 = arr[i];
	cout << "Ans : " << m2 * m1 << "\n";
	return 0;
}