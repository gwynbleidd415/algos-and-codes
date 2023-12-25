#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the number of nodes : ";
	int n;
	cin >> n;
	int arr[n + 1];
	arr[0] = arr[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		int temp = 0;
		for (int j = 1; j <= i; ++j)
			temp += arr[j - 1] * arr[i - j];
		arr[i] = temp;
	}
	cout << "Number of BST possible : " << arr[n] << "\n";
	for (int i = 0; i <= n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}