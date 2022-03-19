#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
	char name[15];//����
	char std[15];//ѧ��
	char Sclass[20];//�༶;
	int score[4];//4�γɼ�
	int All_score;//�ܳɼ�
	float mean;//�����ɼ�
	struct student* next;
};

student* creaheadnode();//�����ڵ�
student* find_student(char* name);//4.����ѧ����Ϣ
student* creaheadlist(student* T);//1.����ѧ����Ϣ
void modification(char *name);//2.�޸�ѧ����Ϣ
void print_list();//3.��ʾѧ����Ϣ
void dele_student(char* name);//5.ɾ��ѧ����Ϣ
void creafile();//6.����ѧ����Ϣ����¼�ļ�
void Randfile();//7.�Ӽ�¼�ļ���ȡѧ����Ϣ
void delefile();//8.��ռ�¼�ļ���Ϣ
void meau();//�˵�
void fun();//��ϵͳ���ܺ���
void safe_flush(FILE* fp)//�������
{
	int ch;
	while ((ch = fgetc(fp)) != EOF && ch != '\n');
}


int sum;//switch(sum)
student* head = creaheadnode();//ͷ�ڵ�
student* p = head;//¼����Ϣָ��

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
	printf("�������:");
	scanf("%d", &sum);
	switch (sum)
	{
		//================
	case 0:
		printf("�Ƴ�����...\n");
		exit(0);
	case 1:
	{
		char X;
		while (1) {
			p = creaheadlist(p);
			safe_flush(stdin);
			printf("�Ƿ����¼��(Y/N):");
			scanf("%c", &X);
			if (X == 'N'||X=='n') break;
		}
		break;
	}
	case 2:
	{
		printf("����Ҫ�޸��˵�������");
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
		printf("����Ҫ�����˵�����:");
		char* name = new char[15];
		scanf("%s", name);
		find_student(name);
		delete[] name;
		break;
	}
	case 5:
	{	
		printf("����Ҫɾ���˵�����:");
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
		printf("����...\n");
		break;
	//===============
	}
}

void delefile()
{
	FILE* fp;
	if ((fp = fopen("C:\\Users\\Public\\Documents\\ѧ������ϵͳ.txt", "w")) == NULL) {
		printf("�ļ��򿪴���(����û�д��ļ����Ƚ���6�����������ļ�)��\n");
		return;
	}
	fclose(fp);
	printf("��Ϣ��ճɹ�...\n");
	system("C:\\Users\\Public\\Documents\\ѧ������ϵͳ.txt");
}

void Randfile()
{
	FILE* fp;
	if ((fp = fopen("C:\\Users\\Public\\Documents\\ѧ������ϵͳ.txt", "r")) == NULL) {
		printf("�ļ��򿪴���(����û�д��ļ����Ƚ���6�����������ļ�)��\n");
		return;
	}
	while (fscanf(fp,"%d",0)!=EOF) {
		student* T = creaheadnode();
		fscanf(fp,"%s%s%s%d%d%d%d%d%f", T->Sclass, T->name, T->std, &T->score[0], &T->score[1], &T->score[2], &T->score[3],&T->All_score,&T->mean);
		p->next = T;
		p = T;
	}
	fclose(fp);
	printf("¼��ɹ�...\n");
	print_list();
}

void creafile()
{
	FILE* fp;
	if ((fp = fopen("C:\\Users\\Public\\Documents\\ѧ������ϵͳ.txt", "a+")) == NULL) {
		printf("�ļ��򿪴���(·��������ߴ�������)��\n");
		return;
	}
	student* list = head->next;
	while (list) {
		fprintf(fp,"%-16s%-8s%-16s%-8d%-8d%-8d%-8d%-8d%-8f\n", list->Sclass, list->name, list->std, list->score[0], list->score[1], list->score[2], list->score[3], list->All_score, list->mean);
		list = list->next;
	}
	fclose(fp);
	system("C:\\Users\\Public\\Documents\\ѧ������ϵͳ.txt");
}

void dele_student(char* name)
{
	char X;
	student* list= head;//�ú��������ѧ��
	student* tmp;
	safe_flush(stdin);//��������
	while (list->next!=NULL) {
		if (strcmp(name, list->next->name) == 0) {
			tmp = list->next;
			if (tmp->next == NULL) p = list;
			printf("�༶\t\t����\tѧ��\t\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4\n");
			printf("%-16s%-8s%-16s%-8d%-8d%-8d%-8d\n", tmp->Sclass, tmp->name, tmp->std, tmp->score[0], tmp->score[1], tmp->score[2], tmp->score[3]);
			printf("�Ƿ�ɾ����ѧ����Ϣ(Y/N):");
			scanf("%c", &X);
			if (X == 'Y' || X == 'y') {
				list->next = tmp->next;
				free(tmp);
				printf("ɾ���ɹ�!\n");
			}
			else printf("ȡ��ɾ��!\n");
			return;
		}
		list = list->next;
	}
	printf("����ʧ��!\n");
}
student* find_student(char* name)
{
	student* list = head->next;
	while (list) {
		if (strcmp(name,list->name)==0){
			printf("���ҳɹ�!\n");
			printf("�༶\t\t����\tѧ��\t\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4\t�ܳɼ�\tƽ���ɼ�\n");
			printf("%-16s%-8s%-16s%-8d%-8d%-8d%-8d%-8d%-8f\n", list->Sclass, list->name, list->std, list->score[0], list->score[1], list->score[2], list->score[3], list->All_score, list->mean);
			return list;//����ҵ����ظ�ѧ����Ϣ��ַ
		}
	list = list->next;
	}
	printf("���޴��ˣ�\n");
	return NULL;//���û�ҵ�����NULLָ��
}
void modification(char* name)
{
	student* list = head->next;
	list = find_student(name);//���ú�������ѧ��
	if (list) {
		printf("�����޸�����:\n");
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
	printf("��������༶,����,ѧ��,�ɼ�1,�ɼ�2,�ɼ�3,�ɼ�4\n");
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
	printf("�༶\t\t����\tѧ��\t\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ɼ�4\t�ܳɼ�\tƽ���ɼ�\n");
	while (list) {
		printf("%-16s%-8s%-16s%-8d%-8d%-8d%-8d%-8d%-8f\n", list->Sclass, list->name, list->std, list->score[0], list->score[1], list->score[2], list->score[3],list->All_score,list->mean);
		list = list->next;
	}
}
void meau()
{
	printf("\t��ѧ������ϵͳ��\t\n");
	printf("0.���н���\n");
	printf("1.����ѧ����Ϣ\n");
	printf("2.�޸�ѧ����Ϣ\n");
	printf("3.��ʾѧ����Ϣ\n");
	printf("4.��ѯѧ����Ϣ\n");
	printf("5.ɾ��ѧ����Ϣ\n");
	printf("6.����ѧ����Ϣ����¼�ļ�\n");
	printf("7.�Ӽ�¼�ļ���ȡѧ����Ϣ\n");
	printf("8.��ռ�¼�ļ���Ϣ\n");
}
