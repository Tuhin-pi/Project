#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student
{
	private:
		string mobile,roll_no,email_id,name,address,course;
	public:
		void menu();
		void insert();
		void display();
		void exit();
		void fordelay(int);
		void reverse();
		void search();
		void modify();
		void Delete();
		void invalid();
		
};
void student::invalid()
{
	cout<<"\n\n\t\t\tinvalid input...Please Try Again...."<<endl;
			cout<<"\a";
			fordelay(10000000);
			cout<<"\a";
			fordelay(10000000);
			cout<<"\a";
			reverse();
}
void student::reverse()
{
	string x;
	cout<<"\n\t\t\tPress 0 for menu/ 1 for exit :";
			cin>>x;
			if(x=="0")
			{
			menu();
			}
			else if(x=="1")
			{
				exit();
			}	
			else
			{
				invalid();
			}	   
}
void student:: fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void student::exit()
{
	system("cls");
	cout<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t|  THANKS FOR USING OUR SYSTEM |"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
}
void student::menu()
{
	system("cls");
	int choise;
	system("cls");
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t|  STUDENT MANNAGEMENT SYSTEM  |"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t1.Enter New Record"<<endl;
	cout<<"\t\t\t2.Display Record"<<endl;
	cout<<"\t\t\t3.Modify Record"<<endl;
	cout<<"\t\t\t4.Search Record"<<endl;
	cout<<"\t\t\t5.Delete Record"<<endl;
	cout<<"\t\t\t6.Exit"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t  Choose Option :[1/2/3/4/5/6]  "<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\tEnter Your Choise : ";
	cin>>choise;
	switch(choise)
	{
		case 1:
			insert();
			break;
		case 2:
			display();
			break;
		case 3:
			modify();
			break;
		case 4:
			search();
			break;
		case 5:
			Delete();
			break;		
		case 6:
			exit();
			break;	
		default:
			invalid();
			break;
			
	}
}
void student::insert()
{
	ofstream file;
	system("cls");
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t|      ADD STUDENT DTAILS      |"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\tEnter Name of the Student : ";
	getline(cin,name);
	cout<<"\t\t\tEnter Roll No of the Student : ";
	cin>>roll_no;
	cout<<"\t\t\tEnter course of the Student : ";
	cin>>course;
	cout<<"\t\t\tEnter Email Id of the Student : ";
	cin>>email_id;
	cout<<"\t\t\tEnter Mobile No of the student : ";
	cin>>mobile;
	cout<<"\t\t\tEnter Address of the Student : ";
	cin>>address;
	fordelay(1000000000);
	cout<<"\t\t\tStudent's Dtails Added Sucessfily....."<<endl;
	fordelay(100000000);
	file.open("studentrecord.txt",ios::app);
	file<<"   "<<name<<"   "<<roll_no<<"  "<<course<<"  "<<email_id<<"  "<<mobile<<"  "<<address<<"\n";
	file.close();
	reverse();
}
void student::display()
{
	int count=0;
	system("cls");
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t|     STUDENT RECORD TABLE     |"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	ifstream file;
	file.open("studentrecord.txt");
	if(!file)
	{
		cout<<"\n\n\n\n\t\t\tNO RECORD FOUND"<<endl;
	}
	else
	{
		file>>name>>roll_no>>course>>email_id>>mobile>>address;
		while(!file.eof())
		{
			cout<<"\n\n\n\t\t\tSerial No."<<count+1<<endl;
			cout<<"\t\t\tName: "<<name<<endl;
			cout<<"\t\t\tRoll No: "<<roll_no<<endl;
			cout<<"\t\t\tCourse: "<<course<<endl;
			cout<<"\t\t\tEmail Id: "<<email_id<<endl;
			cout<<"\t\t\tMobile No: "<<mobile<<endl;
			cout<<"\t\t\tAddress: "<<address<<endl;
			file>>name>>roll_no>>course>>email_id>>mobile>>address;
			count++;
		}
		if(count==0)
		{
			cout<<"\n\n\n\n\t\t\tNO RECORD FOUND"<<endl;
		}
		cout<<"\n\n\n\t\t\tTotal No of Student: "<<count<<endl;
	}
	file.close();
	reverse();
	
}
void student::modify()
{
	system("cls");
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t|    MODIFY STUDENT RECORD     |"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	string y;
	int status=0;
	cout<<"\n\n\n\t\t\tEnter Roll No of the Student : ";
	cin>>y;
	ofstream file;
	ifstream file1;
	file.open("record.txt",ios::app);
	file1.open("studentrecord.txt");
	if(!file1)
	{
		cout<<"\n\n\n\n\t\t\tNO RECORD FOUND"<<endl;
	}
	else
	{
	file1>>name>>roll_no>>course>>email_id>>mobile>>address;
	while(!file1.eof())
	{
		
		if(roll_no!=y)
		{
			file<<"   "<<name<<"   "<<roll_no<<"  "<<course<<"  "<<email_id<<"  "<<mobile<<"  "<<address<<"\n";
		}
		else if(roll_no==y)
		{
			cout<<"\n\t\t\t:: Your Present Data ::";
			cout<<"\n\n\t\t\tName: "<<name<<endl;
			cout<<"\t\t\tRoll No: "<<roll_no<<endl;
			cout<<"\t\t\tCourse: "<<course<<endl;
			cout<<"\t\t\tEmail Id: "<<email_id<<endl;
			cout<<"\t\t\tMobile No: "<<mobile<<endl;
			cout<<"\t\t\tAddress: "<<address<<endl;
			status=1;
			cout<<"\n\t\t\tEnter New Record:\n";
			cout<<"\n\t\t\tEnter Name of the Student : ";
			cin>>name;
			cout<<"\t\t\tEnter Roll No of the Student : ";
			cin>>roll_no;
			cout<<"\t\t\tEnter course of the Student : ";
			cin>>course;
			cout<<"\t\t\tEnter Email Id of the Student : ";
			cin>>email_id;
			cout<<"\t\t\tEnter Mobile No of the student : ";
			cin>>mobile;
			cout<<"\t\t\tEnter Address of the Student : ";
			cin>>address;
			file<<"   "<<name<<"   "<<roll_no<<"  "<<course<<"  "<<email_id<<"  "<<mobile<<"  "<<address<<"\n";	
			fordelay(1000000000);
	cout<<"\t\t\tStudent's Dtails Modified Sucessfily.....\n"<<endl;	
		}
		file1>>name>>roll_no>>course>>email_id>>mobile>>address;
	}
	if(status==0)
	{
		cout<<"\n\n\n\n\t\t\tNO RECORD FOUND"<<endl;	
	}
	
	file.close();
	file1.close();
	remove("studentrecord.txt");
	rename("record.txt","studentrecord.txt");
	}
	fordelay(100000000);
	reverse();
}
void student::search()
{
	system("cls");
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t|    SEARCH STUDENT RECORD     |"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	string y;
	cout<<"\n\n\n\t\t\tEnter Roll No of the Student : ";
	cin>>y;
	ifstream file;
	file.open("studentrecord.txt");
	if(!file)
	{
		cout<<"\n\n\n\n\t\t\tNO RECORD FOUND..."<<endl;
	}
	else
	{
	int status=0;
	file>>name>>roll_no>>course>>email_id>>mobile>>address;
	while(!file.eof())
	{
		int z=y.compare(roll_no);
		if(z==0)
		{
			cout<<"\n\n\t\t\tName: "<<name<<endl;
			cout<<"\t\t\tRoll No: "<<roll_no<<endl;
			cout<<"\t\t\tCourse: "<<course<<endl;
			cout<<"\t\t\tEmail Id: "<<email_id<<endl;
			cout<<"\t\t\tMobile No: "<<mobile<<endl;
			cout<<"\t\t\tAddress: "<<address<<endl;
			status=1;
		}	
	file>>name>>roll_no>>course>>email_id>>mobile>>address;
	}
	if(status==0)
	{
		cout<<"\n\n\n\n\t\t\tNO RECORD FOUND...."<<endl;	
	}
	file.close();
	}
	reverse();
}
void student::Delete()
{
	int x;
	system("cls");
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t|   DO YOU WANT TO DELETE??    |"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\n\n\t\t\tPress 0 for delete all::\n\t\t\tPress 1 for delete individual :: ";
	cin>>x;
	if(x==0)
	{
		ifstream file;
		file.open("studentrecord.txt");
		file.close();
		remove("studentrecord.txt");
		fordelay(10000000);
		cout<<"\t\t\tAll Student's Dtails Deleted Sucessfily.....\n"<<endl;
	}
	else 
	{
			string y;
	int status=0;
	cout<<"\n\n\n\t\t\tEnter Roll No of the Student : ";
	cin>>y;
	ofstream file;
	ifstream file1;
	file.open("record.txt",ios::app);
	file1.open("studentrecord.txt");
	if(!file1)
	{
		cout<<"\n\n\n\n\t\t\tNO RECORD FOUND"<<endl;
	}
	else
	{
	file1>>name>>roll_no>>course>>email_id>>mobile>>address;
	while(!file1.eof())
	{
		
		if(roll_no!=y)
		{
			file<<"   "<<name<<"   "<<roll_no<<"  "<<course<<"  "<<email_id<<"  "<<mobile<<"  "<<address<<"\n";
		}
		else if(roll_no==y)
		{
			file<<"\n";	
		}
		file1>>name>>roll_no>>course>>email_id>>mobile>>address;
	}
	if(status==0)
	{
		cout<<"\n\n\n\n\t\t\tNO RECORD FOUND"<<endl;	
	}
	
	file.close();
	file1.close();
	remove("studentrecord.txt");
	rename("record.txt","studentrecord.txt");
	}
	fordelay(10000000);
	cout<<"\t\t\tStudent's Dtails Deleted Sucessfily.....\n"<<endl;
	}
	reverse();
}
main()
{
	student project;
	project.menu();
}

