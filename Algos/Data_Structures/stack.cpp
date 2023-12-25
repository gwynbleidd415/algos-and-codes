#include <bits/stdc++.h>
using namespace std;

// template <class T>
// struct node
// {
// 	T data;
// 	node *prev;
// 	node(T data, node *prev = NULL)
// 	{
// 		this->data = data;
// 		this->prev = prev;
// 	}
// };

template <class T>
class Stack
{
	struct node
	{
		T data;
		node *prev;
		node(T data, node *prev = NULL)
		{
			this->data = data;
			this->prev = prev;
		}
	};

	node *top = NULL;
	int n = 0;

public:
	void push(T data)
	{
		top = new node(data, top);
		++n;
	}
	void pop()
	{
		if (n == 0)
			return;
		node *temp = top;
		top = top->prev;
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
			temp = temp->prev;
		}
		cout << "\n";
	}
};

int main()
{
	int t = 1;
	Stack<int> s1;
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
			s1.push(data);
			break;
		case 2:
			s1.pop();
			break;
		case 3:
			cout << "The top element is : " << s1.topp() << "\n";
			break;
		case 4:
			s1.display();
			break;
		default:
			t = 0;
			break;
		}
	}
	return 0;
}