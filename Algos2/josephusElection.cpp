#include <iostream>
using namespace std;

int josephus(int n, int k)
{
	int temp = 1;
	if (n > 1)
	{
		temp = (josephus(n - 1, k) + k - 1) % n + 1;
		// cout << "Kill person at index : " << temp << "\n";
	}
	return temp;
}

int main()
{
	int n, k;
	cout << "Enter the number of people : ";
	cin >> n;
	cout << "Enter the index to skip to : ";
	cin >> k;
	// josephus(n, k);
	cout << "Stay at position : " << josephus(n, k) << "\n";
	return 0;
}