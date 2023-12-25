#include <iostream>
using namespace std;

struct maxMat
{
	int t, b, r, l, maxx;
};

struct maxm
{
	int maxx, t, b;
	maxm(int maxx, int t, int b)
	{
		this->maxx = maxx;
		this->t = t;
		this->b = b;
	}
};

maxm kadane(int *arr, int n)
{
	int s, e, maxx = INT32_MIN;
	for (int i = 0; i < n; ++i)
		if (arr[i] > maxx)
		{
			maxx = arr[i];
			s = e = i;
		}
	if (maxx <= 0)
		return maxm(maxx, s, e);
	maxx = 0;
	s = e = 0;
	int med = 0, es = 0;
	for (int i = 0; i < n; ++i)
	{
		med += arr[i];
		if (med > maxx)
		{
			maxx = med;
			e = i;
			s = es;
		}
		else if (med < 0)
		{
			med = 0;
			es = i + 1;
		}
	}
	return maxm(maxx, s, e);
}

int main()
{
	int r, c;
	cout << "Enter the number of rows and columns of the matrix : ";
	cin >> r >> c;
	int mat[r][c];
	cout << "Enter the elements of the rows and columns\n";
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> mat[i][j];
	int arr[r];
	maxMat ar;
	ar.maxx = INT32_MIN;
	ar.r = ar.b = ar.l = ar.t = 0;
	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j < r; ++j)
			arr[j] = 0;
		for (int j = i; j < c; ++j)
		{
			for (int k = 0; k < r; ++k)
				arr[k] += mat[k][j];
			maxm tmax = kadane(arr, r);
			if (ar.maxx < tmax.maxx)
			{
				ar.maxx = tmax.maxx;
				ar.t = tmax.t;
				ar.b = tmax.b;
				ar.l = i;
				ar.r = j;
			}
		}
	}
	cout << "Maximum sum of a rectangular area of matrix : " << ar.maxx << "\n";
	cout << "Top : " << ar.t << " \tBottom : " << ar.b << " \tLeft : " << ar.l << " \tRight : " << ar.r << "\n";
	return 0;
}