#include <iostream>
#include "myHeaders/stack.h"
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of paths : ";
	cin >> n;
	int cst[n];
	cout << "Enter the highest jump from each path\n";
	for (int i = 0; i < n; ++i)
		cin >> cst[i];
	pair<int, int> minj[n];
	minj[0] = {0, -1};
	for (int i = 1; i < n; ++i)
		minj[i] = {INT32_MAX, -1};
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j <= i + cst[i]; ++j)
			if (minj[j].first > minj[i].first + 1)
				minj[j].first = minj[i].first + 1, minj[j].second = i;
	cout << "Minimum Jumps Required : " << minj[n - 1].first << "\n";
	int x = n - 1;
	stack<int> st;
	while (x != -1)
	{
		st.push(x);
		x = minj[x].second;
	}
	while (!st.empty())
	{
		cout << st.top() << " -> ";
		st.pop();
	}
	cout << "\n";
	return 0;
}