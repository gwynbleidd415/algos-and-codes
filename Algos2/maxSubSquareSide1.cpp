#include <iostream>
using namespace std;

int main()
{
	cout << "Enter the order of the square : ";
	int n;
	cin >> n;
	cout << "Enter the sides\n";
	int mat[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> mat[i][j];
	pair<int, int> n1[n][n];
	n1[0][0] = {mat[0][0], mat[0][0]};
	for (int i = 1; i < n; ++i)
		if (mat[0][i] == 0)
			n1[0][i] = {0, 0};
		else
			n1[0][i] = {n1[0][i - 1].first + 1, 1};
	for (int i = 1; i < n; ++i)
		if (mat[i][0] == 0)
			n1[i][0] = {0, 0};
		else
			n1[i][0] = {1, n1[i - 1][0].second + 1};
	int maxx = 0, mb = 0, mr = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (mat[i][j] == 0)
				n1[i][j] = {0, 0};
			else
				n1[i][j] = {n1[i][j - 1].first + 1, n1[i - 1][j].second + 1};
			int t = max(n1[i][j].first, n1[i][j].second);
			for (int k = t; k > maxx; --k)
			{
				if (n1[i][j - k + 1].second >= k && n1[i - k + 1][j].first >= k)
				{
					maxx = k;
					mb = i;
					mr = j;
					break;
				}
			}
		}
	}
	cout << "Maximum length of square is : " << maxx << " \tFrom : (" << mb - maxx + 1 << ", " << mr - maxx + 1 << ")\n";
	return 0;
}