#include<string>
#include<fstream>
using namespace std;

typedef struct student
{
	string stu_addr;//通讯地址
	string stu_name;//姓名
	int stu_age;//年龄
	string stu_sex;//性别
	int stu_grad;//届
	string stu_tel;//电话
	string stu_email;//邮箱
	string stu_dept;//系
	string stu_qq;//QQ号 
	string stu_class;//班级
	student *stu_next;
} Stu;

class Student
{
public:
	Student();
	~Student();

	void input();
	
	void Query() const;
	Stu *findByGrad(const int &Grad) const;
	Stu *findByName(const string &Name) const;
	Stu *findByDept(const string &Dept) const;
	Stu *findByClass(const string &Class) const;
	Stu *findByTel(const string &Tel) const;

	void Delete();
	void DeleteByTel(string &Tel);
	
	void Modify();
	
	void Show() const;
	
	void Sort();
	void SortByGrad();
	void SortByName();
	
	void saveToFile();
	void readFile();
	
	void insert(const Stu& temp);
	
	int Count() const;

private:
	Stu *head;
};
