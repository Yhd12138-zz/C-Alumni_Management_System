#include<iostream>
#include"Student_yhd.cpp"
using namespace std;

void menu()
{
	cout<<"+--------------------------+\n";
	cout<<"|   学生学籍信息管理系统   |\n";
	cout<<"+--------------------------+\n";
	cout<<"|    1、添加学生信息       |\n";
	cout<<"|    2、修改学生信息       |\n";
	cout<<"|    3、删除学生信息       |\n";
	cout<<"|    4、查询学生信息       |\n";
	cout<<"|    5、保存学生信息       |\n";
	cout<<"|    6、读取学生信息       |\n";
	cout<<"|    7、显示学生信息       |\n";
	cout<<"|    8、排序学生信息       |\n";
	cout<<"+--------------------------+\n";
	cout<<"|    0、退出               |\n";
	cout<<"+--------------------------+\n";
}

int main() 
{
	Student m_stu;
	int choice;
	menu();
	do
	{
		cout<<"请输入选项1-8（输入9显示菜单）:";
		cin>>choice;
		while (cin==0)
		{
			cin.clear();
			cin.sync();
			cout<<"请输入正确的选项："<<endl;
			cin>>choice;
		}
		switch (choice)
		{
			case 6:
				m_stu.readFile();
				break;
			case 5:
				m_stu.saveToFile();
				break;
			case 1:
				m_stu.input();
				break;
			case 2:
				m_stu.Modify();
				break;
			case 7:
				m_stu.Show();
				break;
			case 4:
				m_stu.Query();
				break;
			case 3:
				m_stu.Delete();
				break;
			case 8:
				m_stu.Sort();
				break;
			case 9:
				menu();
				break;
			case 0:
				break;
			default:
				cout<<"请输入正确的选项："<<endl;
				break;
		}
	}
	while (choice);
	return 0;
}
