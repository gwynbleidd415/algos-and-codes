template <class T = int>
class minHeap
{
	T *arr;
	int *pos;
	int n, c;
	bool (*cmpFunc)(T, T);
	int (*index)(T);
	void swap(T &a, T &b)
	{
		T c = a;
		a = b;
		b = c;
		delete c;
	}
	void swapIndex(int &a, int &b)
	{
		int c = a;
		a = b;
		b = a;
	}

public:
	minHeap(int c, bool (*cmpFunc)(T, T), int (*index)(T))
	{
		this->c = c;
		this->n = 0;
		this->cmpFunc = cmpFunc;
		this->index = index;
		arr = new T[c];
		pos = new int[c];
	}
	bool empty()
	{
		return (n == 0);
	}
	T top()
	{
		if (n > 0)
			return arr[0];
		T null;
		return null;
	}
	void push(T data)
	{
		arr[n] = data;
		pos[index(data)] = n;
		int i = n;
		while (i > 0 && cmpFunc(arr[i], arr[(i - 1) / 2]))
		{
			swap(arr[i], arr[(i - 1) / 2]);
			swap(pos[index(arr[i])], pos[index(arr[(i - 1) / 2])]);
			i = (i - 1) / 2;
		}
		++n;
	}
	void pop()
	{
		swap(arr[0], arr[n]);
		--n;
		int i = 0;
		while (true)
		{
			int j = i * 2 + 1;
			if (j + 1 < n && cmpFunc(arr[j + 1], arr[i]) && cmpFunc(arr[j + 1], arr[j]))
			{
				swap(arr[i], arr[j + 1]);
				swap(pos[index(arr[i])], pos[index(arr[j + 1])]);
				i = j + 1;
			}
			else if (j < n && cmpFunc(arr[j], arr[i]))
			{
				swap(arr[i], arr[j + 1]);
				swap(pos[index(arr[i])], pos[index(arr[j])]);
				i = j;
			}
			else
				break;
		}
	}
	void reduce(T data, T nData)
	{
		int i = pos[index(data)];
		arr[i] = nData;
		while (i > 0 && cmpFunc(arr[i], arr[(i - 1) / 2]))
		{
			swap(arr[i], arr[(i - 1) / 2]);
			swap(pos[index(arr[i])], pos[index(arr[(i - 1) / 2])]);
			i = (i - 1) / 2;
		}
	}
};