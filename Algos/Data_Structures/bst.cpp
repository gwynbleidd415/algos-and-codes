#include <bits/stdc++.h>
using namespace std;

class bst
{
	struct node
	{
		int data;
		node *left, *right;
		node(int data)
		{
			this->data = data;
			left = right = NULL;
		}
	};
	node *root = NULL;
	int rem_next(node *rt)
	{
		if (rt->right == NULL)
			return INT_MIN;
		if (rt->right->left == NULL)
		{
			int temp = rt->right->data;
			node *temp1 = rt->right;
			rt->right = rt->right->right;
			free(temp1);
			return temp;
		}
		node *temp = rt->right;
		while (1)
			if (temp->left->left == NULL)
			{
				int tmp = temp->left->data;
				node *tmp1 = temp->left;
				temp->left = temp->left->right;
				free(tmp1);
				return tmp;
			}
			else
				temp = temp->left;
		return 0;
	}

public:
	bool search(int data)
	{
		node *temp = root;
		while (1)
		{
			if (temp == NULL)
				return false;
			if (temp->data == data)
				return true;
			if (temp->data > data)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	void insert(int data)
	{
		if (root == NULL)
			root = new node(data);
		else
		{
			node *temp = root;
			while (true)
				if (data < temp->data)
				{
					if (temp->left == NULL)
					{
						temp->left = new node(data);
						return;
					}
					temp = temp->left;
				}
				else
				{
					if (temp->right == NULL)
					{
						temp->right = new node(data);
						return;
					}
					temp = temp->right;
				}
		}
	}
	void deletee(int data)
	{
		if (root == NULL)
			return;
		if (root->data == data)
		{
			bool cc = false;
			node *temp = root;
			if (root->left == NULL)
				root = root->right, cc = true;
			else if (root->right == NULL)
				root = root->left, cc = true;
			else
				root->data = rem_next(root);
			if (cc)
				free(temp);
			return;
		}
		node *wr = root;
		node *par = root;
		while (1)
		{
			if (data < wr->data)
			{
				if (wr->left != NULL && wr->left->data == data)
				{
					int res = rem_next(wr->left);
					if (res == INT_MIN)
					{
						node *tempp = wr->left;
						wr->left = wr->left->left;
						free(tempp);
					}
					else
						wr->left->data = res;
					return;
				}
				else if (wr->left == NULL)
				{
					cout << "NOT FOUND\n";
					return;
				}
				else
					wr = wr->left;
			}
			else
			{
				if (wr->right != NULL && wr->right->data == data)
				{
					int res = rem_next(wr->right);
					if (res == INT_MIN)
					{
						node *tempp = wr->right;
						wr->right = wr->right->left;
						free(tempp);
					}
					else
						wr->right->data = res;
					return;
				}
				else if (wr->right == NULL)
				{
					cout << "NOT FOUND\n";
					return;
				}
				else
					wr = wr->right;
			}
		}
	}
	void display()
	{
		if (root == NULL)
			return;
		stack<node *> st;
		node *temp = root;
		while (1)
		{
			if (temp != NULL)
			{
				st.push(temp);
				temp = temp->left;
			}
			else
			{
				if (!st.empty())
				{
					node *ex = st.top();
					st.pop();
					cout << ex->data << " ";
					temp = ex->right;
				}
				else
					break;
			}
		}
		cout << "\n";
	}
};

int main()
{
	bst t;
	int c = 1;
	while (c)
	{
		cout << "Choose..\n1.Insert   2.Delete   3.Search   4.Display   5.Exit  : ";
		int wish;
		cin >> wish;
		int data = 5;
		if (wish < 4)
		{
			cout << "Enter the data : ";
			cin >> data;
		}
		switch (wish)
		{
		case 1:
			t.insert(data);
			break;
		case 2:
			t.deletee(data);
			break;
		case 3:
			cout << (t.search(data) ? "FOUND\n" : "NOT FOUND\n");
			break;
		case 4:
			t.display();
			break;
		default:
			c = 0;
		}
	}
	return 0;
}