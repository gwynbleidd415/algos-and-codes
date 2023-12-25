/* Find the total number of ways of forminng a given number n by addition of numbers 1, 3 & 4.The numbers can be repeated any number of time to get the value n.*/

#include <bits/stdc++.h>
using namespace std;

int num_fact(int nf[], int n)
{
	if (n > 3 && nf[n] == 0)
		nf[n] = num_fact(nf, n - 4) + num_fact(nf, n - 3) + num_fact(nf, n - 1);
	return nf[n];
}

int main()
{
	int n;
	cout << "Enter the value of n : ";
	cin >> n;
	int nf[n + 1] = {0};
	nf[0] = 1, nf[1] = 1, nf[2] = 1, nf[3] = 2;
	int ans = num_fact(nf, n);
	cout << ans << "\n";
	return 0;
}