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
	
		cout<<"姓名：";
		cin>>temp.stu_name;
		cout<<"性别：";
		cin>>temp.stu_sex;
		cout<<"年龄：";
		cin>>temp.stu_age;
		cout<<"届：";
		cin>>temp.stu_grad;
		cout<<"系：";
		cin>>temp.stu_dept;
		cout<<"班级：";
		cin>>temp.stu_class;
		cout<<"通讯地址：";
		cin>>temp.stu_addr;
		cout<<"电话：";
		cin>>temp.stu_tel;
		cout<<"QQ：";
		cin>>temp.stu_qq;
		cout<<"E-mail：";
		cin>>temp.stu_email;
		cout<<"请确认以下内容输入无误："<<endl;
		show(&temp);
		cout<<endl<<"输入y确认录入，输入exit放弃："<<endl;
		cin>>confirm;
		while (confirm!="y"&&confirm!="exit")
		{
			cout<<"输入y确认录入，输入exit放弃："<<endl;
			cin>>confirm;
		}
		if (confirm=="y")
			insert(temp);
		else if (confirm=="exit")
			cout<<"已回到菜单"<<endl;
}


void Student::Query() const
{
	int select;
	string name0;
	int grad0;
	string dept0;
	string class0;
	Stu *p;
	cout<<"1.按姓名查询\n2.按届查询\n3.按系查询\n4.按班级查询\n0.返回到菜单\n请输入1-4：";
	cin>>select;
	switch (select)
	{
	case 1:
		cout<<"请输入姓名: ";
		cin>>name0;
		if ((p=findByName(name0)))
			while (p->stu_next!=NULL)
			{
				show(p->stu_next);
				p=p->stu_next;
			}
		break;
	case 2:
		cout<<"请输入届: ";
		cin>>grad0;
		if ((p=findByGrad(grad0)))
			while (p->stu_next!=NULL)
			{
				show(p->stu_next);
				p=p->stu_next;
			}
		break;
	case 3:
		cout<<"请输入系：";
		cin>>dept0;
		if ((p=findByDept(dept0)))
			while (p->stu_next!=NULL)
			{
				show(p->stu_next);
				p=p->stu_next;
			}
		break;
	case 4:
		cout<<"请输入班级：";
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
		cout<<"输入错误！"<<endl;
	}
	cout<<"已返回到菜单"<<endl; 
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
		cout<<"没有找到输入的届"<<endl;
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
		cout<<"没有找到输入的系"<<endl;
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
		cout<<"没有找到输入的姓名"<<endl;
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
	cout<<"没有找到输入的电话"<<endl;
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
		cout<<"没有找到输入的班级"<<endl;
		return NULL;
	}
	else
		return head_class;
}


void Student::Delete()
{
	Show();
	string Tel;
	cout<<"请输入要删除的号码："<<endl;
	cin>>Tel;
	DeleteByTel(Tel);
}

void Student::DeleteByTel(string &Tel)
{
	Stu *q, *p;
	p=findByTel(Tel);
	if (p==NULL)
	{
		cout<<"没有找到电话是“"<<Tel<<"”的同学, 删除失败"<<endl;
		return;
	}
	q=p->stu_next;
	p->stu_next=q->stu_next;
	delete q;
	cout<<"已删除电话为“"<<Tel<<"”的同学信息"<<endl;;
}


void Student::Modify()
{
	Show();
	cout<<"请输入要修改的同学信息的电话："<<endl;
	int count0=Count(); 
	string Tel;
	Stu *p; 
	cin>>Tel;
	p=findByTel(Tel);
	if (p==NULL)
	{
		cout<<"没有找到电话是“"<<Tel<<"”的同学, 修改失败"<<endl;
		return;
	}
	else
	{
		cout<<"请输入新的同学信息："<<endl;
		input();
		if (count0!=Count())
			DeleteByTel(Tel);
	}
}

void Student::saveToFile() 
{
	string new_file;
	cout << "请输入要保存的文件名: "; 
	cin >> new_file;
	fstream file;
	file.open(new_file.c_str(), ios::out);
	if (file.bad()) 
	{
		cout<<"文件打开失败！"<<endl;
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
	cout<<"保存成功！"<<endl;
	filename=new_file;
}
void Student::readFile() 
{
	string new_file;
	cout<<"请输入要读取的文件名："; 
	cin>>new_file;
	fstream file;
	file.open(new_file.c_str(), ios::in);
	if (file.bad()) 
	{
		cout<<"文件打开失败！"<<endl;
		return;
	}
	int len=0;
	file>>len;
	if (!len) 
	{
		cout<< "文件数据错误！"<<endl;
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
	cout<<"文件读入成功！"<<endl;
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
	cout<<"目前共有"<<Count()<<"位同学的信息"<<endl<<"-----------------------------------\n";
	for (p=head->stu_next;p;p=p->stu_next)
	{
		show(p);
	}
	cout<<"-----------------------------------\n";
}
void show(Stu *p)
{
	cout<<"姓名："<<p->stu_name<<"；性别："<<p->stu_sex<<"；年龄："<<p->stu_age<<"；届："<<p->stu_grad<<"；系："<<p->stu_dept<<"；班级："<<p->stu_class<<"；通讯地址："<<p->stu_addr<<"；电话："<<p->stu_tel<<"；QQ："<<p->stu_qq<<"；E-mail："<<p->stu_email<<endl;
}

void Student::Sort()
{
	int select;
	cout<<"1.按姓名排序\n2.按届排序\n请输入1-2（输入0返回菜单）：";
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
			cout<<"输入错误！"<<endl;
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
	cout<<"排序完成！"<<endl;
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
	cout<<"排序完成！"<<endl;
}

int Student::Count() const
{
	int count=0;
	Stu *p;
	for (p=head->stu_next;p;p=p->stu_next)
		count+=1;
	return count;
}
