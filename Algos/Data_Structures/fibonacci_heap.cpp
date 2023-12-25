#include <bits/stdc++.h>
using namespace std;

template <class T>
class Fibonacci_Heap
{
	struct node
	{
		T data;
		bool marked;
		int degrees;
		node *left, *right, *parent, *child;
		node(T data)
		{
			this->data = data;
			marked = false;
			degrees = 0;
			parent = child = NULL;
			left = right = this;
		}
	};
	node *root = NULL;
	int n = 0;
	int nroot = 0;

	node *unionn(node *root1, node *root2)
	{
		root1->right->left = root2->left;
		root2->left->right = root1->right;
		root1->right = root2;
		root2->left = root1;
		if (root1->data <= root2->data)
			return root1;
		return root2;
	}

public:
	void push(T data)
	{
		node *roottemp = new node(data);
		if (root == NULL)
			root = roottemp;
		else
			root = unionn(root, roottemp);
		++nroot;
		++n;
	}
	T minm()
	{
		return root->data;
	}
	void pop()
	{
		if (root == NULL)
			return;
		else
		{
			int deg = root->degrees;
			if (root->child != NULL)
			{
				node *temp = root->child->right;
				while (temp != root->child)
				{
					temp->parent = NULL;
					temp = temp->right;
					++nroot;
				}
				temp->parent = NULL;
				root->left->right = temp->right;
				temp->right->left = root->left;
				temp->right = root->right;
				root->right->left = temp;
				free(root);
				root = temp;
			}
			else
			{
				if (root == root->left)
				{
					free(root);
					root = NULL;
					--nroot;
					--n;
					return;
				}
				else
				{
					root->left->right = root->right;
					root->right->left = root->left;
					node *temp = root;
					root = root->right;
					free(temp);
					--nroot;
				}
			}
			int size = log(n) + 1;
			node *arr[size];
			for (int i = 0; i <= size; ++i)
				arr[i] = NULL;
			node *temp = root;
			int marked = 0;
			while (marked < nroot)
			{
				if (arr[temp->degrees] == NULL)
				{
					arr[temp->degrees] = temp;
					temp = temp->right;
					++marked;
				}
				else if (arr[temp->degrees] == temp)
				{
					temp = temp->right;
				}
				else
				{
					node *temp1, *temp2;
					if ((arr[temp->degrees])->data <= temp->data)
					{
						temp1 = arr[temp->degrees];
						temp2 = temp;
					}
					else
					{
						temp1 = temp;
						temp2 = arr[temp->degrees];
					}
					temp2->left->right = temp2->right;
					temp2->right->left = temp2->left;
					temp2->right = temp2->left = temp2;
					if (temp1->child == NULL)
						temp1->child = temp2;
					else
						temp1->child = unionn(temp2, temp1->child);
					temp2->parent = temp1;
					temp1->degrees += 1;
					arr[temp2->degrees] = NULL;
					temp = temp1;
					--nroot;
					--marked;
				}
			}
			root = temp;
			for (int i = 0; i < size; ++i)
				if (arr[i] != NULL && (arr[i])->data < root->data)
					root = arr[i];
		}
		--n;
	}
	node *find_key(T key)
	{
		if (root == NULL)
			return NULL;
		if (root->data == key)
			return root;
		node *temp = root->right;
		stack<node *> st;
		if (root->data < key)
			st.push(root);
		while (temp != root)
		{
			if (temp->data == key)
				return temp;
			if (temp->data < key)
				st.push(temp);
			temp = temp->right;
		}
		while (!st.empty())
		{
			node *temp1 = st.top();
			st.pop();
			if (temp1->child != NULL)
			{
				temp1 = temp1->child;
				if (temp1->data == key)
					return temp1;
				if (temp1->data < key)
					st.push(temp1);
				node *temp2 = temp1->right;
				while (temp2 != temp1)
				{
					if (temp2->data == key)
						return temp2;
					if (temp2->data < key)
						st.push(temp2);
					temp2 = temp2->right;
				}
			}
		}
		return NULL;
	}
	void cut_join(node *keyv)
	{
		if (keyv->right == keyv)
			keyv->parent->child = NULL;
		else
		{
			node *mchild = keyv->right;
			node *temp = mchild->right;
			while (temp != keyv)
			{
				if (temp->data < mchild->data)
					mchild = temp;
				temp = temp->right;
			}
			keyv->parent->child = mchild;
			keyv->right->left = keyv->left;
			keyv->left->right = keyv->right;
			keyv->left = keyv->right = keyv;
		}
		keyv->parent = NULL;
		root = unionn(root, keyv);
		++nroot;
	}
	void decrease_key(T key, T value)
	{
		if (value >= key)
		{
			cout << "Sorry key can only be decreased\n";
			return;
		}
		else if (root == NULL)
			return;
		else
		{
			node *keyv = find_key(key);
			if (keyv == NULL)
			{
				cout << "key not found\n";
				return;
			}
			keyv->data = value;
			if (keyv->parent == NULL)
			{
				if (keyv->data < root->data)
					root = keyv;
				return;
			}
			if (keyv->parent->data <= keyv->data)
			{
				if (keyv->data < keyv->parent->child->data)
					keyv->parent->child = keyv;
				return;
			}
			if (keyv->parent->marked == false)
			{
				keyv->parent->marked = true;
				cut_join(keyv);
				return;
			}
			node *par = keyv->parent;
			cut_join(keyv);
			while (true)
			{
				if (par->parent != NULL)
				{
					node *par1 = par->parent;
					cut_join(par);
					if (par1->marked == false)
					{
						par1->marked = true;
						break;
					}
					par = par1;
				}
				else
					break;
			}
		}
	}
	void delete_key(T key)
	{
		if (root == NULL)
			return;
		node *keyv = find_key(key);
		if (keyv == NULL)
			return;
		decrease_key(keyv->data, INT_MIN);
		pop();
	}
	void display()
	{
		if (root == NULL)
			return;
		node *temp = root->right;
		stack<node *> st;
		st.push(root);
		while (temp != root)
		{
			st.push(temp);
			temp = temp->right;
		}
		while (!st.empty())
		{
			node *temp1 = st.top();
			cout << temp1->data << "\t";
			st.pop();
			if (temp1->child != NULL)
			{
				node *temp2 = temp1->child;
				st.push(temp2);
				temp2 = temp2->right;
				while (temp2 != temp1->child)
				{
					st.push(temp2);
					temp2 = temp2->right;
				}
			}
		}
	}
};

int main()
{
	int t = 1;
	Fibonacci_Heap<int> fh;
	while (t)
	{
		cout << "1.Push  2.Pop  3.Minimum  4.Decrease  5.Delete  6.Display  7.Done : ";
		int wish;
		cin >> wish;
		switch (wish)
		{
		case 1:
		{
			cout << "Enter the data : ";
			int data;
			cin >> data;
			fh.push(data);
		}
		break;
		case 2:
			fh.pop();
			break;
		case 3:
			cout << "The min value is : " << fh.minm() << "\n";
			break;
		case 4:
		{
			int key, value;
			cout << "Enter the key value : ";
			cin >> key;
			cout << "Enter the decreased value : ";
			cin >> value;
			fh.decrease_key(key, value);
		}
		break;
		case 5:
		{
			int key;
			cout << "Enter the key value : ";
			cin >> key;
			fh.delete_key(key);
		}
		break;
		case 6:
			fh.display();
			cout << "\n";
			break;
		default:
			t = 0;
		}
	}
	return 0;
}