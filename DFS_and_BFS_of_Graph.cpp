/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency list to perform BFS. Use the map of the area around the college as the graph. Identify the prominent land marks as nodes and perform DFS and BFS on that.*/
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

struct node
{
	string data;
	struct node* nxt;
};

void insert(struct node **q,string data)
{
	node* temp = new node();
	temp = *q;
	while(temp->nxt != NULL)
	{
		temp = temp->nxt;
	}
	node* newnode = new node();
	newnode->data = data;
	newnode->nxt = NULL;
	temp->nxt = newnode;
}


void DFS(node* vertices[],int n)
{
	map <string,int> vis;
	node* temp = new node();
	for(int i = 0;i<n;i++)
	{
		vis.insert(pair<string,int>(vertices[i]->data,-1));
	}
	node* stack[n];
	int top = -1;
	bool flag = false;

	top++;
	stack[top] = new node();
	stack[top] = vertices[top];
	while(top != -1)
	{
	    if(vis[stack[top]->data] != 1)
	    {
		    cout<<stack[top]->data<<" ";
		    vis[stack[top]->data] = 1;
	    }
		for(int i = 0;i<n;i++)
		{
			if(stack[top]->data.compare(vertices[i]->data) == 0)
			{
				temp = vertices[i];
				break;
			}
		}
		flag = false;
		while(vis[temp->data] != -1)
		{
			temp = temp->nxt;

			if(temp == NULL)
			{
				flag = true;
				break;
			}
		}
		if(flag)
		{
			top--;
		}
		else
		{
			top++;
			stack[top] = new node();
			stack[top] = temp;
		}
	}
	delete(temp);

}


void BFS(node* vertices[],int n)
{
	map <string,int> vis;
	for(int i = 0;i<n;i++)
		vis.insert(pair<string,int>(vertices[i]->data,-1));
	node* temp = new node;
	node* queue[n];
	int front = -1;
	int rear = -1;

	rear++;
	front++;

	queue[rear] = new node;
	queue[rear] = vertices[0];

	while(rear != -1)
	{
		cout<<queue[front]->data<<" ";
		vis[queue[front]->data] = 1;
		for(int i = 0;i<n;i++)
		{
			if(queue[front]->data.compare(vertices[i]->data) == 0)
			{
				temp = vertices[i];
				break;
			}
		}
		while(temp != NULL)
		{
			if(vis[temp->data] == -1)
			{
				rear++;
				queue[rear] = new node();
				queue[rear] = temp;
				vis[queue[rear]->data] = 1;
			}
			temp = temp->nxt;
		}
		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front++;
		}
	}


}

int main()
{
	string name;
	int n,n1;
	cout<<"Enter the number of vertices : ";
	cin >> n;
	node* vertices[n];
	for(int i = 0;i<n;i++)
	{
		cout<<"Enter the vertex "<<i+1<<" : ";
		cin >> name;
		vertices[i] = new node();
		vertices[i]->data = name;
		vertices[i]->nxt = NULL;
	}
	for(int i = 0;i<n;i++)
	{
		cout<<"Enter the number of vertices which have an edge with "<<vertices[i]->data<<" : ";
		cin >> n1;
		for(int j = 0;j<n1;j++)
		{
			cout<<"Enter the connecting vertex "<<j+1<<" with vertex "<<vertices[i]->data<<" : ";
			cin >> name;
			insert(&vertices[i],name);
		}
	}
	/*node* temp = new node;
	for(int i = 0;i<n;i++)
	{
		cout<<vertices[i]->data<<"->";
		temp  = vertices[i]->nxt;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->nxt;
		}
		cout<<endl;
	}*/
	cout<<"DFS of the graph is : "<<endl;
	DFS(vertices,n);
	cout<<"\nBFS of the graph is : "<<endl;
	BFS(vertices,n);
}

