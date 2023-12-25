#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number : ";
	cin >> n;
	bool arr[n + 1];
	for (int i = 2; i <= n; ++i)
		arr[i] = true;
	arr[0] = arr[1] = false;
	for (int i = 2; i <= n; ++i)
		if (arr[i] == true)
			for (int j = i * i; j <= n; j += i)
				arr[j] = false;
	for (int i = 0; i <= n; ++i)
		if (arr[i] == true)
			cout << i << ", ";
	cout << "\n";
	return 0;
}