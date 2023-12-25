/* Calculate the sum of 1st n numbers in fibonacci series*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the value of n : ";
	int n;
	cin >> n;
	if (n < 1)
		cout << " Ans : 0\n";
	else
	{
		int p[2][2] = {{0, 1}, {1, 1}};
		int pn[2][2] = {{1, 1}, {1, 1}};
		for (int i = n - 1; i > 0; i /= 2)
		{
			if (i & 1)
			{
				int temp[2][2];
				temp[0][0] = pn[0][0] * p[0][0] + pn[0][1] * p[1][0];
				temp[0][1] = pn[0][0] * p[0][1] + pn[0][1] * p[1][1];
				temp[1][0] = pn[1][0] * p[0][0] + pn[1][1] * p[1][0];
				temp[1][1] = pn[1][0] * p[0][1] + pn[1][1] * p[1][1];
				pn[0][0] = temp[0][0], pn[0][1] = temp[0][1], pn[1][0] = temp[1][0], pn[1][1] = temp[1][1];
				// delete (temp);
			}
			int temp1[2][2];
			temp1[0][0] = p[0][0] * p[0][0] + p[0][1] * p[1][0];
			temp1[0][1] = p[0][0] * p[0][1] + p[0][1] * p[1][1];
			temp1[1][0] = p[1][0] * p[0][0] + p[1][1] * p[1][0];
			temp1[1][1] = p[1][0] * p[0][1] + p[1][1] * p[1][1];
			p[0][0] = temp1[0][0], p[0][1] = temp1[0][1], p[1][0] = temp1[1][0], p[1][1] = temp1[1][1];
			// delete (temp);
		}
		cout << "Ans : " << pn[1][1] - 1 << "\n";
	}
	return 0;
}