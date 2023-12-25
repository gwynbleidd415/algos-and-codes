/* A calculator can calculate x+1, x*2, x*3 for current number x. Find minimum operations for the calculator to reach n from 1.*/

#include <bits/stdc++.h>
using namespace std;

int find_ops(int arr[], int e)
{
	if (e == 0)
		return 0;
	int a = INT_MAX, b = INT_MAX, c = INT_MAX;
	if (arr[e] == 0)
	{
		if ((e + 1) % 2 == 0)
			a = find_ops(arr, (e + 1) / 2 - 1);
		if ((e + 1) % 3 == 0)
			b = find_ops(arr, (e + 1) / 3 - 1);
		c = find_ops(arr, e - 1);
		arr[e] = min(a, min(b, c)) + 1;
	}
	return arr[e];
}

int main()
{
	cout << "Enter the number n : ";
	int n;
	cin >> n;
	int arr[n] = {0};
	int ans = find_ops(arr, n - 1);
	cout << "MIN OPS : " << ans << "\n";
	stack<int> st;
	int i = n - 1;
	while (i)
		if (arr[i] == arr[i - 1] + 1)
			st.push(i + 1), --i;
		else if ((i + 1) % 2 == 0 && arr[i] == arr[(i + 1) / 2 - 1] + 1)
			st.push(i + 1), i = (i + 1) / 2 - 1;
		else if ((i + 1) % 3 == 0 && arr[i] == arr[(i + 1) / 3 - 1] + 1)
			st.push(i + 1), i = (i + 1) / 3 - 1;
	st.push(1);
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << "\n";
	return 0;
}