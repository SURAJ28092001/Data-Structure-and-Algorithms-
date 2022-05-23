//============================================================================
// Name        : Programs.cpp
// Author      : Suraj Joshi
// Version     : 2.0
// Copyright  : Your copyright notice
// Description : Hello World!!! in C++, Ansi-style
//============================================================================
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void inOrder(node* root)
{
	if(root == NULL)
		return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

class BST_tree
{
	struct node* root;
public:
	node* get_root()
	{
		return root;
	}
	BST_tree()
	{
		root = NULL;
	}

	void insert(int data)
	{
		struct node* newnode = new node();
		newnode->data = data;
		newnode->right = NULL;
		newnode->left = NULL;
		if(root == NULL)
		{
			root = newnode;
			return;
		}
		else
		{
			struct node* temp = new node();
			temp = root;
			while(temp->left != NULL || temp->right != NULL)
			{
				if(temp->data > data)
				{
					if(temp->left == NULL)
					{
						temp->left = newnode;
						return;
					}
					temp = temp->left;
				}
				else
				{
					if(temp->right == NULL)
					{
						temp->right = newnode;
						return;
					}
					temp = temp->right;
				}
			}
			if(temp->data > data)
			{
				temp->left = newnode;
			}
			else
				temp->right = newnode;
		}
	}


	void mirror_tree(node* root)
	{
		if(root == NULL)
			return;
		mirror_tree(root->left);
		mirror_tree(root->right);
		struct node* temp = new node();
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}



};

int find_min(struct node *root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
}

int height(node* root)
{
	if(root == NULL)
		return 0;
	int left_height = height(root->left);
	int right_height = height(root->right);
	if(left_height > right_height)
		return left_height + 1;
	else
		return right_height + 1;
}

bool searcher(struct node* root,int data)
{
	if(root == NULL)
	{
		return false;
	}
	else
	{
		while(root != NULL)
		{
			if(root->data == data)
			{
				return true;
			}
			else
			{
				if(root->data > data)
				{
					root = root->left;
				}
				else if(root->data < data)
				{
					root = root->right;
				}
			}
		}
		return false;
	}
}

int main()
{
	struct node* root;
	root = NULL;
	root = new node();
	int c;
	int data,search_ele;
	BST_tree obj;
	do
	{
		cout<<"-----------------------------------------------------------------------------"<<endl;
		cout<<"Press 1 to insert data : "<<endl;
		cout<<"Press 2 to find the number of nodes in the binary search tree : "<<endl;
		cout<<"Press 3 to find the node with the minimum value : "<<endl;
		cout<<"Press 4 to make it a mirror tree :"<<endl;
		cout<<"Press 5 to search a value : "<<endl;
		cout<<"Press 6 to display the tree : "<<endl;
		cout<<"Press 0 to exit"<<endl;
		cout<<"-----------------------------------------------------------------------------"<<endl;
		cin >> c;
		switch(c)
		{
		case 1:
			cout<<"Enter the data : "<<endl;
			cin >> data;
			obj.insert(data);
			cout<<"Data entered successfully."<<endl;
			break;
		case 2:
			root = new node();
			root = obj.get_root();
			cout<<"The maximum number of nodes in the trees are : "<<height(root)<<endl;
			break;
		case 3:
			root = obj.get_root();
			cout<<"The node with the minimum value is : "<<find_min(root)<<endl;
			break;
		case 4:
			obj.mirror_tree(obj.get_root());
			cout<<"The reversed tree is : "<<endl;
			inOrder(obj.get_root());
			cout<<endl;
			break;
		case 5:
			cout<<"Enter the element to be searched : "<<endl;
			cin >> search_ele;
			root = obj.get_root();
			if(searcher(root,search_ele))
				cout<<"The element is present in the BST."<<endl;
			else
				cout<<"The element is not present in the BST."<<endl;
			break;
		case 6:
			root = new node();
			root = obj.get_root();
			cout<<"The data in the tree is : "<<endl;
			inOrder(root);
			cout<<endl;
			break;
		case 0:
			cout<<"Exited."<<endl;
			break;
		default:
			cout<<"Invalid Number !!! Please try again."<<endl;
		}
	}while(c != 0);

	return 0;
}
