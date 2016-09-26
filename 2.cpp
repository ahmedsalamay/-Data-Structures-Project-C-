#include <iostream>
#include <string>
using namespace std;
class Student
{
private:
	struct student_Node
	{
		string Name,ID;
		float Grade;
		student_Node * next;
	};
	struct Course_Node
	{
		string C_Name;
		student_Node *Head,*Tail;
		Course_Node * next;
	};
	Course_Node *C_Head,*C_Tail;
	Course_Node * Node;
public:
	Student()
	{
		C_Head=C_Tail=NULL;

	}
	void Add_Course(string cName)
	{
	 Node = new Course_Node;
		Node->C_Name=cName;
		Node->next=NULL;
		if(C_Head==NULL)
		{C_Head=C_Tail=Node;}
		else
		{
			C_Tail->next=Node;
			C_Tail=Node;
			C_Tail->next=NULL;
		}
		Node->Tail=Node->Head=NULL;
	}
	void Add_Student(string sname,string sId,float sgrade,string C_Name)
	{
		student_Node * mynode = new student_Node;
		mynode->Name=sname;
		mynode->ID=sId;
		mynode->Grade=sgrade;
		mynode->next=NULL;
		Node=C_Head;
   while(Node!=NULL)
	 {
	   if(Node->C_Name==C_Name)
		  {
			 if(Node->Head==NULL)
				 {Node->Head=Node->Tail=mynode;Node->Tail->next=NULL;}
			 else
			 {
				(Node->Tail)->next=mynode;
				Node->Tail=mynode;
			 }

		  }
	   Node=Node->next;
	  }

	}
	void Print()
	{
		Node=C_Head;
		while(Node!=NULL)
		{
			student_Node * New =Node->Head;
			cout<<"---------------------------------------------"<<endl;
			cout<<"        Course Name        " <<Node->C_Name<<endl;
			while(New!=NULL)
			{
				cout<<"-----------------------------"<<endl;
				cout<<" Student Name  : "<< New -> Name<<endl;
				cout<<" Student ID    : "<< New -> ID<<endl;
				cout<<" Student Grade : "<< New -> Grade<<endl;
				cout<<"-----------------------------"<<endl;
				New=New->next;
			}
			cout<<"---------------------------------------------"<<endl;
			Node=Node->next;

		}
	}
	void Remove_Course(string cname)
	{
		Course_Node * temp;
		Node=C_Head;int x=0,y=0;
   while(Node!=NULL)
	 {
	   if(Node->C_Name==cname)
	   {y++;break;}
	   Node=Node->next;
	   x++;
    }
   if(y==0){cout<<" This Course Does Not Exist "<<endl;return;}
   if(x==0)
   {
	   temp=C_Head;
	   C_Head=C_Head->next;
   }
   else
   {
   Node=C_Head;
   for(int i=0;i<x-1;i++)
      Node=Node->next;
    temp = Node->next;
    Node->next =temp->next;
   }
	delete temp;
	}
	void Remove_Student(string id,string cname)
	{
		int x=0,y=0;
		student_Node * temp;
		Node=C_Head;
   while(Node!=NULL)
	 {
	   if(Node->C_Name==cname)
	   {
		   student_Node * current = Node->Head;
	while(current!=NULL)
	   {
	   if(current->ID==id)
	   {y++; break;}
	   current=current->next;
	   x++;
       }
	if(y==0){cout<<" This Student Does Not Exist "<<endl;return;}
   if(x==0)
   {
	   temp=Node->Head;
	   Node->Head=Node->Head->next;
   }
   else
   {
   current=Node->Head;
   for(int i=0;i<x-1;i++)
      current=current->next;
    temp = current->next;
    current->next =temp->next;
   }
	delete temp;
	}
	   Node=Node->next;
	}
	}
	void Display_Specific_Course(string C_Name)
	{
		Node=C_Head;int x=0;
		while(Node!=NULL)
		{
			if(Node->C_Name==C_Name)
			{
				x++;
			student_Node * New =Node->Head;
			cout<<"---------------------------------------------"<<endl;
			cout<<"        Course Name        " <<Node->C_Name<<endl;
			while(New!=NULL)
			{
				cout<<"-----------------------------"<<endl;
				cout<<" Student Name  : "<< New -> Name<<endl;
				cout<<" Student ID    : "<< New -> ID<<endl;
				cout<<" Student Grade : "<< New -> Grade<<endl;
				cout<<"-----------------------------"<<endl;
				New=New->next;
			}
			cout<<"---------------------------------------------"<<endl;
			}
			Node=Node->next;
	}
		if(x==0)
		cout<<" This Course Does Not Exist "<<endl;
	}
	void Student_Search(string id)
	{
		Node=C_Head;int x=0;
		while(Node!=NULL)
		{
			student_Node * New =Node->Head;
			while(New!=NULL)
			{
				if(New -> ID==id)
				{
				if(x==0)
				{
				cout<<"-----------------------------"<<endl;
				cout<<" Student Name  : "<< New -> Name<<endl;
				cout<<" Student ID    : "<< New -> ID<<endl;
				cout<<" Student Grade : "<< New -> Grade<<endl;
				cout<<"-----------------------------"<<endl;
				x++;
				}
				cout<<"---------------------------------------------"<<endl;
				cout<<"        Course Name        " <<Node->C_Name<<endl;
				break;
				}
				New=New->next;
		}
			Node=Node->next;
		}
	}

};
int main()
{
	Student student;int choice;
	while(1)
	    {
		cout<<endl;
		cout<<"-------------------------------------------------------------"<<endl;
        cout << "1)  |  Add New Course                                |\n";
        cout << "2)  |  Add New Student                               |\n";
        cout << "3)  |  Remove Course                                 |\n";
        cout << "4)  |  Remove Student Using ID From Specific Course  |\n";
		cout << "5)  |  Display Course Using Course Name              |\n";
		cout << "6)  |  Search Student Using ID                       |\n";
		cout << "7)  |  Print All Faculty Courses Withe Students      |\n";
        cout << "8)  |  Exit                                          |\n";
	    cout<<"-------------------------------------------------------------"<<endl;
		cout<<endl;
		cout<<" Please Enter Your Choice"<<endl;
		cin >> choice;
		if(choice==1)
		{
			string cname;
			cin.ignore();
			cout<<" Enter Course Name :";
			getline(cin,cname);
			student.Add_Course(cname);
		}
		else if(choice==2)
		{
			string sname,sid,cname;float sgrade;
			cin.ignore();
			cout <<" Enter Student Name          : ";
			getline(cin,sname);
			cout <<" Enter Student ID            : ";
			getline(cin,sid);
			cout <<" Enter Student's Course Name : ";
			getline(cin,cname);
			cout <<" Enter Student Gead          : ";
			cin >> sgrade;
			student.Add_Student(sname,sid,sgrade,cname);
		}
		else if(choice==3)
		{
			string cname;
			cin.ignore();
			cout<<" Enter Course Name : ";
			getline(cin,cname);
			student.Remove_Course(cname);
		}
		else if(choice==4)
		{
			string cname,id;
			cin.ignore();
			cout<<" Enter Student ID : ";
			getline(cin,id);
			cout<<" Enter Course Name : ";
			getline(cin,cname);
			student.Remove_Student(id,cname);
		}
		else if(choice==5)
		{
			string cname;
			cin.ignore();
			cout<<" Enter Course Name : ";
			getline(cin,cname);
			student.Display_Specific_Course(cname);
		}
		else if(choice==6)
		{
			string cname,id;
			cin.ignore();
			cout<<" Enter Student ID : ";
			getline(cin,id);
			student.Student_Search(id);
		}
		else if(choice==7)
			student.Print();
		else break;

	}


	return 0;}
