#include <iostream>
#include "myHeaders/stack.h"
using namespace std;

struct ar
{
	int t, b, l, r, maxx;
	ar(int maxx = 0, int t = 0, int b = 0, int l = 0, int r = 0)
	{
		this->l = l;
		this->r = r;
		this->maxx = maxx;
		this->t = t;
		this->b = b;
	}
};

struct maxAr
{
	int maxx, l, r, t;
	maxAr(int maxx = 0, int l = 0, int r = 0, int t = 0)
	{
		this->l = l;
		this->r = r;
		this->maxx = maxx;
		this->t = t;
	}
};

maxAr maxRectAr(int *arr, int n)
{
	stack<int> st;
	st.push(0);
	maxAr maxx = maxAr();
	int j;
	for (j = 1; j <= n; ++j)
	{
		while (arr[st.top()] > arr[j])
		{
			int temp = st.top();
			st.pop();
			int area = arr[temp] * (j - st.top() - 1);
			if (area > maxx.maxx)
			{
				maxx.maxx = area;
				maxx.l = st.top();
				maxx.r = j - 2;
				maxx.t = arr[temp];
			}
		}
		st.push(j);
	}
	while (st.top() != 0)
	{
		int temp = st.top();
		st.pop();
		int area = arr[temp] * (j - st.top() - 1);
		if (area > maxx.maxx)
		{
			maxx.maxx = area;
			maxx.l = st.top();
			maxx.r = j - 2;
			maxx.t = arr[temp];
		}
	}
	return maxx;
}

int main()
{
	int r, c;
	cout << "Enter the number of rows and columns of the matrix : ";
	cin >> r >> c;
	int mat[r][c];
	cout << "Enter the elements of the matrix\n";
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> mat[i][j];
	int arr[c + 1] = {0};
	ar maxx = ar();
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			if (mat[i][j] == 1)
				arr[j + 1] += 1;
			else
				arr[j + 1] = 0;
		maxAr temp = maxRectAr(arr, c);
		if (maxx.maxx < temp.maxx)
		{
			maxx.maxx = temp.maxx;
			maxx.l = temp.l;
			maxx.r = temp.r;
			maxx.t = i - temp.t + 1;
			maxx.b = i;
		}
	}
	cout << "Maximum area of 1's : " << maxx.maxx << "\n";
	cout << "TOP : " << maxx.t << " \tBOTTOM : " << maxx.b << "\n";
	cout << "LEFT : " << maxx.l << " \tRIGHT : " << maxx.r << "\n";
	return 0;
}

// 1 0 0 1 1 1
// 1 0 1 1 0 1
// 0 1 1 1 1 1
// 0 0 1 1 1 1