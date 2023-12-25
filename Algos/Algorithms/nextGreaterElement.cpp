#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number of elements : ";
	int n;
	cin >> n;
	int arr[n];
	cout << "Enter the elements\n";
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	stack<int> st;
	st.push(arr[0]);
	for (int i = 1; i < n; ++i)
	{
		while ((!st.empty()) && arr[i] > st.top())
		{
			cout << st.top() << " ---> " << arr[i] << "\n";
			st.pop();
		}
		st.push(arr[i]);
	}
	while (!st.empty())
	{
		cout << st.top() << " --> -1\n";
		st.pop();
	}
	return 0;
}