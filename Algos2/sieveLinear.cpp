#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class lList
{
	node *top = NULL, *bottom = NULL;

public:
	void push(int data)
	{
		if (top == NULL)
		{
			top = new node(data);
			bottom = top;
			return;
		}
		bottom->next = new node(data);
		bottom = bottom->next;
	}
	node *topp()
	{
		return top;
	}
};

int main()
{
	int n;
	cout << "Enter the number : ";
	cin >> n;
	bool arr[n + 1];
	int spf[n + 1];
	lList prime;
	for (int i = 2; i <= n; ++i)
		arr[i] = true;
	arr[0] = arr[1] = false;
	for (int i = 2; i <= n; ++i)
	{
		if (arr[i])
		{
			spf[i] = i;
			prime.push(i);
		}
		node *temp = prime.topp();
		for (; temp != NULL && temp->data <= spf[i] && temp->data * i <= n; temp = temp->next)
		{
			spf[temp->data * i] = temp->data;
			arr[temp->data * i] = false;
		}
	}
	for (int i = 0; i <= n; ++i)
		if (arr[i] == true)
			cout << i << ", ";
	cout << "\n";
	return 0;
}