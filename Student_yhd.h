#include<string>
#include<fstream>
using namespace std;

typedef struct student
{
	string stu_addr;//ͨѶ��ַ
	string stu_name;//����
	int stu_age;//����
	string stu_sex;//�Ա�
	int stu_grad;//��
	string stu_tel;//�绰
	string stu_email;//����
	string stu_dept;//ϵ
	string stu_qq;//QQ�� 
	string stu_class;//�༶
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
