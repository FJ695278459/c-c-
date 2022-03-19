#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
	char name[15];//名字
	char std[15];//学号
	char Sclass[20];//班级;
	int score[4];//4课成绩
	int All_score;//总成绩
	float mean;//评均成绩
	struct student* next;
};

student* creaheadnode();//创建节点
student* find_student(char* name);//4.查找学生信息
student* creaheadlist(student* T);//1.增加学生信息
void modification(char *name);//2.修改学生信息
void print_list();//3.显示学生信息
void dele_student(char* name);//5.删除学生信息
void creafile();//6.保存学生信息至记录文件
void Randfile();//7.从记录文件读取学生信息
void delefile();//8.情空记录文件信息
void meau();//菜单
void fun();//主系统功能函数
void safe_flush(FILE* fp)//清楚缓存
{
	int ch;
	while ((ch = fgetc(fp)) != EOF && ch != '\n');
}


int sum;//switch(sum)
student* head = creaheadnode();//头节点
student* p = head;//录入信息指针

int main()
{
	while (1)
	{
		meau();
		fun();
		system("pause");
		system("cls");
	}
	return 0;
}


void fun()
{
	printf("输入操作:");
	scanf("%d", &sum);
	switch (sum)
	{
		//================
	case 0:
		printf("推出程序...\n");
		exit(0);
	case 1:
	{
		char X;
		while (1) {
			p = creaheadlist(p);
			safe_flush(stdin);
			printf("是否继续录入(Y/N):");
			scanf("%c", &X);
			if (X == 'N'||X=='n') break;
		}
		break;
	}
	case 2:
	{
		printf("输入要修改人的姓名：");
		char* name = new char[15];
		scanf("%s", name);
		modification(name);
		delete[] name;
		break;
	}
	case 3:
		print_list();
		break;
	case 4:
	{
		printf("输入要查找人的姓名:");
		char* name = new char[15];
		scanf("%s", name);
		find_student(name);
		delete[] name;
		break;
	}
	case 5:
	{	
		printf("输入要删除人的姓名:");
		char* name = new char[15];
		scanf("%s", name);
		dele_student(name);
		delete[] name;
		break;
	}
	case 6:
	{
		creafile();
		break;
	}
	case 7:
	{
		Randfile();
		break;
	}
	case 8:
	{
		delefile();
		break;
	}
	default:
		printf("错误...\n");
		break;
	//===============
	}
}

void delefile()
{
	FILE* fp;
	if ((fp = fopen("C:\\Users\\Public\\Documents\\学生管理系统.txt", "w")) == NULL) {
		printf("文件打开错误(可能没有此文件，先进行6操作创建此文件)！\n");
		return;
	}
	fclose(fp);
	printf("信息清空成功...\n");
	system("C:\\Users\\Public\\Documents\\学生管理系统.txt");
}

void Randfile()
{
	FILE* fp;
	if ((fp = fopen("C:\\Users\\Public\\Documents\\学生管理系统.txt", "r")) == NULL) {
		printf("文件打开错误(可能没有此文件，先进行6操作创建此文件)！\n");
		return;
	}
	while (fscanf(fp,"%d",0)!=EOF) {
		student* T = creaheadnode();
		fscanf(fp,"%s%s%s%d%d%d%d%d%f", T->Sclass, T->name, T->std, &T->score[0], &T->score[1], &T->score[2], &T->score[3],&T->All_score,&T->mean);
		p->next = T;
		p = T;
	}
	fclose(fp);
	printf("录入成功...\n");
	print_list();
}

void creafile()
{
	FILE* fp;
	if ((fp = fopen("C:\\Users\\Public\\Documents\\学生管理系统.txt", "a+")) == NULL) {
		printf("文件打开错误(路径问题或者磁盘问题)！\n");
		return;
	}
	student* list = head->next;
	while (list) {
		fprintf(fp,"%-16s%-8s%-16s%-8d%-8d%-8d%-8d%-8d%-8f\n", list->Sclass, list->name, list->std, list->score[0], list->score[1], list->score[2], list->score[3], list->All_score, list->mean);
		list = list->next;
	}
	fclose(fp);
	system("C:\\Users\\Public\\Documents\\学生管理系统.txt");
}

void dele_student(char* name)
{
	char X;
	student* list= head;//用函数查调找学生
	student* tmp;
	safe_flush(stdin);//消除缓存
	while (list->next!=NULL) {
		if (strcmp(name, list->next->name) == 0) {
			tmp = list->next;
			if (tmp->next == NULL) p = list;
			printf("班级\t\t名字\t学号\t\t成绩1\t成绩2\t成绩3\t成绩4\n");
			printf("%-16s%-8s%-16s%-8d%-8d%-8d%-8d\n", tmp->Sclass, tmp->name, tmp->std, tmp->score[0], tmp->score[1], tmp->score[2], tmp->score[3]);
			printf("是否删除该学生信息(Y/N):");
			scanf("%c", &X);
			if (X == 'Y' || X == 'y') {
				list->next = tmp->next;
				free(tmp);
				printf("删除成功!\n");
			}
			else printf("取消删除!\n");
			return;
		}
		list = list->next;
	}
	printf("查找失败!\n");
}
student* find_student(char* name)
{
	student* list = head->next;
	while (list) {
		if (strcmp(name,list->name)==0){
			printf("查找成功!\n");
			printf("班级\t\t名字\t学号\t\t成绩1\t成绩2\t成绩3\t成绩4\t总成绩\t平均成绩\n");
			printf("%-16s%-8s%-16s%-8d%-8d%-8d%-8d%-8d%-8f\n", list->Sclass, list->name, list->std, list->score[0], list->score[1], list->score[2], list->score[3], list->All_score, list->mean);
			return list;//如果找到返回该学生信息地址
		}
	list = list->next;
	}
	printf("查无此人！\n");
	return NULL;//如果没找到返回NULL指针
}
void modification(char* name)
{
	student* list = head->next;
	list = find_student(name);//调用函数查找学生
	if (list) {
		printf("输入修改内容:\n");
		scanf("%s%s%s%d%d%d%d", list->Sclass, list->name, list->std, &list->score[0], &list->score[1], &list->score[2], &list->score[3]);
	}
}
student* creaheadnode()
{
	student* headnode = (student*)malloc(sizeof(student));
	headnode->next = NULL;
	return headnode;
}
student* creaheadlist(student* X)
{
	student* list = creaheadnode();
	printf("依次输入班级,名字,学号,成绩1,成绩2,成绩3,成绩4\n");
	scanf("%s%s%s%d%d%d%d", list->Sclass, list->name, list->std, &list->score[0], &list->score[1], &list->score[2], &list->score[3]);
	list->All_score = 0;
	for (int i = 0; i < 4; i++) {
		list->All_score += list->score[i];
	}
	list->mean =list->All_score/4.0;
	X->next = list;
	X = list;
	return X;
}
void print_list()
{
	student* list = head->next;
	printf("班级\t\t名字\t学号\t\t成绩1\t成绩2\t成绩3\t成绩4\t总成绩\t平均成绩\n");
	while (list) {
		printf("%-16s%-8s%-16s%-8d%-8d%-8d%-8d%-8d%-8f\n", list->Sclass, list->name, list->std, list->score[0], list->score[1], list->score[2], list->score[3],list->All_score,list->mean);
		list = list->next;
	}
}
void meau()
{
	printf("\t【学生管理系统】\t\n");
	printf("0.运行结束\n");
	printf("1.增加学生信息\n");
	printf("2.修改学生信息\n");
	printf("3.显示学生信息\n");
	printf("4.查询学生信息\n");
	printf("5.删除学生信息\n");
	printf("6.保存学生信息至记录文件\n");
	printf("7.从记录文件读取学生信息\n");
	printf("8.清空记录文件信息\n");
}
