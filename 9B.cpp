#include<iostream>
#include<fstream>

using namespace std;

class student
{

		int rollno;
		char name[10];
    public:
		int read();
		int write();
};


int student::write()
{
	//string nam;
	//int roll;
	ofstream file;
	student obj;
	file.open("Text.txt", ios::in|ios::trunc);
	cout<<"\nEnter Name\t";
	cin>>obj.name;
	//obj.name = nam;
	cout<<"\nEnter Roll NO\t";
	cin>>obj.rollno;
	// = roll;
	file.write((char*)&obj,sizeof(obj));
	file.close();
	return 0;
}
int student::read()
{
	ifstream fil;
	student obj;
	fil.open("Text.txt",ios::out); 
	fil.read((char*)&obj,sizeof(obj));
	//string nam =obj.name;
	//int roll = obj.rollno;
	
	cout<<"\nRoll No = "<<obj.rollno; 
	cout<<"\nName = "<<obj.name;
	fil.close();
	return 0;
}

int main()
{
	student s;
	s.write();
	s.read();
	return 0;
}
