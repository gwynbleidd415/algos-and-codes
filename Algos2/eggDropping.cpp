#include <iostream>
using namespace std;

int main()
{
	int ne, nf;
	cout << "Enter the number of eggs : ";
	cin >> ne;
	cout << "Enter the number of floors : ";
	cin >> nf;
	int dp[ne][nf];
	for (int i = 0; i < nf; ++i)
		dp[0][i] = i + 1;
	for (int i = 1; i < ne; ++i)
		dp[i][0] = 1;
	for (int i = 1; i < ne; ++i)
	{
		for (int j = 1; j < nf; ++j)
		{
			int minn = min(dp[i][j - 1], dp[i - 1][j - 1]);
			for (int k = 1; k < j; ++k)
			{
				int temp = max(dp[i][j - k - 1], dp[i - 1][k - 1]);
				if (temp < minn)
					minn = temp;
			}
			dp[i][j] = minn + 1;
		}
	}
	cout << "Minimum tests required : " << dp[ne - 1][nf - 1] << "\n";
	// for (int i = 0; i < ne; ++i)
	// {
	// 	for (int j = 0; j < nf; ++j)
	// 		cout << dp[i][j] << " ";
	// 	cout << "\n";
	// }
	return 0;
}