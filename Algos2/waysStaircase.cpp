#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of steps : ";
	cin >> n;
	int arr[n + 1];
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i <= n; ++i)
		arr[i] = arr[i - 1] + arr[i - 2];
	cout << "Total ways : " << arr[n] << "\n";
	return 0;
}