/* Find the gcd and hcf of two numbers.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the two numbers : ";
	int a, b;
	cin >> a >> b;
	int p = a * b;
	if (b > a)
		swap(a, b);
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	cout << "GCD : " << a << "\tHCF : " << p / a << "\n";
	return 0;
}