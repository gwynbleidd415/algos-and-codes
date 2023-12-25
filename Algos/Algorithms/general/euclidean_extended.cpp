/* Find the gcd and hcf of two numbers.*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int ta = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return ta;
}

int main()
{
	cout << "Enter the two numbers : ";
	int a, b;
	cin >> a >> b;
	int p = a * b;
	int ans, x, y;
	if (a > b)
		ans = gcd(a, b, x, y);
	else
		ans = gcd(b, a, y, x);
	cout << "GCD : " << ans << "\t x : " << x << "\t y: " << y << "\n";
	return 0;
}