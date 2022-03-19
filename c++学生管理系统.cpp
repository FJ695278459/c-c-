#include<iostream>
#include<stdlib.h>//（标准库头文件）standard libaray能都使用某些函数 
#include<list>
#include<fstream>//ofstream类的头文件 
#include<windows.h>
#include<sstream>
#include<string>
using namespace std;
class student{
private:
	int age;//年龄 
	string name;//名字 
	string ID;//学号 
	int score_chinese;//语文成绩
	int score_math;//数学成绩
	int score_english;//英语成绩
	int total_score;//总成绩 
public:
	student();
	student(string biu)
	{
		stringstream f(biu);
		string s;
		getline(f,s,'\t');
		this->name=s;
		getline(f,s,'\t');
		this->age=atoi(s.c_str());
		getline(f,s,'\t');
		this->ID=s;
		getline(f,s,'\t');
		this->score_chinese =atoi(s.c_str());
		getline(f,s,'\t');
		this->score_english =atoi(s.c_str());
		getline(f,s,'\t');
		this->score_math =atoi(s.c_str());
		getline(f,s,'\t');
		this->total_score =atoi(s.c_str()); 
	}
	void n_modifica()
	{
	cout<<"输入名字：";
 	cin>>name;
 	cout<<"输入年龄：";
	cin>>age;
	cout<<"输入学号：";
	cin>>ID;
	cout<<"输入语文成绩：";
	cin>>score_chinese;
	cout<<"输入数学成绩：";
	cin>>score_math;
	cout<<"输入英语成绩：";
	cin>>score_english; 
	total_score=score_chinese+score_math+score_english; 
	}	
	void print()
	{
		cout<<name<<"\t";
		cout<<age<<"\t";
		cout<<ID<<"\t";
		cout<<score_chinese<<"\t";
		cout<<score_math<<"\t";
		cout<<score_english<<"\t";
		cout<<total_score<<endl; 
	}

	string getname()
	{
		return this->name;
	}
	int getage()
	{
		return this->age;
	}
	string getID()
	{
		return this->ID; 
	}
	int getscore_chinese()
	{
		return this->score_chinese;
	 } 
	int getscore_math()
	{
		return this->score_math;
	}
	int getscore_english()
	{
		return this->score_english;
	}
	int gettotal_score()
	{
		return this->total_score;
	 } 
};
static list<student> juju;//存储学生信息 
//static string path="C:\\Users\\DELL\\Desktop\\student.txt";//储存文件的路径 
void mean();//主菜单 
void travel();//遍历链表，打印学生信息 
void func();//功能函数 
void find();//根据名字返回该学生
void modification();//修改学生信息 
void Delete();//删除学生信息 
bool rank(student &s1,student &s2);//排序 
void documention();//导入文件 
void read();//读取文件数据 


int main()
{
	while(true)
	{
		mean();
		func();//功能录入 
		system("pause");//暂停，等待输入 
		system("cls");//清除屏幕上的所有显示 
	}
	return 0;
 } 
 
 
 
 student::student()
{
 	cout<<"输入名字：";
 	cin>>name;
 	cout<<"输入年龄：";
	cin>>age;
	cout<<"输入学号：";
	cin>>ID;
	cout<<"输入语文成绩：";
	cin>>score_chinese;
	cout<<"输入数学成绩：";
	cin>>score_math;
	cout<<"输入英语成绩：";
	cin>>score_english; 
	total_score=score_chinese+score_math+score_english; 
}
 
 void func()
 {
 	cout<<"你要执行的操作："; 
 	int hanhan;
 	cin>>hanhan;
 	switch(hanhan)
 	{
 		case 0:{
		 //	cout<<"退出程序"<<endl;
		 	exit(1);
			break;
		 }
		case 1:{
		//	cout<<"增添"<<endl; 
			student a;
			//a.print();
			juju.push_back(a);
			break;
		}
		case 2:{
			cout<<"导入文件"<<endl;
			documention();
			break;
		}
		case 3:{
		//	cout<<"查询"<<endl;
			find();
			break;
		}
		case 4:{
		//	cout<<"修改"<<endl;
			modification();
			break;
		}
		case 5:{
		//	cout<<"显示"<<endl; 
			travel();
			break;
		}
		case 6:{
			//cout<<"排序"<<endl;
			juju.sort(rank);
			cout<<"排序成功"<<endl;
			travel();
			break;
		}
		case 7:{
		//	cout<<"删除"<<endl;
			Delete();
			break;
		}
		case 8:{
			cout<<"从文件中读取数据"<<endl;
			read();
			break;
		}
		default:{
			cout<<"操作失败"<<endl; 
			break;
		} 
 		
	 }
 }
 void find()
 {
 	string m_name;
	 cout<<"请输入名字:"; 
	 cin>>m_name;
	 for (list<student>::iterator i=juju.begin();i!=juju.end();i++) 
 	 {
 	 	if(i->getname()==m_name)
 	 	{
 	 		cout<<"姓名\t年龄\t学号\t语文\t数学\t英语\t总分"<<endl;
 	 		i->print();
 	 		return;
		  }
 	}
 	cout<<"查询失败"<<endl; 
 }
void modification()
{
	string m_modifica;
	cout<<"请输入学生姓名："; 
	 cin>>m_modifica;
	 for (list<student>::iterator i=juju.begin();i!=juju.end();i++) 
 	 {
 	 	if(i->getname()==m_modifica)
 	 	{
 	 		cout<<"姓名\t年龄\t学号\t语文\t数学\t英语\t总分"<<endl;
 	 		i->print();
 	 		cout<<"修改学生信息"<<endl; 
 	 		i->n_modifica();
 	 		i->print();
 	 		return;
		  }
 	}
 	cout<<"查询失败"<<endl; 
}
void Delete()
{
	travel();
	string m_modifica;
	cout<<"请输入学生姓名："; 
	 cin>>m_modifica;
	 for (list<student>::iterator i=juju.begin();i!=juju.end();i++) 
 	 {
 	 	if(i->getname()==m_modifica)
 	 	{
 	 		cout<<"删除学生信息"<<endl; 
 	 		i=juju.erase(i);
 	 		return;
		  }
 	}
 	cout<<"查询失败"<<endl; 
 } 
 bool rank(student &s1,student &s2)
 {
 	return s1.gettotal_score()>s2.gettotal_score() ;
 }
 void documention()
 {
 	ofstream mycout("C:\\Users\\DELL\\Desktop\\student.txt");
	 mycout<< "姓名\t年龄\t学号\t语文\t数学\t英语\t总分"<<endl;
	 for (list<student>::iterator i=juju.begin();i!=juju.end();i++) 
 	 {
		mycout<<i->getname()<<"\t";
		mycout<<i->getage()<<"\t";
		mycout<<i->getID()<<"\t";
		mycout<<i->getscore_chinese()<<"\t";
		mycout<<i->getscore_math()<<"\t";
		mycout<<i->getscore_english()<<"\t";
		mycout<<i->gettotal_score()<<endl; 
	  }
	  mycout.close();
	  system("C:\\Users\\DELL\\Desktop\\student.txt");
  } 
 void read()
 {
 	ifstream pig("C:\\Users\\DELL\\Desktop\\student.txt");
 	string hen;
 	if(!getline(pig,hen))
 	{
 		cout<<"此文件为空"<<endl;
 		return;
	 }
	 while(getline(pig,hen))
	 {
	 	student bugu(hen); 
	 	juju.push_front(bugu);
		cout<<hen<<endl;
	 }
	 pig.close();
 	
 }
 void travel()
 {
 	cout<<"姓名\t年龄\t学号\t语文\t数学\t英语\t总分"<<endl;
 	 for (list<student>::iterator i=juju.begin();i!=juju.end();i++) 
 	 {
 	 	i->print();
 	 //	cout<<i->getname()<<endl;
	  }
 }
 void mean()
 {
 	cout<<"\t\t\t---------------------------------【学生管理系统】----------------------------"<<endl;
 	cout<<"\t\t\t0.退出程序"<<endl; 
 	cout<<"\t\t\t1.增添学生信息"<<endl;
 	cout<<"\t\t\t2.将学生信息导入文件"<<endl; 
 	cout<<"\t\t\t3.查询学生信息"<<endl;
 	cout<<"\t\t\t4.修改学生信息"<<endl;
 	cout<<"\t\t\t5.显示学生成绩"<<endl;
 	cout<<"\t\t\t6.将学生成绩排序"<<endl;
	cout<<"\t\t\t7.删除学生信息"<<endl;
	cout<<"\t\t\t8.从文件中读取数据"<<endl; 
	 
  } 

