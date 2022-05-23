/*A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes. Find the time and space requirements of your method.*/
#include<iostream>
using namespace std;

struct node
{
	string data;
	struct node *left;
	struct node *right;
};

struct node* insert(struct node **q,string data)
{
	struct node* temp = new node();
	temp = *q;
	struct node* newnode = new node();
	if(temp->left == NULL)
	{
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		temp->left = newnode;
	}
	else
	{
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		temp->right = newnode;
	}
	return newnode;
}

void display(struct node *root)
{
	if(root == NULL)
		return;
	cout<<root->data<<endl;
	display(root->left);
	display(root->right);
}


int main()
{
	struct node *book = new node();
	struct node *chap = new node();
	struct node *sec = new node();
	struct node *sub_sec = new node();
	string book_name, chapter,section,sub_section;
	cout<<"Enter the book name : ";
	getline(cin,book_name);
	book->data = book_name;
	book->left = NULL;
	book->right = NULL;
	for(int i = 0;i<2;i++)
	{
		cout<<"Enter the chapter name : ";
		getline(cin,chapter);
		chap = insert(&book,chapter);
		for(int j = 0;j<2;j++)
		{
			cout<<"Enter the "<<chapter<<"'s section name : ";
			getline(cin,section);
			sec = insert(&chap,section);
			for(int k = 0;k<2;k++)
			{
				cout<<"Enter the "<<section<<"'s subsection name : ";
				getline(cin,sub_section);
				sub_sec = insert(&sec,sub_section);
			}
		}
	}
	cout<<"The data in the tree is : "<<endl;
	display(book);

	return 0;
}
