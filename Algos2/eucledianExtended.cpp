#include <iostream>
using namespace std;

int egcd(int a, int b, int &x, int &y)
{
	if (a % b == 0)
	{
		x = 0, y = 1;
		return b;
	}
	int x1, y1;
	int r = egcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return r;
}

int main()
{
	int a, b;
	cout << "Enter the two numbers : ";
	cin >> a >> b;
	if (a < b)
		swap(a, b);
	int x, y;
	int ans = egcd(a, b, x, y);
	cout << "GCD : " << ans << " \tHCF : " << (a * b) / ans << "\n";
	cout << a << "*" << x << " + " << b << "*" << y << " = " << ans << "\n";
	return 0;
}