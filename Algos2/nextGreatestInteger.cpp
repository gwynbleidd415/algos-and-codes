#include <iostream>
#include "./myHeaders/stack.h"
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	int arr[n + 1];
	arr[0] = INT32_MAX;
	cout << "Enter the heights of the elements\n";
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	stack<int> st;
	int ng[n];
	st.push(0);
	for (int i = 1; i <= n; ++i)
	{
		while (arr[st.top()] < arr[i])
		{
			ng[st.top() - 1] = arr[i];
			st.pop();
		}
		st.push(i);
	}
	while (st.top() != 0)
	{
		ng[st.top() - 1] = -1;
		st.pop();
	}
	for (int i = 0; i < n; ++i)
		cout << arr[i + 1] << " -> " << ng[i] << "\n";
	return 0;
}
