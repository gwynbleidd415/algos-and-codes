#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str, pat;
	cout << "Enter the string : ";
	getline(cin, str);
	cout << "Enter the pattern : ";
	cin >> pat;
	if (pat.length() > str.length())
		cout << "-1\n";
	else
	{
		int arr[pat.length()] = {0};
		int i = 0, j = 1;
		while (j < pat.length())
		{
			if (pat[i] == pat[j])
			{
				arr[j] = i + 1;
				++i, ++j;
			}
			else if (i == 0)
			{
				arr[j] = 0;
				++j;
			}
			else
				i = arr[i - 1];
		}
		i = 0, j = 0;
		queue<int> q;
		while (i < str.length())
		{
			if (str[i] == pat[j])
			{
				++j;
				++i;
			}
			else
			{
				if (j != 0)
					j = arr[j - 1];
				else
					++i;
			}
			if (j == pat.length())
			{
				q.push(i - j);
				j = arr[j - 1];
			}
		}
		// cout << i << " " << j << "\n";
		if (q.empty())
			cout << "-1\n";
		else
		{
			cout << "The pattern found at indexes : ";
			while (q.size() != 1)
			{
				cout << q.front() << ", ";
				q.pop();
			}
			cout << q.front() << "\n";
			q.pop();
		}
	}
	return 0;
}