#include <iostream>
using namespace std;
#define INT_MAX 2147483627
#include "./myHeaders/stack.h"
// #include "stack.h"

struct matrix
{
	int r, c;
};

struct arrCell
{
	int val;
	matrix l, r;
};

int main()
{
	cout << "Enter the number of matrices : ";
	int n;
	cin >> n;
	cout << "Enter the rows and columns of matrices\n";
	matrix mats[n];
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		mats[i].r = a;
		mats[i].c = b;
	}
	arrCell dp[n][n];
	for (int i = 0; i < n; ++i)
	{
		dp[i][i].val = 0;
		dp[i][i].l.c = i;
		dp[i][i].l.r = i;
		dp[i][i].r.c = i;
		dp[i][i].r.r = i;
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n - i; ++j)
		{
			int minn = INT_MAX;
			int mid = j;
			for (int k = 0; k < i; ++k)
			{
				int temp = mats[j].r * mats[j + k].c * mats[j + i].c + dp[j][j + k].val + dp[j + k + 1][j + i].val;
				if (temp < minn)
				{
					minn = temp;
					mid = k;
				}
			}
			dp[j][j + i].val = minn;
			dp[j][j + i].l.c = j;
			dp[j][j + i].l.r = mid;
			dp[j][j + i].r.c = mid + 1;
			dp[j][j + i].r.r = i + j;
		}
	}
	cout << "Minimum Cost : " << dp[0][n - 1].val << "\n";
	// int x = 0, y = n - 1;
	// stack<matrix> st;
	// st.push(dp[x][y].r);
	// st.push(dp[x][y].l);
	// while (!st.empty())
	// {
	// 	matrix t = st.top();
	// 	st.pop();
	// 	if (t.c == t.r - 1)
	// 		cout << "(" << t.c << " X " << t.r << ")";
	// 	else if (t.c == t.r)
	// 		cout << " X " << t.c;
	// 	else
	// 	{
	// 		st.push(dp[t.c][t.r].r);
	// 		st.push(dp[t.c][t.r].l);
	// 	}
	// }
	// cout << "\n";
	return 0;
}