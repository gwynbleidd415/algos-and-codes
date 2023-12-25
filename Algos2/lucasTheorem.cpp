#include <iostream>
using namespace std;

int ncrp(int n, int r, int p)
{
	int c[r + 1];
	for (int i = 0; i <= r; ++i)
		c[i] = 0;
	c[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = min(r, i); j > 0; --j)
			c[j] = (c[j - 1] + c[j]) % p;
	return c[r];
}

int lucas(int n, int r, int p)
{
	if (r > n)
		return 0;
	if (r == 0 || r == n)
		return 1;
	int a, b;
	a = n % p, b = r % p;
	return ncrp(a, b, p) * lucas(n / p, r / p, p);
}

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
	cout << "The value of ncr mod p : " << lucas(n, r, p) << "\n";
	return 0;
}