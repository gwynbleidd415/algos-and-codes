#include <bits/stdc++.h>
using namespace std;

int calcfib(int fib[], int n)
{
	if (n > 1)
		if (fib[n] == 0)
			fib[n] = calcfib(fib, n - 1) + calcfib(fib, n - 2);
	return fib[n];
}

int main()
{
	int n;
	cout << "Enter the end range : ";
	cin >> n;
	int fib[n] = {0};
	fib[1] = 1;
	calcfib(fib, n - 1);
	for (int i = 0; i < n; ++i)
		cout << fib[i] << "  ";
	cout << "\n";
	return 0;
}