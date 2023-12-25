/* Find the number of points in line segments*/

#include <bits/stdc++.h>
using namespace std;

// int find_pnt(int points[], int val, int s, int e, int t)
// {
// 	if (e < s)
// 		return -1;
// 	if (s == e)
// 	{
// 		if (t == 0 && val <= points[s])
// 			return s;
// 		else if (t == 1 && val >= points[s])
// 			return s;
// 		else
// 			return -1;
// 	}
// 	int m = (s + e) / 2;
// 	int ret = -1;
// 	if (points[m] == val)
// 		ret = m;
// 	else if (points[m] > val)
// 		ret = find_pnt(points, val, s, m);
// 	else
// 		ret = find_pnt(points, val, m + 1, e);
// 	return ret;
// }

int find_abv(int points[], int val, int s, int e)
{
	if (s == e)
		if (points[s] >= val)
			return s;
		else
			return INT_MIN;
	int m = (s + e) / 2;
	int ret = -1;
	if (points[m] == val)
		ret = m;
	else if (points[m] > val)
		ret = find_abv(points, val, s, m);
	else
		ret = find_abv(points, val, m + 1, e);
	return ret;
}

int find_bel(int points[], int val, int s, int e)
{
	if (s == e)
		if (points[s] <= val)
			return s;
		else
			return -1;
	int m = (s + e + 1) / 2;
	int ret = -1;
	if (points[m] == val)
		ret = m;
	else if (points[m] > val)
		ret = find_bel(points, val, s, m - 1);
	else
		ret = find_bel(points, val, m, e);
	return ret;
}

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
	sort(points, points + np);
	for (int i = 0; i < nl; ++i)
	{
		int si = find_abv(points, lines[i][0], 0, np - 1);
		int ei = find_bel(points, lines[i][1], 0, np - 1);
		int lp = 0;
		if (si != INT_MIN && ei != INT_MIN)
			lp = ei - si + 1;
		cout << lp << " ";
	}
	cout << "\n";
	return 0;
}