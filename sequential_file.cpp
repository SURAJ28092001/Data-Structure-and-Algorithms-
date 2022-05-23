/*Company maintains employee information as employee ID, name, designation and salary. Allow user to add, delete information of employee. Display information of particular employee. If employee does not exist an appropriate message is displayed. If it is, then the system displays the employee details. Use index sequential file to maintain the data.*/
#include<iostream>
#include<fstream>
using namespace std;

class Employee
{
	int salary;
	char name[100],desig[100],empid[100];
public:
	void accept()
	{
		cout<<"Enter Employee ID : ";
		cin >> empid;
		cout<<"Enter name : ";
		cin.ignore();
		cin.getline(name,100);
		cout<<"Enter Designation : ";
		cin.getline(desig,100);
		cout<<"Enter salary : ";
		cin >> salary;
	}
	void output()
	{
		cout<<"---------------------------------------"<<endl;
		cout<<"Employee ID : "<<empid<<endl;
		cout<<"Name : "<<name<<endl;
		cout<<"Designation : "<<desig<<endl;
		cout<<"Salary : "<<salary<<endl;
		cout<<"---------------------------------------"<<endl;
	}
	char* get_id()
	{
		return empid;
	}
};

int main()
{
	int ch;
	char id[100];
	int c = 0;
	Employee s;
	do
	{
		cout<<"================================================================="<<endl;
		cout<<"Press 1 to insert a new record : "<<endl;
		cout<<"Press 2 to display a particular record : "<<endl;
		cout<<"Press 3 to delete a record : "<<endl;
		cout<<"Press 0 to Exit : "<<endl;
		cout<<"================================================================="<<endl;
		cin >> ch;
		switch(ch)
		{
		case 1:
		{
			ofstream f;
			f.open("Employee.dat",ios::app);
			s.accept();
			f.write((char*)&s,sizeof(s));
			c++;
			f.close();
		}
			break;
		case 2:
		{
			cout<<"Enter the Employee ID : ";
			cin >> id;
			bool flag = 0;
			ifstream f;
			f.open("Employee.dat");
			for(int i = 0;i<c;i++)
			{
			f.read((char*)&s,sizeof(s));
			if(strcmp(s.get_id(),id) == 0)
			{
				cout<<"Record found with following details : "<<endl;
				s.output();
				flag = 1;
				break;
			}
			cout<<endl;
			}
			if(flag == 0)
				cout<<"No such record found."<<endl;
			f.close();
			break;
		}
		case 3:
		{
			cout<<"Enter the Employee ID to be deleted : ";
			cin >> id;
			ofstream fout;
			ifstream fin;
			bool flag = false;
			fout.open("temp.dat",ios::app);
			fin.open("Employee.dat");
			for(int i = 0;i<c;i++)
			{
				fin.read((char*)&s,sizeof(s));

				if(strcmp(s.get_id(),id) == 0)
				{
					flag = true;
					continue;
				}
				fout.write((char*)&s,sizeof(s));
			}
			if(!flag)
			{
				cout<<"No such record found."<<endl;
				break;
			}
			else
				cout<<"Record is deleted successfully."<<endl;
			fin.close();
			fout.close();
			remove("Employee.dat");
			rename("temp.dat","Employee.dat");
			break;
		}
		case 0:
			cout<<"Exited"<<endl;
			break;
		default:
			cout<<"Invalid Choice !!! Please try again."<<endl;

		}
	}while(ch != 0);
	return 0;
}
