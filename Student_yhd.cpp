#include"Student_yhd.h"
#include<iostream>
using namespace std;

string filename="Empty";
void show(Stu *p);

Student::Student()
{
	head=new Stu;
	head->stu_name="No Name";
	head->stu_next=NULL;
}
Student::~Student()
{
	Stu *p=head, *q;
	while (p) 
	{
		q=p;
		p=q->stu_next;
		delete q;
	}
}


void Student::input()
{
	Stu temp;
	string confirm;
	
		cout<<"������";
		cin>>temp.stu_name;
		cout<<"�Ա�";
		cin>>temp.stu_sex;
		cout<<"���䣺";
		cin>>temp.stu_age;
		cout<<"�죺";
		cin>>temp.stu_grad;
		cout<<"ϵ��";
		cin>>temp.stu_dept;
		cout<<"�༶��";
		cin>>temp.stu_class;
		cout<<"ͨѶ��ַ��";
		cin>>temp.stu_addr;
		cout<<"�绰��";
		cin>>temp.stu_tel;
		cout<<"QQ��";
		cin>>temp.stu_qq;
		cout<<"E-mail��";
		cin>>temp.stu_email;
		cout<<"��ȷ������������������"<<endl;
		show(&temp);
		cout<<endl<<"����yȷ��¼�룬����exit������"<<endl;
		cin>>confirm;
		while (confirm!="y"&&confirm!="exit")
		{
			cout<<"����yȷ��¼�룬����exit������"<<endl;
			cin>>confirm;
		}
		if (confirm=="y")
			insert(temp);
		else if (confirm=="exit")
			cout<<"�ѻص��˵�"<<endl;
}


void Student::Query() const
{
	int select;
	string name0;
	int grad0;
	string dept0;
	string class0;
	Stu *p;
	cout<<"1.��������ѯ\n2.�����ѯ\n3.��ϵ��ѯ\n4.���༶��ѯ\n0.���ص��˵�\n������1-4��";
	cin>>select;
	switch (select)
	{
	case 1:
		cout<<"����������: ";
		cin>>name0;
		if ((p=findByName(name0)))
			while (p->stu_next!=NULL)
			{
				show(p->stu_next);
				p=p->stu_next;
			}
		break;
	case 2:
		cout<<"�������: ";
		cin>>grad0;
		if ((p=findByGrad(grad0)))
			while (p->stu_next!=NULL)
			{
				show(p->stu_next);
				p=p->stu_next;
			}
		break;
	case 3:
		cout<<"������ϵ��";
		cin>>dept0;
		if ((p=findByDept(dept0)))
			while (p->stu_next!=NULL)
			{
				show(p->stu_next);
				p=p->stu_next;
			}
		break;
	case 4:
		cout<<"������༶��";
		cin>>class0;
		if ((p=findByClass(class0)))
			while (p->stu_next!=NULL)
			{
				show(p->stu_next);
				p=p->stu_next;
			}
		break;
	case 0:
		return;
	default:
		cout<<"�������"<<endl;
	}
	cout<<"�ѷ��ص��˵�"<<endl; 
}
Stu *Student::findByGrad(const int &Grad) const
{
	Stu *head_grad=new Stu;
	head_grad->stu_name="No Name";
	head_grad->stu_next=NULL;
	Stu *p;
	Stu *p_grad=head_grad;
	for (p=head;p->stu_next;p=p->stu_next)
		if (p->stu_next->stu_grad==Grad)
		{
			p_grad->stu_next=new Stu(*(p->stu_next));
			p_grad->stu_next->stu_next=NULL;
			p_grad=p_grad->stu_next;
		}
	if (head_grad->stu_next==NULL)
	{	
		cout<<"û���ҵ�����Ľ�"<<endl;
		return NULL;
	}
	else
		return head_grad;
}
Stu *Student::findByDept(const string &Dept) const
{
	Stu *head_dept=new Stu;
	Stu *p;
	Stu *p_dept=head_dept;
	for (p=head;p->stu_next;p=p->stu_next)
		if (p->stu_next->stu_dept==Dept)
		{
			p_dept->stu_next=new Stu(*(p->stu_next));
			p_dept->stu_next->stu_next=NULL;
			p_dept=p_dept->stu_next;
		}
	if (head_dept->stu_next==NULL)
	{	
		cout<<"û���ҵ������ϵ"<<endl;
		return NULL;
	}
	else
		return head_dept;
}
Stu *Student::findByName(const string &Name) const
{
	Stu *head_name=new Stu;
	Stu *p;
	Stu *p_name=head_name;
	for (p=head;p->stu_next;p=p->stu_next)
		if (p->stu_next->stu_name==Name)
		{
			p_name->stu_next=new Stu(*(p->stu_next));
			p_name->stu_next->stu_next=NULL;
			p_name=p_name->stu_next;
		}
	if (head_name->stu_next==NULL)
	{	
		cout<<"û���ҵ����������"<<endl;
		return NULL;
	}
	else
		return head_name;
}
Stu *Student::findByTel(const string &Tel) const
{
	Stu *p;
	for (p=head;p->stu_next;p=p->stu_next)
		if (p->stu_next->stu_tel==Tel) return p;
	cout<<"û���ҵ�����ĵ绰"<<endl;
	return NULL;
}
Stu *Student::findByClass(const string &Class) const
{
	Stu *head_class=new Stu;
	Stu *p;
	Stu *p_class=head_class;
	for (p=head;p->stu_next;p=p->stu_next)
		if (p->stu_next->stu_class==Class)
		{
			p_class->stu_next=new Stu(*(p->stu_next));
			p_class->stu_next->stu_next=NULL;
			p_class=p_class->stu_next;
		}
	if (head_class->stu_next==NULL)
	{	
		cout<<"û���ҵ�����İ༶"<<endl;
		return NULL;
	}
	else
		return head_class;
}


void Student::Delete()
{
	Show();
	string Tel;
	cout<<"������Ҫɾ���ĺ��룺"<<endl;
	cin>>Tel;
	DeleteByTel(Tel);
}

void Student::DeleteByTel(string &Tel)
{
	Stu *q, *p;
	p=findByTel(Tel);
	if (p==NULL)
	{
		cout<<"û���ҵ��绰�ǡ�"<<Tel<<"����ͬѧ, ɾ��ʧ��"<<endl;
		return;
	}
	q=p->stu_next;
	p->stu_next=q->stu_next;
	delete q;
	cout<<"��ɾ���绰Ϊ��"<<Tel<<"����ͬѧ��Ϣ"<<endl;;
}


void Student::Modify()
{
	Show();
	cout<<"������Ҫ�޸ĵ�ͬѧ��Ϣ�ĵ绰��"<<endl;
	int count0=Count(); 
	string Tel;
	Stu *p; 
	cin>>Tel;
	p=findByTel(Tel);
	if (p==NULL)
	{
		cout<<"û���ҵ��绰�ǡ�"<<Tel<<"����ͬѧ, �޸�ʧ��"<<endl;
		return;
	}
	else
	{
		cout<<"�������µ�ͬѧ��Ϣ��"<<endl;
		input();
		if (count0!=Count())
			DeleteByTel(Tel);
	}
}

void Student::saveToFile() 
{
	string new_file;
	cout << "������Ҫ������ļ���: "; 
	cin >> new_file;
	fstream file;
	file.open(new_file.c_str(), ios::out);
	if (file.bad()) 
	{
		cout<<"�ļ���ʧ�ܣ�"<<endl;
		return;
	}
	int len=Count();
	file<<len<<endl;
	Stu *pHead=head->stu_next;
	while (pHead!=NULL) 
	{
		file<<pHead->stu_name<<endl;
		file<<pHead->stu_sex<<endl;
		file<<pHead->stu_age<<endl;
		file<<pHead->stu_grad<<endl;
		file<<pHead->stu_dept<<endl;
		file<<pHead->stu_class<<endl;
		file<<pHead->stu_addr<<endl;
		file<<pHead->stu_tel<<endl;
		file<<pHead->stu_qq<<endl;
		file<<pHead->stu_email<<endl;
		pHead=pHead->stu_next;
	}
	file.close();
	cout<<"����ɹ���"<<endl;
	filename=new_file;
}
void Student::readFile() 
{
	string new_file;
	cout<<"������Ҫ��ȡ���ļ�����"; 
	cin>>new_file;
	fstream file;
	file.open(new_file.c_str(), ios::in);
	if (file.bad()) 
	{
		cout<<"�ļ���ʧ�ܣ�"<<endl;
		return;
	}
	int len=0;
	file>>len;
	if (!len) 
	{
		cout<< "�ļ����ݴ���"<<endl;
		return;
	}
	Stu pHead;
	file.get();
	while (len--)
	{
		file>>pHead.stu_name;
		file>>pHead.stu_sex;
		file>>pHead.stu_age;
		file>>pHead.stu_grad;
		file>>pHead.stu_dept;
		file>>pHead.stu_class;
		file>>pHead.stu_addr;
		file>>pHead.stu_tel;
		file>>pHead.stu_qq;
		file>>pHead.stu_email;
		insert(pHead);
	}
	file.close();
	cout<<"�ļ�����ɹ���"<<endl;
	filename=new_file;
}

void Student::insert(const Stu& temp)
{
	Stu *newnode, *p=head;
	while (p->stu_next)
	{
		p=p->stu_next;
	}
	p->stu_next=new Stu(temp);
	p->stu_next->stu_next=NULL;
}

void Student::Show() const
{
	Stu *p;
	cout<<"Ŀǰ����"<<Count()<<"λͬѧ����Ϣ"<<endl<<"-----------------------------------\n";
	for (p=head->stu_next;p;p=p->stu_next)
	{
		show(p);
	}
	cout<<"-----------------------------------\n";
}
void show(Stu *p)
{
	cout<<"������"<<p->stu_name<<"���Ա�"<<p->stu_sex<<"�����䣺"<<p->stu_age<<"���죺"<<p->stu_grad<<"��ϵ��"<<p->stu_dept<<"���༶��"<<p->stu_class<<"��ͨѶ��ַ��"<<p->stu_addr<<"���绰��"<<p->stu_tel<<"��QQ��"<<p->stu_qq<<"��E-mail��"<<p->stu_email<<endl;
}

void Student::Sort()
{
	int select;
	cout<<"1.����������\n2.��������\n������1-2������0���ز˵�����";
	cin>>select;
	switch (select)
	{
		case 1:
			SortByName();
			break;
		case 2:
			SortByGrad();
			break;
		case 0:
			return;
		default:
			cout<<"�������"<<endl;
	}
}

void Student::SortByGrad()
{
	Stu *head_sort=new Stu;
	Stu *p;
	Stu *p_sort=head_sort;
	int grad0[Count()];
	string tel0[Count()];
	int i=0;
	for (p=head->stu_next;p;p=p->stu_next, i++)
	{
		grad0[i]=p->stu_grad;
		tel0[i]=p->stu_tel;
	}
	for (int j=0;j<Count()-1;j++)
		for (int k=j+1;k<Count();k++)
			if (grad0[j]>grad0[k])
			{
				swap(tel0[j], tel0[k]);
				swap(grad0[j], grad0[k]);
			}
	for (int j=0;j<Count();j++)
		for (p=head->stu_next;p;p=p->stu_next)
			if (tel0[j]==p->stu_tel)
			{
				p_sort->stu_next=new Stu(*p);
				p_sort->stu_next->stu_next=NULL;
				p_sort=p_sort->stu_next;
				break;
			}
	head=head_sort;
	cout<<"������ɣ�"<<endl;
}

void Student::SortByName()
{
	Stu *head_sort=new Stu;
	Stu *p;
	Stu *p_sort=head_sort;
	string name0[Count()];
	string tel0[Count()];
	int i=0;
	for (p=head->stu_next;p;p=p->stu_next, i++)
	{
		name0[i]=p->stu_name;
		tel0[i]=p->stu_tel;
	}
	for (int j=0;j<Count()-1;j++)
		for (int k=j+1;k<Count();k++)
			if (name0[j]>name0[k])
			{
				swap(tel0[j], tel0[k]);
				swap(name0[j], name0[k]);
			}
	for (int j=0;j<Count();j++)
		for (p=head->stu_next;p;p=p->stu_next)
			if (tel0[j]==p->stu_tel)
			{
				p_sort->stu_next=new Stu(*p);
				p_sort->stu_next->stu_next=NULL;
				p_sort=p_sort->stu_next;
				break;
			}
	head=head_sort;
	cout<<"������ɣ�"<<endl;
}

int Student::Count() const
{
	int count=0;
	Stu *p;
	for (p=head->stu_next;p;p=p->stu_next)
		count+=1;
	return count;
}
