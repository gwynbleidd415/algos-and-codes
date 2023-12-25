#include <bits/stdc++.h>
using namespace std;

class avl
{
	struct node
	{
		int data, height;
		node *left, *right;
		node(int data)
		{
			this->data = data;
			left = right = NULL;
			height = 0;
		}
	};
	int calcHeight(node *root)
	{
		if (root->left == NULL && root->right == NULL)
			return 0;
		if (root->left == NULL)
			return root->right->height + 1;
		if (root->right == NULL)
			return root->left->height + 1;
		return max(root->left->height, root->right->height) + 1;
	}
	int getBalance(node *root)
	{
		if (root->left == NULL && root->right == NULL)
			return 0;
		if (root->left == NULL)
			return -(root->right->height + 1);
		if (root->right == NULL)
			return root->left->height + 1;
		return root->left->height - root->right->height;
	}
	node *rrotate(node *root)
	{
		node *temp = root->left;
		root->left = root->left->right;
		temp->right = root;
		root->height = calcHeight(root);
		temp->height = calcHeight(temp);
		return temp;
	}
	node *lrotate(node *root)
	{
		node *temp = root->right;
		root->right = root->right->left;
		temp->left = root;
		root->height = calcHeight(root);
		temp->height = calcHeight(temp);
		return temp;
	}
	node *codeInsert(node *root, int data)
	{
		if (root == NULL)
			return new node(data);
		if (root->data < data)
			root->right = codeInsert(root->right, data);
		else
			root->left = codeInsert(root->left, data);
		root->height = calcHeight(root);
		int r = getBalance(root);
		if (r > 1)
			if (data < root->left->data)
				return rrotate(root);
			else
			{
				root->left = lrotate(root->left);
				return rrotate(root);
			}
		if (r < -1)
			if (data > root->right->data)
				return lrotate(root);
			else
			{
				root->right = rrotate(root->right);
				return lrotate(root);
			}
		return root;
	}
	node *findNext(node *root)
	{
		node *temp = root;
		while (temp->left != NULL)
			temp = temp->left;
		return temp;
	}
	node *codeDelete(node *root, int data)
	{
		if (root == NULL)
		{
			cout << "NOT FOUND\n";
			return NULL;
		}
		if (root->data < data)
			root->right = codeDelete(root->right, data);
		else if (root->data > data)
			root->left = codeDelete(root->left, data);
		else
		{
			if (root->left == NULL || root->right == NULL)
			{
				node *temp = root->left ? root->left : root->right;
				free(root);
				return temp;
			}
			node *temp = findNext(root->right);
			root->data = temp->data;
			root->right = codeDelete(root->right, temp->data);
		}
		root->height = calcHeight(root);
		int r = getBalance(root);
		if (r > 1)
			if (getBalance(root->left) > 1)
				return rrotate(root);
			else
			{
				root->left = lrotate(root->left);
				return rrotate(root);
			}
		if (r < -1)
			if (getBalance(root->right) < -1)
				return lrotate(root);
			else
			{
				root->right = rrotate(root->right);
				return lrotate(root);
			}
		return root;
	}
	void codeInorder(node *root)
	{
		if (root == NULL)
			return;
		codeInorder(root->left);
		cout << root->data << " ";
		codeInorder(root->right);
	}
	node *root = NULL;

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
			if (temp->data < data)
				temp = temp->right;
			else
				temp = temp->left;
		}
		return 0;
	}
	void insert(int data)
	{
		if (root == NULL)
			root = new node(data);
		else
			root = codeInsert(root, data);
	}
	void deletee(int data)
	{
		if (root == NULL)
			cout << "NOT FOUND\n";
		else
			root = codeDelete(root, data);
	}
	void inorder()
	{
		if (root == NULL)
			return;
		codeInorder(root);
		cout << "\n";
	}
};

int main()
{
	int c = 1;
	avl t;
	while (c)
	{
		cout << "Choose..\n1.Insert   2.Search   3.Delete   4.Display   5.Exit  : ";
		int wish;
		cin >> wish;
		int data;
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
			cout << (t.search(data) ? "FOUND\n" : "NOT FOUND\n");
			break;
		case 3:
			t.deletee(data);
			break;
		case 4:
			t.inorder();
			break;
		default:
			c = 0;
		}
	}
	return 0;
}