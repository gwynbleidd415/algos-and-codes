#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue
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
			top = top->next;
		free(temp);
		--n;
	}
	T topp()
	{
		return top->data;
	}
	void display()
	{
		node *temp = top;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << "\n";
	}
};

int main()
{
	int t = 1;
	Queue<int> q1;
	while (t)
	{
		cout << "1. Push   2. Pop   3. Top   4. Display   5. Done   : ";
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
		default:
			t = 0;
			break;
		}
	}
	return 0;
}