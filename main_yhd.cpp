#include<iostream>
#include"Student_yhd.cpp"
using namespace std;

void menu()
{
	cout<<"+--------------------------+\n";
	cout<<"|   ѧ��ѧ����Ϣ����ϵͳ   |\n";
	cout<<"+--------------------------+\n";
	cout<<"|    1�����ѧ����Ϣ       |\n";
	cout<<"|    2���޸�ѧ����Ϣ       |\n";
	cout<<"|    3��ɾ��ѧ����Ϣ       |\n";
	cout<<"|    4����ѯѧ����Ϣ       |\n";
	cout<<"|    5������ѧ����Ϣ       |\n";
	cout<<"|    6����ȡѧ����Ϣ       |\n";
	cout<<"|    7����ʾѧ����Ϣ       |\n";
	cout<<"|    8������ѧ����Ϣ       |\n";
	cout<<"+--------------------------+\n";
	cout<<"|    0���˳�               |\n";
	cout<<"+--------------------------+\n";
}

int main() 
{
	Student m_stu;
	int choice;
	menu();
	do
	{
		cout<<"������ѡ��1-8������9��ʾ�˵���:";
		cin>>choice;
		while (cin==0)
		{
			cin.clear();
			cin.sync();
			cout<<"��������ȷ��ѡ�"<<endl;
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
				cout<<"��������ȷ��ѡ�"<<endl;
				break;
		}
	}
	while (choice);
	return 0;
}
