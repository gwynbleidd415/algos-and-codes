#include <bits/stdc++.h>
using namespace std;

// To print all strings using all characters
void recPer(string str, string ans)
{
	if (str.length() == 0)
		cout << ans << "\t";
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == str[i - 1])
			continue;
		recPer(str.substr(0, i) + str.substr(i + 1), ans + str[i]);
	}
}

// To print all possible strings of any number of characters
void allRecPer(string str, string ans)
{
	if (ans != "")
		cout << ans << "\t";
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == str[i - 1])
			continue;
		allRecPer(str.substr(0, i) + str.substr(i + 1), ans + str[i]);
	}
}

int main()
{
	cout << "Enter the string : ";
	string str;
	getline(cin, str);
	sort(str.begin(), str.end());
	allRecPer(str, "");
	return 0;
}