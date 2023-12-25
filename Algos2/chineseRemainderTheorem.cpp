#include <iostream>
using namespace std;

int eucledianInverse(int n, int p)
{
	if (p == 1)
		return 0;
	int a = n, b = p;
	int x = 1, y = 0, x1 = 0, y1 = 1;
	while (b)
	{
		int div = a / b;
		int xt = x1, yt = y1, at = a;
		x1 = x - div * x1, y1 = y - div * y1;
		x = xt, y = yt;
		a = b;
		b = at % b;
	}
	return (p + x) % p;
}

int main()
{
	int n;
	cout << "Enter the number of mods : ";
	cin >> n;
	int mods[n], rem[n], prod = 1;
	cout << "Enter the mods\n";
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> mods[i];
		prod = prod * mods[i];
	}
	cout << "Enter the remainders\n";
	for (int i = 0; i < n; ++i)
		cin >> rem[i];
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int pp = prod / mods[i];
		ans = (ans + (rem[i] * (eucledianInverse(pp, mods[i]) * pp) % prod) % prod) % prod;
	}
	cout << "Ans : " << ans << "\n";
	return 0;
}