/* Given an expression containing +,-,* place paranthesis to get the maximum value of the expression*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
void display(vector<T> v)
{
	for (auto itr : v)
		cout << itr << " ";
	cout << "\n";
}

pair<int, int> solve(pair<int, int> n1, pair<int, int> n2, char ch)
{
	if (ch == '+')
		return make_pair(n1.first + n2.first, n1.second + n2.second);
	if (ch == '-')
		return make_pair(n1.first - n2.second, n1.second - n2.first);
	int a = n1.first * n2.first;
	int b = n1.first * n2.second;
	int c = n1.second * n2.first;
	int d = n1.second * n2.second;
	int maxx = max(a, max(b, max(c, d)));
	int minn = min(a, min(b, min(c, d)));
	return make_pair(minn, maxx);
}

// pair<int, int> find_minmax(vector<int> nums, vector<char> syms, int s, int e, vector<vector<pair<int, int>>> minmax)
// {
// 	if (s == e)
// 		return make_pair(nums[s], nums[s]);
// 	if (minmax[s][e].first == INT_MIN)
// 	{
// 		int maxx = INT_MIN;
// 		int minn = INT_MAX;
// 		for (int i = s; i < e; ++i)
// 		{
// 			pair<int, int> a = find_minmax(nums, syms, s, i, minmax);
// 			pair<int, int> b = find_minmax(nums, syms, i + 1, e, minmax);
// 			pair<int, int> c = solve(a, b, syms[i]);
// 			if (c.first < minn)
// 				minn = c.first;
// 			if (c.second > maxx)
// 				maxx = c.second;
// 		}
// 		minmax[s][e] = make_pair(minn, maxx);
// 	}
// 	return minmax[s][e];
// }

int main()
{
	cout << "Enter the expression : ";
	string exp;
	cin >> exp;
	vector<int> nums;
	vector<char> syms;
	int st = 0;
	for (int i = 0; i < exp.length(); ++i)
		if (exp[i] == '+' || exp[i] == '*' || exp[i] == '-')
			nums.push_back(stoi(exp.substr(st, i))), syms.push_back(exp[i]), st = i + 1;
	nums.push_back(stoi(exp.substr(st, exp.length())));
	// display(nums);
	// display(syms);
	vector<vector<pair<int, int>>> minmax(nums.size(), vector<pair<int, int>>(nums.size(), make_pair(INT_MIN, INT_MAX)));
	for (int i = 0; i < nums.size(); ++i)
		minmax[i][i] = make_pair(nums[i], nums[i]);
	for (int i = 1; i < nums.size(); ++i)
	{
		for (int j = 0; j < nums.size() - i; ++j)
		{
			int minn = INT_MAX, maxx = INT_MIN;
			for (int k = j; k < j + i; ++k)
			{
				pair<int, int> a = minmax[j][k];
				pair<int, int> b = minmax[k + 1][j + i];
				pair<int, int> c = solve(a, b, syms[k]);
				if (c.first < minn)
					minn = c.first;
				if (c.second > maxx)
					maxx = c.second;
			}
			minmax[j][j + i] = make_pair(minn, maxx);
		}
	}
	pair<int, int> ans = minmax[0][nums.size() - 1];
	cout << "MIN : " << ans.first << "    MAX : " << ans.second << "\n";
	return 0;
}