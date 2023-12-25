#include <iostream>

template <class T>
class stack
{
	struct node
	{
		T data;
		node *next;
		node(T data, node *root)
		{
			this->data = data;
			this->next = root;
		}
	};
	node *root = NULL;

public:
	bool empty()
	{
		if (root == NULL)
			return true;
		return false;
	}
	T top()
	{
		if (root != NULL)
			return root->data;
		T null;
		return null;
	}
	void push(T data)
	{
		root = new node(data, root);
	}
	void pop()
	{
		if (root == NULL)
			return;
		node *temp = root;
		root = root->next;
		free(temp);
	}
};