/*#include <iostream>
using namespace std;

struct node
{
	string name;
	string problem;
	int priority;
	struct node *nxt;
};

class Priority_Queue
{
	node* root;
public:
	Priority_Queue()
	{
		root = new node;
		root = NULL;
	}

	void insert(string name,string problem,int priority)
	{
		if(root == NULL)
		{
			root = new node;
			root->name = name;
			root->problem = problem;
			root->priority = priority;
			root->nxt = NULL;
			return;
		}
		node* temp = new node;
		temp = root;
		node* newnode = new node;
		newnode->name = name;
		newnode->problem = problem;
		newnode->priority = priority;
		newnode->nxt = NULL;
		node* old = new node;
		if(temp->priority > priority)
		{
			newnode->nxt = temp;
			root = newnode;
			return;
		}
		else
		{
			while(temp->priority <= priority && temp->nxt != NULL)
			{
				old = temp;
				temp = temp->nxt;
			}
			if(temp->nxt == NULL)
			{
				if(temp->priority <= priority)
				{
					temp->nxt = newnode;
					return;
				}
			}
				old->nxt = newnode;
				newnode->nxt = temp;

		}
	}

	void display()
	{
		node* temp = new node;
		temp = root;
		if(root == NULL)
		{
			cout<<"There are no patients in the waiting list."<<endl;
			return;
		}
		cout<<"The Patients in the waiting list are as follows : "<<endl;
		while(temp != NULL)
		{
			cout<<"----------------------------------------"<<endl;
			cout<<"Name of the Patient is : "<<temp->name<<endl;
			cout<<"Problem of the patient is : "<<temp->problem<<endl;
			if(temp->priority == 1)
				cout<<"The category of the patient's problem is : Serious"<<endl;
			else if(temp->priority == 2)
				cout<<"The category of the patient's problem is : Non-serious"<<endl;
			else
				cout<<"The category of the patient's problem is : General Checkup"<<endl;
			cout<<"----------------------------------------"<<endl;
			temp = temp->nxt;
		}
	}

	void cater()
	{
		node* temp = new node;
		temp = root;
		if(root == NULL)
		{
			cout<<"There are no patients in the waiting list."<<endl;
			return;
		}

		if(temp->nxt == NULL)
		{
			cout<<"The patient being catered is with the following details : "<<endl;
			cout<<"Name of the Patient is : "<<temp->name<<endl;
			cout<<"Problem of the patient is : "<<temp->problem<<endl;
			if(temp->priority == 1)
				cout<<"The category of the patient's problem is : Serious"<<endl;
			else if(temp->priority == 2)
				cout<<"The category of the patient's problem is : Non-serious"<<endl;
			else
				cout<<"The category of the patient's problem is : General Checkup"<<endl;
			root = NULL;
			delete(temp);

		}
		else
		{
			cout<<"The patient being catered is with the following details : "<<endl;
			cout<<"Name of the Patient is : "<<temp->name<<endl;
			cout<<"Problem of the patient is : "<<temp->problem<<endl;
			if(temp->priority == 1)
				cout<<"The category of the patient's problem is : Serious"<<endl;
			else if(temp->priority == 2)
				cout<<"The category of the patient's problem is : Non-serious"<<endl;
			else
				cout<<"The category of the patient's problem is : General Checkup"<<endl;
			root = temp->nxt;
			delete(temp);
		}
	}
};

int main()
{
	Priority_Queue p;
	char name[200];
	char prob[1000];
	int ch,priority;
	do
	{
		cout<<"-------------------------------------------------"<<endl;
		cout<<"Press 1 to enter a new patient"<<endl;
		cout<<"Press 2 to cater a patient"<<endl;
		cout<<"Press 3 to check all the patients in waiting list"<<endl;
		cout<<"Press 0 to exit"<<endl;
		cout<<"-------------------------------------------------"<<endl;
		cin >> ch;
		switch(ch)
		{
		case 1:
			cout<<"Enter the patient Name : ";
			cin.ignore();
			cin.getline(name,200);
			cout<<"Enter the problem of the patient : ";
			cin.getline(prob,1000);
			while(true)
			{
			cout<<"============================================================"<<endl;
			cout<<"Press 1 if the category of the patient's problem is 'SERIOUS' "<<endl;
			cout<<"Press 2 if the category of the patient's problem is 'NON-SERIOUS' "<<endl;
			cout<<"Press 3 if the category of the patient's problem is 'GENERAL CHECKUP' "<<endl;
			cout<<"============================================================"<<endl;
			cin >> priority;
			if(priority == 3 || priority == 1 || priority == 2)
				break;
			else
				cout<<"Wrong choice Please select again."<<endl;
			}
			p.insert(name, prob, priority);
			cout<<"Patient Added Successfully !!!"<<endl;
			break;
		case 2:
			p.cater();
			break;
		case 3:
			p.display();
			break;
		case 0:
			cout<<"Exited"<<endl;
			break;
		default:
			cout<<"Wrong choice Please Try again."<<endl;
			break;
		}
	}while(ch != 0);

	return 0;
}
*/
