#include <iostream>
#include "./myHeaders/stack.h"
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	int arr[n + 1];
	arr[0] = 0;
	cout << "Enter the heights of the elements\n";
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	stack<int> st;
	st.push(0);
	int maxx = 0, s = 0, e = 0;
	int i;
	for (i = 1; i <= n; ++i)
	{
		if (arr[st.top()] <= arr[i])
			st.push(i);
		else
		{
			while (arr[st.top()] > arr[i])
			{
				int temp = st.top();
				st.pop();
				if (arr[temp] * (i - st.top() - 1) > maxx)
				{
					maxx = arr[temp] * (i - st.top() - 1);
					s = st.top();
					e = i - 2;
					// cout << s << " " << e << " " << maxx << "\n";
				}
			}
			st.push(i);
		}
	}
	while (st.top() != 0)
	{
		int temp = st.top();
		st.pop();
		if (arr[temp] * (i - st.top() - 1) > maxx)
		{
			maxx = arr[temp] * (i - st.top() - 1);
			s = st.top() + 1;
			e = i - 1;
			// cout << s << " " << e << " " << maxx << "\n";
		}
	}
	cout << "Max Area : " << maxx << " \tFrom : " << s << " \tto : " << e << "\n";
	return 0;
}