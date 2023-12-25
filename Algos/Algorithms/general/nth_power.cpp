/* Find the nth power of a number.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number : ";
	int num;
	cin >> num;
	cout << "Enter the value of n : ";
	int n;
	cin >> n;
	if (n == 0)
		cout << " Ans : 1\n";
	else
	{
		int res = 1;
		int t = num;
		for (int i = n; i > 0; i /= 2)
		{
			if (i & 1)
				res *= t;
			t *= t;
		}
		cout << "Ans : " << res << "\n";
	}
	return 0;
}