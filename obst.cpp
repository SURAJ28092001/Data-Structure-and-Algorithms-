/*#include <iostream>
using namespace std;

struct node
{
	string data;
	struct node *left;
	struct node *right;
};

int weight_calc(int w[5][5],int P[5],int Q[5])
{
	for(int i = 0;i<5;i++)
	{
		for(int j = i+1;j<5;j++)
		{
			w[i][j] = w[i][j-1] + P[j-1] + Q[j];
		}
	}
	return w[5][5];
}

int c_calc(int c[5][5],int w[5][5])
{
	double min = 1000000;
		double sum = 0;
		int min_r = 0;
		int count = 1;
		while(count != 5)
		{
			min = 1000000;
			min_r = 0;
			for(int i = 0;i<(5-count);i++)
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
				}
				c[i][i+count] = min + w[i][i+count];
			}
			count++;
		}
		return c[5][5];
}

int r_calc(int c[5][5],int w[5][5],int r[5][5])
{
	double min = 1000000;
	double sum = 0;
	int min_r = 0;
	int count = 1;
	while(count != 5)
	{
		min = 1000000;
		min_r = 0;
		for(int i = 0;i<(5-count);i++)
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
			}
			r[i][i+count] = min_r;
		}
		count++;
	}
	return r[5][5];
}


	node* make_tree(int r[5][5],string q[],int ind1,int ind2,int v[])
	{
		node *temp = new node;
		if(ind1 == ind2)
		{
			temp = NULL;
			return temp;
		}
		int index = r[ind1][ind2];
		if(v[index-1] == -1)
		{
			v[index-1] = 1;
			temp->data = q[index-1];
			temp->left = make_tree(r,q,ind1,index-1,v);
			temp->right = make_tree(r,q,index,ind2,v);
		}
		else
		{
			temp = NULL;
		}
		return temp;
	}



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
	postorder(root->left);
	cout<<root->data<<" ";
	postorder(root->right);
}

int main()
{
	/*
	double *P,*Q;
	int *v;
	string *q;
	int n;
	cout<<"Enter the number of elements : ";
	cin >> n;
	int n1 = n+1;
	P = new double[n];
	Q = new double[n1];
	v = new int[n];
	q = new string[n];

	double w[n1][n1],c[n1][n1];
	int r[n1][n1];

	cout<<"Enter the elements : "<<endl;
	for(int i = 0;i<n;i++)
	{
		cout<<"q["<<i<<"] : ";
		cin >> q[i];
		v[i] = -1;
	}
	cout<<"Enter the probabilities of successful search : "<<endl;
	for(int i = 0;i<n;i++)
	{
		cout<<"P["<<i<<"] for "<<q[i]<<" : ";
		cin >> P[i];
	}
	cout<<"Enter the probabilities of unsuccessful search : "<<endl;
	for(int i = 0;i<n1;i++)
	{
		cout<<"Q["<<i<<"] : ";
		cin >> Q[i];
		w[i][i] = Q[i];
		c[i][i] = 0;
		r[i][i] = 0;
		if((i+1) != n1)
			r[i][i+1] = i+1;
	}
	for(int i = 0;i<n1;i++)
	{
		for(int j = i+1;j<n1;j++)
		{
			w[i][j] = w[i][j-1] + P[j-1] + Q[j];
		}
	}

	double min = 1000000;
	double sum = 0;
	int min_r = 0;
	int count = 1;
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
			}
			c[i][i+count] = min + w[i][i+count];
			r[i][i+count] = min_r;
		}
		count++;
	}

	tree obj(n1);
	int *p = *r;
	obj.r = &p;
	obj.display();
	node* root = new node;
	root = obj.make_tree(q, 0, n, v);

	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	inorder(root);

*//*


	int P[] = {3,3,1,1};
	int Q[] = {2,3,1,1,1};
	string q[] = {"do","if","int","while"};
	int v[] = {-1,-1,-1,-1};
	int w[5][5],c[5][5],r[5][5];
	for(int i = 0;i<5;i++)
	{
		w[i][i] = Q[i];
		c[i][i] = 0;
		r[i][i] = 0;
		if((i+1) != 5)
			r[i][i+1] = i+1;
	}
	w[5][5] = weight_calc(w,P,Q);
	c[5][5] = c_calc(c,w);
	r[5][5] = r_calc(c,w,r);
	node* root = new node;
	root = make_tree(r,q,0,4,v);
	preorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	inorder(root);

	return 0;
}
*/
