#include <iostream>
using namespace std;

int main()
{
	int n, r, p;
	cout << "Enter the value of n : ";
	cin >> n;
	cout << "Enter the value of r : ";
	cin >> r;
	cout << "Enter the value of p : ";
	cin >> p;
	if (r > n - r)
		r = n - r;
	int c[r + 1];
	for (int i = 0; i <= r; ++i)
		c[i] = 0;
	c[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = min(r, i); j > 0; --j)
			c[j] = (c[j - 1] + c[j]) % p;
	cout << "The value of ncr mod p : " << c[r] << "\n";
	return 0;
}