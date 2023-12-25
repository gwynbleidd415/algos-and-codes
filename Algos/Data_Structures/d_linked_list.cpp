#include <bits/stdc++.h>
using namespace std;

template <class T>
class D_Linked_List
{
	struct node
	{
		T data;
		node *next;
		node *prev;
		node(T data, node *prev = NULL, node *next = NULL)
		{
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
	};

	node *top = NULL;
	node *bottom = NULL;
	int n = 0;

public:
	void push_first(T data)
	{
		if (n == 0)
		{
			top = new node(data);
			bottom = top;
		}
		else
		{
			top->prev = new node(data, NULL, top);
			top = top->prev;
		}
		++n;
	}
	void push_last(T data)
	{
		if (n == 0)
		{
			top = new node(data);
			bottom = top;
		}
		else
		{
			bottom->next = new node(data, bottom, NULL);
			bottom = bottom->next;
		}
		++n;
	}
	void insert(T data, int i)
	{
		if (i < 0 || i > n)
			return;
		if (i == 0)
			push_first(data);
		else if (i == n)
			push_last(data);
		else
		{
			node *temp = top;
			while (i != 0)
				temp = temp->next, --i;
			temp->prev->next = new node(data, temp->prev, temp);
			temp->prev = temp->prev->next;
			++n;
		}
	}
	void pop_first()
	{
		if (n == 0)
			return;
		node *temp = top;
		if (n == 1)
			top = bottom = NULL;
		else
		{
			top = top->next;
			top->prev = NULL;
		}
		free(temp);
		--n;
	}
	void pop_last()
	{
		if (n == 0)
			return;
		node *temp = bottom;
		if (n == 1)
			top = bottom = NULL;
		else
		{
			bottom = bottom->prev;
			bottom->next = NULL;
		}
		free(temp);
		--n;
	}
	void deletee(int i)
	{
		if (i < 0 || i >= n)
			return;
		if (i == 0)
			pop_first();
		else if (i == n - 1)
			pop_last();
		else
		{
			node *temp = top;
			while (i != 0)
				temp = temp->next, --i;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
			--n;
		}
	}
	T first()
	{
		if (n != 0)
			return top->data;
		// return;
	}
	T last()
	{
		if (n != 0)
			return bottom->data;
		// return;
	}
	T value(int i)
	{
		node *temp = top;
		while (i != 0)
			temp = temp->next, --i;
		return temp->data;
	}
	void display()
	{
		if (n == 0)
			return;
		node *temp = top;
		while (temp != bottom)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << temp->data << "  ";
		cout << "\n";
	}
};

int main()
{
	int t = 1;
	D_Linked_List<int> l1;
	while (t)
	{
		cout << "1.PushFirst  2.PushLast  3.Insert  4.PopFirst  5.PopLast  6.Delete  7.First  8.Last  9.Display  10.Done   : ";
		int wish;
		cin >> wish;
		switch (wish)
		{
		case 1:
		{
			cout << "Enter the data : ";
			int data;
			cin >> data;
			l1.push_first(data);
		}
		break;
		case 2:
		{
			cout << "Enter the data : ";
			int data;
			cin >> data;
			l1.push_last(data);
		}
		break;
		case 3:
		{
			cout << "Enter the data : ";
			int data;
			cin >> data;
			cout << "Enter the index : ";
			int i;
			cin >> i;
			l1.insert(data, i);
		}
		break;
		case 4:
			l1.pop_first();
			break;
		case 5:
			l1.pop_last();
			break;
		case 6:
		{
			cout << "Enter the index : ";
			int i;
			cin >> i;
			l1.deletee(i);
		}
		break;
		case 7:
			cout << "The First element is : " << l1.first() << "\n";
			break;
		case 8:
			cout << "The Last element is : " << l1.last() << "\n";
			break;
		case 9:
			l1.display();
			break;
		default:
			t = 0;
			break;
		}
	}
	return 0;
}