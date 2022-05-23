/*Construct an expression tree from the given prefix expression eg. +--a*bc/def and traverse it using post order traversal(non recursive) and then delete the entire tree.*/
#include <iostream>
using namespace std;

struct node
{
	char data;
	struct node *left;
	struct node *right;
};

node* make_tree(string st)
{
	node* arr[1000];
	int top  = -1;
	int n = st.length();
	for(int i = 0;i<n;i++)
	{
		node* newnode = new node();
		newnode->data = st[i];
		newnode->left = NULL;
		newnode->right = NULL;
		if(st[i] == '+' || st[i] == '^' || st[i] == '*' || st[i] == '/' || st[i] == '-')
		{
			node* ptr1 = new node();
			node* ptr2 = new node();
			ptr1 = arr[top--];
			ptr2 = arr[top--];
			top++;
			newnode->left = ptr1;
			newnode->right = ptr2;
			arr[top] = newnode;
		}
		else
		{
			top++;
			arr[top] = newnode;
		}

	}
	return arr[top];
}

void postorder(struct node* n)
{
	node* stack1[1000];
	node* stack2[1000];
	int top1 = -1;
	int top2 = -1;
	if(n != NULL)
	{
		node* ptr = new node();
		top1++;
		stack1[top1] = n;
		while(top1 != -1)
		{
			ptr = stack1[top1--];
			top2++;
			stack2[top2] = ptr;
			if(ptr->left != NULL)
			{
				top1++;
				stack1[top1] = ptr->left;
			}
			if(ptr->right != NULL)
			{
				top1++;
				stack1[top1] = ptr->right;
			}
		}
		while(top2 != -1)
		{
			ptr = stack2[top2--];
			cout<<ptr->data<<" ";
		}
	}
}

void del(struct node** n)
{
	node* temp = new node;
	temp = (*n);
	if(temp == NULL)
		return;
	del(&temp->left);
	del(&temp->right);
	delete(temp);
}


int main()
{
	string str;
	cout<<"Enter the string : "<<endl;
	cin >> str;
	string st = "";
	for(int i = str.length()-1;i>=0;i--)
	{
		st = st + str[i];
	}

	node* n = new node();
	n = make_tree(st);
	cout<<"The post order is : "<<endl;
	postorder(n);
	cout<<endl;
	cout<<"The tree is deleted."<<endl;
	del(&n);


	return 0;
}
