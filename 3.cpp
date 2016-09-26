#include <iostream>
#include <string>
using namespace std;
int S_Counter=0;
class Student
{
private:
	struct Student_Node
	{
		string Name,Course_Name;
		int ID;
		double Grade;
		Student_Node * Next_Student,*Next_Right,*Next_Left;
	};
	struct Course_Node
	{
		string C_Name;
		Student_Node  *Head,*Tail;
		Course_Node * Next_Course;
	};
	struct IDs_and_Courses
	{
		string cname;
		int ID;
	};
	Course_Node * Node,*C_Head,*C_Tail;
	IDs_and_Courses Courses[1000];
public:
	void Add_Course(string cName)
	{
	    Node = new Course_Node;
		Node->C_Name=cName;
		Node->Next_Course=NULL;
		if(C_Head==NULL)
		{C_Head=C_Tail=Node;}
		else
		{
			C_Tail->Next_Course=Node;
			C_Tail=Node;
			C_Tail->Next_Course=NULL;
		}
		Node->Tail=Node->Head=NULL;
	}
	string Search_Course(int id,string Cname)
	{
		string course="0";int index=-1;
		for(int i=0;i<S_Counter;i++)
		{
			if(Courses[i].ID==id)
			{course=Courses[i].cname;index=i;break;}
		}
		if(index==-1)
		{Courses[S_Counter].cname=Cname;Courses[S_Counter].ID=id;S_Counter++;return course;}

		else {Courses[index].cname=Cname;return course;}
	}
	void Add_Student(string sname,int sId,float sgrade,string C_Name)
	{
		Student_Node * mynode = new Student_Node;
		mynode->Name=sname;
		mynode->ID=sId;
		mynode->Grade=sgrade;
		mynode->Course_Name=C_Name;
		mynode->Next_Student=NULL;
		Node=C_Head;
		string check=Search_Course(sId,C_Name);
		cout<<check<<endl;
   while(Node!=NULL)
	 {
	   if((Node->C_Name)==C_Name)
		  {
			 if(Node->Head==NULL)
				 {Node->Head=Node->Tail=mynode;Node->Tail->Next_Student=NULL;}
			 else
			 {
				(Node->Tail)->Next_Student=mynode;
				Node->Tail=mynode;
			 }

		  }
	   Node=Node->Next_Course;
	  }
  if(check=="0")
	   mynode->Next_Right= mynode->Next_Left=NULL;
   else
   {
	   Node=C_Head;
   while(Node!=NULL)
	 {
	   if(Node->C_Name==check)
	   {
		   Student_Node * current = Node->Head;
	  while(current!=NULL)
	   {
	   if(current->ID==sId)
	   {current->Next_Right=mynode;mynode->Next_Left=current;mynode->Next_Right=NULL;break;}
	   current=current->Next_Student;
       }
      }
	    Node=Node->Next_Course;
   }
   }
	}
	void Print()
	{
		Node=C_Head;
		while(Node!=NULL)
		{
			Student_Node * New =Node->Head;
			cout<<"---------------------------------------------"<<endl;
			cout<<"        Course Name        " <<Node->C_Name<<endl;
			while(New!=NULL)
			{
				cout<<"-----------------------------"<<endl;
				cout<<" Student Name  : "<< New -> Name<<endl;
				cout<<" Student ID    : "<< New -> ID<<endl;
				cout<<" Student Grade : "<< New -> Grade<<endl;
				cout<<"-----------------------------"<<endl;
				New=New->Next_Student;
			}
			cout<<"---------------------------------------------"<<endl;
			Node=Node->Next_Course;

		}
	}
	void Display_Series(int id)
	{
		Node=C_Head;
			Student_Node * object ;
			cout<<"---------------------------------------------"<<endl;
			while(Node!=NULL)
			{
			Student_Node * New =Node->Head;
			while(New!=NULL)
		    {
			   if(New->ID==id)
			   {
				Student_Node * object =New;
               while(object!=NULL)
			{
				cout<<"        Course Name        " <<object->Course_Name<<endl;
				cout<<"-----------------------------"<<endl;
				cout<<" Student Grade : "<< object -> Grade<<endl;
				cout<<"-----------------------------"<<endl;
				object=object->Next_Right;
			}
			cout<<"---------------------------------------------"<<endl;
			return;
				}
			New=New->Next_Student;
			}
			Node=Node->Next_Course;
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
			Student_Node * New =Node->Head;
			cout<<"---------------------------------------------"<<endl;
			cout<<"        Course Name        " <<Node->C_Name<<endl;
			while(New!=NULL)
			{
				cout<<"-----------------------------"<<endl;
				cout<<" Student Name  : "<< New -> Name<<endl;
				cout<<" Student ID    : "<< New -> ID<<endl;
				cout<<" Student Grade : "<< New -> Grade<<endl;
				cout<<"-----------------------------"<<endl;
				New=New->Next_Student;
			}
			cout<<"---------------------------------------------"<<endl;
			}
			Node=Node->Next_Course;
	}
		if(x==0)
		cout<<" This Course Does Not Exist "<<endl;
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
		cout << "3)  |  Display Course Using Course Name              |\n";
		cout << "4)  |  Search Student Using ID                       |\n";
		cout << "5)  |  Print All Faculty Courses Withe Students      |\n";
        cout << "6)  |  Exit                                          |\n";
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
			string sname,cname;float sgrade;
			int sid;
			cin.ignore();
			cout <<" Enter Student Name          : ";
			getline(cin,sname);
			cout <<" Enter Student ID            : ";
			cin >> sid;
			cin.ignore();
			cout <<" Enter Student's Course Name : ";
			getline(cin,cname);
			cout <<" Enter Student Grade          : ";
			cin >> sgrade;
			student.Add_Student(sname,sid,sgrade,cname);
		}
		else if(choice==3)
		{
			string cname;
			cin.ignore();
			cout<<" Enter Course Name : ";
			getline(cin,cname);
			student.Display_Specific_Course(cname);
		}
		else if(choice==4)
		{
			int id;
			cout<<" Enter Student ID : ";
			cin >> id;
			student.Display_Series(id);
		}

		else if(choice==5)
			student.Print();
		else break;
	}

	return 0;
}
