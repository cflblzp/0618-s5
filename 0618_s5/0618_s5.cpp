#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
struct student {
	char name[20];
	char gender[20];
	int old;
	char tel[20];
};
struct node {
	struct student data;
	struct node* next;
};


struct node* creatList()
{
	struct node* headnode = (struct node*)malloc(sizeof(struct node));
	headnode->next = NULL;
	return headnode;
}



struct node* creatNode(struct student data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->data = data;
	return newnode;
}

void menu()
{
	printf("*****************Welcome to Information about Student system****************\n");
	printf("======================\tѡ��˵���\t====================\n");
	printf("\t1.������Ϣ\n\t2.¼����Ϣ\n\t3.ɾ����Ϣ\n\t4.�޸���Ϣ\n\t5.���������Ϣ\n\t6.����ʹ��ָ��\n");
	printf("\t0���˳�\n");
	printf("\tע���벻Ҫ������12345�������������������к����صĺ��Ŷ~\n");
}


void insertInfoBynode(struct node* headnode, struct student data)
{
	struct node* newnode = creatNode(data);
	newnode->next = headnode->next;
	
	headnode->next = newnode;
}


void printfnode(struct node* headnode)
{
	struct node* pMove = headnode->next;
	printf("----------------����ǰ���г�Ա��Ϣ��--------------------\n");
	printf("\t����\t����\t�Ա�\t�绰����\n");
	if (pMove == NULL)
	{
		printf("û�г�Ա��Ϣ\n");
		return;
	}
	while (pMove != NULL)
	{
		printf("\t%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.old, pMove->data.gender, pMove->data.tel);
		pMove = pMove->next;
	}
}



void deleteNode(struct node* headnode, char* name)
{
	struct node* posData = headnode->next;
	struct node* FrontNode = headnode;
	if (posData == NULL)
	{
		printf("û�����ݣ��޷�ɾ���κ���Ϣ\n");
		return;
	}
	while (strcmp(posData->data.name, name) != 0)
	{
		FrontNode = posData;
		posData = posData->next;
		if (posData == NULL)
		{
			printf("���޴��ˣ��޷�ɾ��\n");
			return;
		}
	}
	FrontNode->next = posData->next;
	free(posData);
	return;
}



struct node* printfInfoBynode(struct node* headnode, char* name)
{
	struct node* pMove = headnode->next;
	while (pMove != NULL && strcmp(pMove->data.name, name) != 0)
	{
		pMove = pMove->next;
	}
	if (pMove == NULL)
	{
		printf("��Ǹ��û�г�Ա��Ϣ\n");
		return NULL;
	}
	else
	{
		printf("����\t����\t�Ա�\t�绰����\n");
		printf("%s\t%d\t%s\t%s\n", pMove->data.name, pMove->data.old, pMove->data.gender, pMove->data.tel);
		return pMove;
	}
}



struct node* searchNode(struct node* headnode, char* name)
{
	struct node* pMove = headnode->next;
	while (pMove != NULL && strcmp(pMove->data.name, name) != 0)
	{
		pMove = pMove->next;
	}
	if (pMove == NULL)
	{
		printf("��Ǹ�����޴���");
		return NULL;
	}
	else
	{
		return pMove;
	}
}



void changeInfo(struct node* headnode,char* name)
{
	struct node* newnode = searchNode(headnode,name);
	printfInfoBynode(headnode, name);
	if (newnode == NULL)
	{
		return;
	}
	else{
			printf("====================���û���Ϣ��==================");
			printf("��������Ҫ�޸�ʲô��Ϣ\n");
			printf("1.����\n2.����\n3.�Ա�\n4.�绰����\n");
			int choice = 0;
			char toname[20];
			char togender[20] ;
			char totel [20];
				cin >> choice;
				switch (choice)
				{
				case 1:
					printf("������Ҫ�޸ĺ�����֣�\n");
					cin >> toname;
				
						strcpy(newnode->data.name, toname);
						printf("�޸ĳɹ���\n");
						break;
					
				case 3:
						printf("�������޸ĺ���Ա�\n");
			
						cin >> togender;
						strcpy(newnode->data.gender, togender);
						printf("�޸ĳɹ���");
						break;
					
				case 2:
					printf("�������޸ĺ�����䣺\n");
					int toold;
					cin >> toold;
					newnode->data.old = toold;
					printf("�޸ĳɹ���\n");
					break;
				case 4:
					printf("�������޸ĺ�ĵ绰���룺");
					cin >> totel;
				
						strcpy(newnode->data.tel, totel);
						printf("�޸ĳɹ���");
						break;
					
				default:
					printf("�����������������");
					break;
				}
	}
}

struct node* List = creatList();

void select()
{
	struct student data;
	int number;
	cin >> number;
		switch (number)
		{
		case 0:
			printf("�����˳�");
			system("pause");
			exit(0);
			break;
		case 1:
			printf("==================�������û���Ϣ��===============\n");
			printf("����������Ҫ���ҵ��û�����");
			cin >> data.name;
			printfInfoBynode(List, data.name);
			break;
		case 2:
			printf("==================��¼�����û���Ϣ��==============\n");
				printf("���������������䣬�Ա𣬵绰���룺\n");
				fflush(stdin);				
		
			cin >> data.name >> data.old >> data.gender >> data.tel;
			insertInfoBynode(List, data);
			break;
		case 3:
			printf("==================��ɾ���û���Ϣ��================\n");
			cin >> data.name;
			deleteNode(List, data.name);
			break;
		case 4:
			printf("==================���޸��û���Ϣ��================\n");
			printf("��������Ҫ�޸���Ϣ���˵����֣�\n");
			fflush(stdin);
			cin >> data.name;
			changeInfo(List,data.name);
			break;
		case 5:
			printfnode(List);         
			break;
		case 6:
			printf("==================��˵��ָ�ϡ�==============\n");
			printf("    ��л��λ��æ����ʹ�ñ�����򣬶��ڳ����ʹ�÷��������½��ͣ�\n");
			printf("    ��������Ϊ¼�롢�޸ġ�ɾ�������ҡ������Ϣ\n");
			printf("    1.һ��ʼʹ�ñ�����ʱ�����������Ϣ��������һ����޸���Ϣ���ᵯ�����޴���֮��Ļ���\n");
			printf("    2.������������N���Ա��Ϣ����ҿ��Է�����ӡ�����֮�⣬�������������ڲ˵������ϰ��¡��޸���Ϣ�����Ӧ�İ��������޸���Ӧ��Ϣ\n");
			printf("    3.Ϊ���û����õ����飬��ʹ�á��޸���Ϣ�����ܵ�ʱ�򣬱�����ṩ��ĳһ��Ϣ�ľ�׼�޸�\n");
		default:
			menu();
			printf("�����������������\n");
			break;
		}
	
}




int main()
{
	while (1)
	{
		menu();
		select();
		system("pause");
		system("cls");
	}
}

