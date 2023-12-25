#include <iostream>
#include "./myHeaders/stack.h"
using namespace std;

int main()
{
	cout << "Enter the number of elements : ";
	int n;
	cin >> n;
	int el[n];
	cout << "Enter the elements\n";
	for (int i = 0; i < n; ++i)
		cin >> el[i];
	int arr[n], from[n], l = 0;
	for (int i = 0; i < n; ++i)
		from[i] = -1;
	arr[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		if (el[i] > el[arr[l]])
		{
			from[i] = arr[l];
			arr[++l] = i;
		}
		else if (el[i] < el[arr[0]])
			arr[0] = i;
		else
		{
			int s = 0, e = l;
			while (s < e)
			{
				int m = (s + e) / 2;
				if (el[arr[m]] < el[i])
					s = m + 1;
				else
					e = m;
			}
			from[i] = arr[s - 1];
			arr[s] = i;
		}
	}
	cout << "Maximum Length of subsequence : " << l + 1 << "\n";
	// for (int i = 0; i < n; ++i)
	// 	cout << from[i] << " ";
	// cout << "\n";
	// for (int i = 0; i <= l; ++i)
	// 	cout << arr[i] << " ";
	// cout << "\n";
	stack<int> st;
	st.push(arr[l]);
	int x = from[arr[l]];
	while (x != -1)
	{
		st.push(x);
		x = from[x];
	}
	while (!st.empty())
	{
		cout << st.top() << " < ";
		st.pop();
	}
	cout << "\n";
	return 0;
}