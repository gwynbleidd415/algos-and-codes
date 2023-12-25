/* Find the maximum number of activities that can be performed by a person. The start and finish time of the activites are given. */

#include <bits/stdc++.h>
using namespace std;

// bool compfunc(const void *a, const void *b)
// {
// 	return (((int *)a)[1] < ((int *)b)[1]);
// }

int cmpfunc(const void *a, const void *b)
{
	return (((int *)a)[1] > ((int *)b)[1]);
}

int main()
{
	int n;
	cout << "Enter the number of activities\n";
	cin >> n;
	cout << "Enter the start and end time of the activities\n";
	int act[n][2];
	for (int i = 0; i < n; ++i)
		cin >> act[i][0] >> act[i][1];
	qsort(act, n, 2 * sizeof(int), cmpfunc);
	// sort(act, act + n, compfunc);
	for (int i = 0; i < n; ++i)
		cout << act[i][0] << " " << act[i][1] << "\n";
	int pt = 0;
	int count = 0;
	for (int i = 0; i < n; ++i)
		if (act[i][0] >= pt)
			++count, pt = act[i][1];
	cout << count << "\n";
	return 0;
}