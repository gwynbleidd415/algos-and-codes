/* Find the total number of ways of forminng a given number n by addition of numbers 1, 3 & 4.The numbers can be repeated any number of time to get the value n.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << "Enter the value of n : ";
	cin >> n;
	int nf[n] = {0};
	nf[0] = 1, nf[1] = 1, nf[2] = 1, nf[3] = 2;
	for (int i = 4; i <= n; ++i)
		nf[i] = nf[i - 1] + nf[i - 3] + nf[i - 4];
	cout << nf[n];
	return 0;
}