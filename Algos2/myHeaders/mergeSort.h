template <class T>
class mergeSort
{
	T *arr;
	int n;
	bool (*cmpfunc)(T, T);

public:
	mergeSort(
		T *arr, int n, bool (*cmpfunc)(T, T) = [](T a, T b) -> bool { return a <= b; })
	{
		this->n = n;
		this->arr = arr;
		this->cmpfunc = cmpfunc;
		sort(0, n - 1);
	}

private:
	void sort(int s, int e)
	{
		if (s < e)
		{
			int m = (s + e) / 2;
			sort(s, m);
			sort(m + 1, e);
			merge(s, e);
		}
	}
	void merge(int s, int e)
	{
		int m = (s + e) / 2;
		T *temp = new T[e - s + 1];
		int i = s, j = m + 1, k = 0;
		while (i <= m && j <= e)
		{
			if (cmpfunc(arr[i], arr[j]))
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		while (i <= m)
			temp[k++] = arr[i++];
		while (j <= e)
			temp[k++] = arr[j++];
		for (int x = s; x <= e; ++x)
			arr[x] = temp[x - s];
	}
};