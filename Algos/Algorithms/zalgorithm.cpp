#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s, p;
	cout << "Enter the string : ";
	cin >> s;
	cout << "Enter the pattern : ";
	cin >> p;
	string ns = p + " " + s;
	int arr[ns.length()] = {0};
	int i = 1, j = 1, k = 0;
	while (j < ns.length())
	{
		if (ns[j] == ns[k])
			++j, ++k;
		else if (k == 0)
		{
			arr[i] = 0;
			++i, ++j;
		}
		else
		{
			arr[i++] = k;
			int l = 1;
			while (i + arr[l] < j)
				arr[i++] = arr[l++];
			k = j - i;
		}
	}
	if (k > 0)
	{
		arr[i++] = k;
		int l = 1;
		while (i != ns.length())
		{
			if (i + arr[l] <= j)
				arr[i] = arr[l];
			else
				arr[i] = j - i;
			++i, ++l;
		}
	}
	for (int i = 0; i < ns.length(); ++i)
		if (arr[i] == p.length())
			cout << i - p.length() - 1 << " ";
	cout << "\n";
	return 0;
}