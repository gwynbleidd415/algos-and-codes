#include <iostream>
using namespace std;

int main()
{
	int r, c;
	cout << "Enter the order of the matrix : ";
	cin >> r >> c;
	cout << "Enter the terms of the matrix\n";
	int mat[r][c];
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> mat[i][j];
	int w, x, y, z;
	cout << "Enter the Area to get the sum\n";
	cout << "Top Left : ";
	cin >> w >> x;
	cout << "Bottom Right : ";
	cin >> y >> z;
	int sMat[r + 1][c + 1];
	for (int i = 0; i <= r; ++i)
		for (int j = 0; j <= c; ++j)
			sMat[i][j] = 0;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			sMat[i][j] = sMat[i - 1][j] + sMat[i][j - 1] - sMat[i - 1][j - 1] + mat[i - 1][j - 1];
	cout << "The total sum : " << sMat[y + 1][z + 1] - sMat[y + 1][x] - sMat[w][z + 1] + sMat[w][x] << "\n";
	return 0;
}