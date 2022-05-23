/*#include <iostream>
using namespace std;

struct node
{
	string key;
	string meaning;
	struct node* left;
	struct node* right;
};

class avl_tree
{
	node* root;
public:
	avl_tree()
	{
		root = new node;
		root = NULL;
	}

	node* left_rotation(node* x)
	{
		node* y = new node;
		node* z = new node;
		y->left = z->left = y->right = z->right = NULL;
		y = x->right;
		z = y->left;

		x->right = z;
		y->left = x;
		return y;
	}

	node* right_rotation(node* x)
	{
		node* y = new node;
		node* z = new node;
		y->left = z->left = y->right = z->right = NULL;

		y = x->left;
		z = y->right;

		x->left = z;
		y->right = x;
		return y;

	}

	int height(node* t)
	{
		if(t == NULL)
			return 0;
		int l = height(t->left);
		int r = height(t->right);
		if(l > r)
			return l+1;
		return r+1;
	}

	int difference(node* t)
	{
		int l = height(t->left);
		int r = height(t->right);
		int d = l - r;
		return d;
	}

	void insert(string keyword,string meaning)
	{
		bool flag = false;
			struct node* newnode = new node();
			newnode->key = keyword;
			newnode->meaning = meaning;
			newnode->right = NULL;
			newnode->left = NULL;
			if(root == NULL)
			{
				root = newnode;
				flag = true;
				return;
			}
			else
			{
				struct node* temp = new node();
				temp = root;
				while(temp->left != NULL || temp->right != NULL)
				{
					if((keyword).compare(temp->key) < 0)
					{
						if(temp->left == NULL)
						{
							temp->left = newnode;
							flag = true;
							break;
						}
						temp = temp->left;
					}
					else if((keyword).compare(temp->key) > 0)
					{
						if(temp->right == NULL)
						{
							temp->right = newnode;
							flag = true;
							break;
						}
						temp = temp->right;
					}
				}
				if(!flag)
				{
					if((keyword).compare(temp->key) < 0)
					{
						temp->left = newnode;
					}
					else
					{
						temp->right = newnode;
					}
				}
			}

			int balance = difference(root);
			if(balance > 1 && (keyword).compare(root->left->key) < 0)
			{
				root = right_rotation(root);
			}
			else if(balance < -1 && (keyword).compare(root->right->key) > 0)
			{
				root = left_rotation(root);
			}
			else if(balance < -1 && (keyword).compare(root->right->key) < 0)
			{
				root->right = right_rotation(root->right);
				root = left_rotation(root);
			}
			else if(balance > 1 && (keyword).compare(root->left->key) > 0)
			{
				root->left = left_rotation(root->left);
				root = right_rotation(root);
			}
	}

	node* get_root()
	{
		return root;
	}

	node* get_inorder(node* temp)
	{
		node* old = new node;
		old = temp;
		temp = temp->right;
		while(temp->left != NULL)
		{
			old = temp;
			temp = temp->left;
		}
		if(old->left == temp)
			old->left = NULL;
		else
			old->right = NULL;
		return temp;
	}

	void del_node_with_two_child(node* temp,node* old)
	{
		node* successor = new node;
		successor = get_inorder(temp);
		temp->key = successor->key;
		temp->meaning = successor->meaning;
		delete(successor);
		cout<<"Delete with two child"<<endl;
	}

	void del(node* temp,node* old)
	{
		if(temp->left == NULL && temp->right == NULL)
		{
			if(old->left == temp)
				old->left = NULL;
			else
				old->right = NULL;
			delete(temp);
			cout<<"Delete with no child"<<endl;
			return;
		}
		else if(temp->left != NULL && temp->right == NULL)
		{
			if(old->left == temp)
				old->left = temp->left;
			else
				old->right = temp->left;
			return;
		}
		else if(temp->left == NULL && temp->right != NULL)
		{
			if(old->left == temp)
				old->left = temp->right;
			else
				old->right = temp->right;
		}
		cout<<"Delete with one child"<<endl;
	}

	void finder(string keyword)
	{
		node* temp = new node;
		temp = root;
		node* old = new node;
		old = NULL;
		while(temp != NULL)
		{
			if(keyword.compare(temp->key) == 0)
			{
				if(temp->right != NULL && temp->left != NULL)
					del_node_with_two_child(temp,old);
				else if(old == NULL)
				{
					if(temp->right != NULL)
						root = temp->right;
					else if(temp->left != NULL)
						root = temp->left;
					else
						root = NULL;
					delete(temp);
				}
				else
					del(temp,old);
				return;
			}
			else if(keyword.compare(temp->key) < 0)
			{
				old = temp;
				temp = temp->left;
			}
			else
			{
				old = temp;
				temp = temp->right;
			}
		}
		cout<<"No such keyword found."<<endl;
	}

	void update(string keyword,string meaning)
	{
		node* temp = new node;
		temp = root;
		while(temp != NULL)
		{
			if(keyword.compare(temp->key) == 0)
			{
				temp->meaning = meaning;
				return;
			}
			else if(keyword.compare(temp->key) < 0)
			{
				temp = temp->left;
			}
			else
			{
				temp = temp->right;
			}
		}
	}
};


void get_child(node* root,string keyword)
{
	if(root == NULL)
		return;
	while(root != NULL)
	{
		if(keyword.compare(root->key) == 0)
		{
			if(root->left == NULL && root->right == NULL)
				cout<<"0 child"<<endl;
			else if((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
				cout<<"1 child"<<endl;
			else
				cout<<"2 children"<<endl;
			return;
		}
		else if(keyword.compare(root->key) < 0)
		{
			root = root->left;
		}
		else
		{
			root = root->right;
		}
	}
	cout<<"The word is not there."<<endl;
}

void display(node* root)
{
	if(root == NULL)
		return;
	display(root->left);
	cout<<"--------------------------"<<endl;
	cout<<root->key<<endl;
	cout<<root->meaning<<endl;
	cout<<"--------------------------"<<endl;
	display(root->right);
}

void get_meaning(node* root,string keyword)
{
	if(root == NULL)
		return;
	while(root != NULL)
	{
		if(keyword.compare(root->key) == 0)
		{
			cout<<"The meaning of the word is  : "<<root->meaning<<endl;
			return;
		}
		else if(keyword.compare(root->key) < 0)
		{
			root = root->left;
		}
		else
		{
			root = root->right;
		}
	}
	cout<<"The word is not there."<<endl;
}

int main()
{
	string keyword;
	string meaning;
	int ch;
	avl_tree root;
	do{
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"Press 1 to enter a new word."<<endl;
	cout<<"Press 2 to get the meaning of a word."<<endl;
	cout<<"Press 3 to delete a word."<<endl;
	cout<<"Press 4 to update the meaning of a word."<<endl;
	cout<<"Press 5 to get the whole dictionary."<<endl;
	cout<<"Press 6 to get the children of a node."<<endl;
	cout<<"Press 0 to exit."<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cin >> ch;
	switch(ch)
	{
	case 1:
		cout<<"Enter the keyword : "<<endl;
		cin.ignore();
		getline(cin,keyword);
		cout<<"Enter the meaning of "<<keyword<<" : "<<endl;
		getline(cin,meaning);
		root.insert(keyword, meaning);
		cout<<"Keyword added."<<endl;
		break;
	case 2:
		cout<<"Enter the word : ";
		cin.ignore();
		getline(cin,keyword);
		get_meaning(root.get_root(),keyword);
		break;
	case 3:
		cout<<"Enter the keyword : ";
		cin.ignore();
		getline(cin,keyword);
		root.finder(keyword);
		cout<<"The keyword "<<keyword<<" is deleted."<<endl;
		break;
	case 4:
		cout<<"Enter the keyword whose meaning is to be changed : ";
		cin.ignore();
		getline(cin,keyword);
		cout<<"Enter the new meaning of "<<keyword<<" : ";
		getline(cin,meaning);
		root.update(keyword, meaning);
		cout<<"The meaning is changed."<<endl;
		break;
	case 5:
		display(root.get_root());
		break;
	case 6:
		cout<<"Enter the keyword : ";
		cin.ignore();
		getline(cin,keyword);
		get_child(root.get_root(),keyword);
		break;
	case 0:
		cout<<"Exited"<<endl;
		break;
	default:
		cout<<"Invalid Choice !!! Please try again.";
		break;
	}
	}while(ch != 0);
	return 0;
}

*/
