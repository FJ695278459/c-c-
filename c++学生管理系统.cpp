#include<iostream>
#include<stdlib.h>//����׼��ͷ�ļ���standard libaray�ܶ�ʹ��ĳЩ���� 
#include<list>
#include<fstream>//ofstream���ͷ�ļ� 
#include<windows.h>
#include<sstream>
#include<string>
using namespace std;
class student{
private:
	int age;//���� 
	string name;//���� 
	string ID;//ѧ�� 
	int score_chinese;//���ĳɼ�
	int score_math;//��ѧ�ɼ�
	int score_english;//Ӣ��ɼ�
	int total_score;//�ܳɼ� 
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
	cout<<"�������֣�";
 	cin>>name;
 	cout<<"�������䣺";
	cin>>age;
	cout<<"����ѧ�ţ�";
	cin>>ID;
	cout<<"�������ĳɼ���";
	cin>>score_chinese;
	cout<<"������ѧ�ɼ���";
	cin>>score_math;
	cout<<"����Ӣ��ɼ���";
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
static list<student> juju;//�洢ѧ����Ϣ 
//static string path="C:\\Users\\DELL\\Desktop\\student.txt";//�����ļ���·�� 
void mean();//���˵� 
void travel();//����������ӡѧ����Ϣ 
void func();//���ܺ��� 
void find();//�������ַ��ظ�ѧ��
void modification();//�޸�ѧ����Ϣ 
void Delete();//ɾ��ѧ����Ϣ 
bool rank(student &s1,student &s2);//���� 
void documention();//�����ļ� 
void read();//��ȡ�ļ����� 


int main()
{
	while(true)
	{
		mean();
		func();//����¼�� 
		system("pause");//��ͣ���ȴ����� 
		system("cls");//�����Ļ�ϵ�������ʾ 
	}
	return 0;
 } 
 
 
 
 student::student()
{
 	cout<<"�������֣�";
 	cin>>name;
 	cout<<"�������䣺";
	cin>>age;
	cout<<"����ѧ�ţ�";
	cin>>ID;
	cout<<"�������ĳɼ���";
	cin>>score_chinese;
	cout<<"������ѧ�ɼ���";
	cin>>score_math;
	cout<<"����Ӣ��ɼ���";
	cin>>score_english; 
	total_score=score_chinese+score_math+score_english; 
}
 
 void func()
 {
 	cout<<"��Ҫִ�еĲ�����"; 
 	int hanhan;
 	cin>>hanhan;
 	switch(hanhan)
 	{
 		case 0:{
		 //	cout<<"�˳�����"<<endl;
		 	exit(1);
			break;
		 }
		case 1:{
		//	cout<<"����"<<endl; 
			student a;
			//a.print();
			juju.push_back(a);
			break;
		}
		case 2:{
			cout<<"�����ļ�"<<endl;
			documention();
			break;
		}
		case 3:{
		//	cout<<"��ѯ"<<endl;
			find();
			break;
		}
		case 4:{
		//	cout<<"�޸�"<<endl;
			modification();
			break;
		}
		case 5:{
		//	cout<<"��ʾ"<<endl; 
			travel();
			break;
		}
		case 6:{
			//cout<<"����"<<endl;
			juju.sort(rank);
			cout<<"����ɹ�"<<endl;
			travel();
			break;
		}
		case 7:{
		//	cout<<"ɾ��"<<endl;
			Delete();
			break;
		}
		case 8:{
			cout<<"���ļ��ж�ȡ����"<<endl;
			read();
			break;
		}
		default:{
			cout<<"����ʧ��"<<endl; 
			break;
		} 
 		
	 }
 }
 void find()
 {
 	string m_name;
	 cout<<"����������:"; 
	 cin>>m_name;
	 for (list<student>::iterator i=juju.begin();i!=juju.end();i++) 
 	 {
 	 	if(i->getname()==m_name)
 	 	{
 	 		cout<<"����\t����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�"<<endl;
 	 		i->print();
 	 		return;
		  }
 	}
 	cout<<"��ѯʧ��"<<endl; 
 }
void modification()
{
	string m_modifica;
	cout<<"������ѧ��������"; 
	 cin>>m_modifica;
	 for (list<student>::iterator i=juju.begin();i!=juju.end();i++) 
 	 {
 	 	if(i->getname()==m_modifica)
 	 	{
 	 		cout<<"����\t����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�"<<endl;
 	 		i->print();
 	 		cout<<"�޸�ѧ����Ϣ"<<endl; 
 	 		i->n_modifica();
 	 		i->print();
 	 		return;
		  }
 	}
 	cout<<"��ѯʧ��"<<endl; 
}
void Delete()
{
	travel();
	string m_modifica;
	cout<<"������ѧ��������"; 
	 cin>>m_modifica;
	 for (list<student>::iterator i=juju.begin();i!=juju.end();i++) 
 	 {
 	 	if(i->getname()==m_modifica)
 	 	{
 	 		cout<<"ɾ��ѧ����Ϣ"<<endl; 
 	 		i=juju.erase(i);
 	 		return;
		  }
 	}
 	cout<<"��ѯʧ��"<<endl; 
 } 
 bool rank(student &s1,student &s2)
 {
 	return s1.gettotal_score()>s2.gettotal_score() ;
 }
 void documention()
 {
 	ofstream mycout("C:\\Users\\DELL\\Desktop\\student.txt");
	 mycout<< "����\t����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�"<<endl;
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
 		cout<<"���ļ�Ϊ��"<<endl;
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
 	cout<<"����\t����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�"<<endl;
 	 for (list<student>::iterator i=juju.begin();i!=juju.end();i++) 
 	 {
 	 	i->print();
 	 //	cout<<i->getname()<<endl;
	  }
 }
 void mean()
 {
 	cout<<"\t\t\t---------------------------------��ѧ������ϵͳ��----------------------------"<<endl;
 	cout<<"\t\t\t0.�˳�����"<<endl; 
 	cout<<"\t\t\t1.����ѧ����Ϣ"<<endl;
 	cout<<"\t\t\t2.��ѧ����Ϣ�����ļ�"<<endl; 
 	cout<<"\t\t\t3.��ѯѧ����Ϣ"<<endl;
 	cout<<"\t\t\t4.�޸�ѧ����Ϣ"<<endl;
 	cout<<"\t\t\t5.��ʾѧ���ɼ�"<<endl;
 	cout<<"\t\t\t6.��ѧ���ɼ�����"<<endl;
	cout<<"\t\t\t7.ɾ��ѧ����Ϣ"<<endl;
	cout<<"\t\t\t8.���ļ��ж�ȡ����"<<endl; 
	 
  } 

