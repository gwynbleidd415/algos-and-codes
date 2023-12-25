#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	int arr[n];
	cout << "Enter the elements\n";
	int maxx = INT32_MIN;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		if (arr[i] > maxx)
			maxx = arr[i];
	}
	// if (maxx < 0)
	// 	cout << "Maximum sum : " << maxx << "\n";
	if (maxx >= 0)
	{
		maxx = 0;
		int en = 0;
		for (int i = 0; i < n; ++i)
		{
			en += arr[i];
			if (maxx < en)
				maxx = en;
			else if (en < 0)
				en = 0;
		}
	}
	cout << "Maximum sum in a substr : " << maxx << "\n";
	return 0;
}