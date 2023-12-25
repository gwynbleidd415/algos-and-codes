/* Find the number of points in line segments*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number of line segments and points : ";
	int nl, np;
	cin >> nl >> np;
	cout << "Enter the staring and ending points of the line segment\n";
	int lines[nl][2];
	for (int i = 0; i < nl; ++i)
		cin >> lines[i][0] >> lines[i][1];
	cout << "Enter the points\n";
	int points[np];
	for (int i = 0; i < np; ++i)
		cin >> points[i];
	int l = 2 * nl + np;
	vector<pair<int, int>> data(l);
	int i = 0;
	for (int j = 0; j < nl; ++j)
	{
		data[i++] = make_pair(lines[j][0], -1);
		data[i++] = make_pair(lines[j][1], -2);
	}
	for (int k = 0; k < np; ++k)
		data[i++] = make_pair(points[k], k);
	sort(data.begin(), data.end());
	int c = 0;
	int count[np];
	for (auto itr : data)
		if (itr.second == -1)
			++c;
		else if (itr.second == -2)
			--c;
		else
			count[itr.second] = c;
	for (i = 0; i < np; ++i)
		cout << count[i] << " ";
	cout << "\n";
	return 0;
}