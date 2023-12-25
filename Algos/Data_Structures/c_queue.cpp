#include <bits/stdc++.h>
using namespace std;

template <class T>
class C_Queue
{
	struct node
	{
		T data;
		node *next = NULL;
		node(T data)
		{
			this->data = data;
		}
	};

	node *top = NULL;
	node *bottom = NULL;
	int n = 0;

public:
	void push(T data)
	{
		if (n == 0)
		{
			top = new node(data);
			bottom = top;
		}
		else
		{
			bottom->next = new node(data);
			bottom = bottom->next;
		}
		bottom->next = top;
		++n;
	}
	void pop()
	{
		if (n == 0)
			return;
		node *temp = top;
		if (n == 1)
			top = bottom = NULL;
		else
		{
			top = top->next;
			bottom->next = top;
		}
		free(temp);
		--n;
	}
	void skip()
	{
		if (n < 2)
			return;
		bottom = bottom->next;
		top = top->next;
	}
	T topp()
	{
		return top->data;
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
	C_Queue<int> q1;
	while (t)
	{
		cout << "1. Push   2. Pop   3. Top   4. Display   5. Skip   6. Done   : ";
		int wish;
		cin >> wish;
		switch (wish)
		{
		case 1:
			cout << "Enter the data : ";
			int data;
			cin >> data;
			q1.push(data);
			break;
		case 2:
			q1.pop();
			break;
		case 3:
			cout << "The top element is : " << q1.topp() << "\n";
			break;
		case 4:
			q1.display();
			break;
		case 5:
			q1.skip();
			break;
		default:
			t = 0;
			break;
		}
	}
	return 0;
}