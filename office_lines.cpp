/*#include <iostream>
#include <map>
using namespace std;

struct node
{
	string city;
	int weight;
	node* nxt;
};

void insert(struct node **q,string name,int wt)
{
	node* temp = new node;
	node* newnode = new node;
	temp = *q;
	while(temp->nxt != NULL)
	{
		temp = temp->nxt;
	}
	newnode->city = name;
	newnode->nxt = NULL;
	newnode->weight = wt;
	temp->nxt = newnode;
}

void prims(node* vertices[], int n)
{
	node* mst[n];
	int total = 0;
	node* stack[n];
	int top = -1;
	map <string,int> vis;
	for(int i = 0;i<n;i++)
	{
		mst[i] = new node;
		mst[i]->city = vertices[i]->city;
		mst[i]->weight = -1;
		mst[i]->nxt = NULL;
		vis.insert(pair<string,int>(vertices[i]->city,-1));
	}
	node* temp = new node;
	node* mini = new node;
	node* copy = new node;
	node* copy1 = new node;
	int min = 10000;
	top++;
	stack[top] = new node;
	stack[top] = vertices[top];
	vis[stack[top]->city] = 1;
	while(top != -1)
	{
		min = 10000;
		mini = NULL;
		for(int i = 0;i<n;i++)
		{
			if(stack[top]->city.compare(vertices[i]->city) == 0)
			{
				temp = vertices[i];
				break;
			}
		}
		while(temp != NULL)
		{
			if(temp->weight < min && vis[temp->city] != 1)
			{
				min = temp->weight;
				mini = temp;
			}
			temp = temp->nxt;
		}
		if(mini == NULL)
		{
			--top;
		}
		else
		{
			int c = 0;
			for(int i = 0;i<n;i++)
			{
				if(stack[top]->city.compare(mst[i]->city) == 0)
				{
					c = i;
					break;
				}
			}
			insert(&mst[c],mini->city,mini->weight);
			copy->city = mini->city;
			copy->weight = mini->weight;
			copy1->city = mst[c]->city;
			copy1->weight = mini->weight;
			for(int i = 0;i<n;i++)
			{
				if(copy->city.compare(mst[i]->city) == 0)
				{
					c = i;
					break;
				}
			}
			insert(&mst[c],copy1->city,copy1->weight);
			total = total + (mini->weight);
			top++;
			stack[top] = mini;
			vis[mini->city] = 1;
		}


	}
	cout<<"Contents are : "<<endl;
	node* temp1 = new node();
		for(int i = 0;i<n;i++)
		{
			cout<<mst[i]->city<<"->";
			temp1 = mst[i];
			temp1 = temp1->nxt;
			while(temp1 != NULL)
			{
				cout<<temp1->city<<" "<<temp1->weight<<"->";
				temp1 = temp1->nxt;
			}
			cout<<"NULL"<<endl;
		}

		cout<<"Total cost : "<<total<<endl;
}



int main()
{
	string name;
	int n;
	cout<<"Enter the number of cities in which the offices are located : ";
	cin >> n;
	node* vertices[n];
	for(int i = 0;i<n;i++)
	{
		cout<<"Enter the city "<<i+1<<" : ";
		cin >> name;
		vertices[i] = new node;
		vertices[i]->city = name;
		vertices[i]->weight = -1;
		vertices[i]->nxt = NULL;
	}
	int n1,wt;
	for(int i = 0;i<n;i++)
	{
		cout<<"Enter the number of cities connected with "<<vertices[i]->city<<" : ";
		cin >> n1;
		for(int j = 0;j<n1;j++)
		{
			cout<<"Enter the connecting city "<<j+1<<" with "<<vertices[i]->city<<" : ";
			cin >> name;
			cout<<"Enter the weight of "<<name<<" & "<<vertices[i]->city<<" : ";
			cin >> wt;
			insert(&vertices[i],name,wt);
		}
	}
	/*node* temp = new node();
	for(int i = 0;i<n;i++)
	{
		cout<<vertices[i]->city<<"->";
		temp = vertices[i];
		temp = temp->nxt;
		while(temp != NULL)
		{
			cout<<temp->city<<" "<<temp->weight<<"->";
			temp = temp->nxt;
		}
		cout<<"NULL"<<endl;
	}*//*
	prims(vertices,n);
	return 0;
}
*/
