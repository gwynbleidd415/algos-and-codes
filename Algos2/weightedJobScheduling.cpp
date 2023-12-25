#include <iostream>
#include "./myHeaders/mergeSort.h"
using namespace std;

struct jobs
{
	int s, e, profit;
};

bool cmpfunc(jobs a, jobs b)
{
	return (a.e < b.e);
}

int main()
{
	int n;
	cout << "Enter the number of jobs : ";
	cin >> n;
	jobs arr[n];
	cout << "Enter the starting and ending time followed by profit for each job\n";
	for (int i = 0; i < n; ++i)
		cin >> arr[i].s >> arr[i].e >> arr[i].profit;
	mergeSort<jobs>(arr, n, cmpfunc);
	int pr[n];
	for (int i = 0; i < n; ++i)
		pr[i] = arr[i].profit;
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < i; ++j)
			if (arr[j].e <= arr[i].s)
				pr[i] = max(pr[i], arr[i].profit + pr[j]);
	int maxx = pr[0];
	for (int i = 1; i < n; ++i)
		if (pr[i] > maxx)
			maxx = pr[i];
	cout << "Maximum Profit : " << maxx << "\n";
	// for (int i = 0; i < n; ++i)
	// 	cout << pr[i] << " ";
	// cout << "\n";
}