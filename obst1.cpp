/*#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

int w(int i,int j,int freq[])
{
	int sum = 0;
	for(int n = i;n<=j;n++)
	{
		sum = sum + freq[n];
	}
	return sum;
}

class tree
{

	node* make_tree(void *r,int key[],int ind1,int ind2,int v[],int n1)
	{
		node *temp = new node;
		int (*R)[n1][n1] = (int (*)[n1][n1]) r;
		if(ind1 == ind2)
		{
			temp = NULL;
			return temp;
		}
		int index = (*R)[ind1][ind2];
		if(v[index-1] == -1)
		{
			v[index-1] = 1;
			temp->data = key[index-1];
			temp->left = make_tree(r,key,ind1,index-1,v,n1);
			temp->right = make_tree(r,key,index,ind2,v,n1);
		}
		else
		{
			temp = NULL;
		}
		return temp;
	}
public:
	node* c_and_r_calc(int key[4],int freq[4],int n1)
	{
		int c[n1][n1],r[n1][n1];
		int v[n1];
		int min = 1000000;
		int min_r = 0;
		int count = 1;
		int sum = 0;

		for(int i = 0;i<n1;i++)
		{
			for(int j = 0;j<n1;j++)
			{
				if(i == j)
				{
					c[i][j] = 0;
					r[i][j] = 0;
				}
				else if((j-i) == 1)
					c[i][j] = freq[i];

			}
			v[i] = -1;
		}
		int j = 0;

		while(count != n1)
		{
			min = 1000000;
			min_r = 0;
			for(int i = 0;i<(n1-count);i++)
			{
				min = 1000000;
				min_r = 0;
				for(int k = i+1;k<=i+count;k++)
				{
					sum = c[i][k-1] + c[k][i+count];
					if(sum < min)
					{
						min = sum;
						if((i+count)-i != 1)
							min_r = k;  //depends on value of k where we got the minimum
						else
							min_r = i+count;
					}
					j = k;
				}
				c[i][i+count] = min + w(i,j-1,freq);
				r[i][i+count] = min_r;
			}
			count++;
		}
		/*for(int i = 0;i<n1;i++)
		{
			for(int j = i;j<n1;j++)
				cout<<"c["<<i<<"]["<<j<<"] : "<<c[i][j]<<endl;
		}
		for(int i = 0;i<n1;i++)
		{
			for(int j = i;j<n1;j++)
				cout<<"r["<<i<<"]["<<j<<"] : "<<r[i][j]<<endl;
		}*//*
		return make_tree(r,key,0,n1-1,v,n1);

		}


};


void preorder(node *root)
{
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(node *root)
{
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void inorder(node *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}


int main()
{
	/*
	int key[] = {10,20,30,40};
	int freq[] = {4,2,6,3};
	node* root = new node;
	tree obj;
	root = obj.c_and_r_calc(key,freq);

	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;

	*//*

	int n,n1;
	cout<<"Enter the number of elements : ";
	cin >> n;
	n1 = n + 1;
	int key[n];
	int freq[n];

	cout<<"Enter the elements : "<<endl;
	for(int i = 0;i<n;i++)
	{
		cout<<"Enter the key["<<i<<"] : ";
		cin >> key[i];
	}
	for(int i = 0;i<n;i++)
	{
		cout<<"Enter the frequency of "<<key[i]<<" : ";
		cin >> freq[i];
	}

	tree obj;
	node* root = new node;
	root = obj.c_and_r_calc(key, freq,n1);
	cout<<"Preorder of the tree is : ";
	preorder(root);
	cout<<endl;
	cout<<"Postorder of the tree is : ";
	postorder(root);
	cout<<endl;
	cout<<"Inorder of the tree is : ";
	inorder(root);
	cout<<endl;


	return 0;
}
*/
