#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number of elements : ";
	int n;
	cin >> n;
	int arr[n];
	cout << "Enter their sizes\n";
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	stack<int> st;
	int maxx = 0;
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		while ((!(st.empty())) && arr[st.top()] > arr[i])
		{
			int x = st.top();
			maxx = max(maxx, arr[x] * (i - x));
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty())
	{
		int x = st.top();
		maxx = max(maxx, arr[x] * (i - x));
		st.pop();
	}
	cout << maxx << "\n";
	return 0;
}