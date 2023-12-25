#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number of elements : ";
	int n;
	cin >> n;
	int arr[n + 1] = {0};
	vector<int> pn;
	for (int i = 2; i <= n; ++i)
	{
		if (arr[i] == 0)
			pn.push_back(i), arr[i] = i;
		for (int j = 0; j < pn.size() && pn[j] <= arr[i] && i * pn[j] <= n; ++j)
			arr[i * pn[j]] = pn[j];
	}
	for (auto itr : pn)
		cout << itr << " ";
	cout << "\n";
	return 0;
}