template <class T>
class listMergeSort
{
public:
	// listMergeSort() {}
	listMergeSort(T *list)
	{
		// this->list = list;
		T *e = list;
		while (e->next != NULL)
			e = e->next;
		mergeSort(list, e);
	}
	void merge(T &a, T &m, T &b)
	{
		T *x = a, *y = m->next;
		T *s = NULL, *e = NULL;
		if (x->data <= y->data)
		{
			s = new T(x->data);
			x = x->next;
		}
		else
		{
			s = new T(y->data);
			y = y->next;
		}
		e = s;
		while (x != m->next && y != b->next)
		{
			if (x->data <= y->data)
			{
				e->next = new T(x->data);
				e = e->next;
				x = x->next;
			}
			else
			{
				e->next = new T(y->data);
				e = e->next;
				y = y->next;
			}
		}
		while (x != m->next)
		{
			e->next = new T(x->data);
			e = e->next;
			x = x->next;
		}
		while (y != b->next)
		{
			e->next = new T(y->data);
			e = e->next;
			y = y->next;
		}
		T *temp = a, *temp1 = s;
		while (s != e->next)
		{
			temp->data = s->data;
			s = s->next;
			temp = temp->next;
		}
		while (temp1 != NULL)
		{
			T *temp2 = temp1;
			temp1 = temp1->next;
			delete temp2;
		}
	}
	void mergeSort(T &a, T &b)
	{
		if (a == b)
			return;
		T *slow = a, fast = a;
		while (fast->next != b && fast != b)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		mergeSort(a, fast);
		mergeSort(fast->next, b);
	}
};
