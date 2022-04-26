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
	printf("======================\t选择菜单键\t====================\n");
	printf("\t1.查找信息\n\t2.录入信息\n\t3.删除信息\n\t4.修改信息\n\t5.浏览所有信息\n\t6.程序使用指南\n");
	printf("\t0是退出\n");
	printf("\t注意请不要按除了12345以外的其他键，否则会有很严重的后果哦~\n");
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
	printf("----------------【当前所有成员信息】--------------------\n");
	printf("\t姓名\t年龄\t性别\t电话号码\n");
	if (pMove == NULL)
	{
		printf("没有成员信息\n");
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
		printf("没有数据，无法删除任何信息\n");
		return;
	}
	while (strcmp(posData->data.name, name) != 0)
	{
		FrontNode = posData;
		posData = posData->next;
		if (posData == NULL)
		{
			printf("查无此人，无法删除\n");
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
		printf("抱歉，没有成员信息\n");
		return NULL;
	}
	else
	{
		printf("姓名\t年龄\t性别\t电话号码\n");
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
		printf("抱歉，查无此人");
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
			printf("====================【用户信息】==================");
			printf("请问您需要修改什么信息\n");
			printf("1.名字\n2.年龄\n3.性别\n4.电话号码\n");
			int choice = 0;
			char toname[20];
			char togender[20] ;
			char totel [20];
				cin >> choice;
				switch (choice)
				{
				case 1:
					printf("请输入要修改后的名字：\n");
					cin >> toname;
				
						strcpy(newnode->data.name, toname);
						printf("修改成功！\n");
						break;
					
				case 3:
						printf("请输入修改后的性别：\n");
			
						cin >> togender;
						strcpy(newnode->data.gender, togender);
						printf("修改成功！");
						break;
					
				case 2:
					printf("请输入修改后的年龄：\n");
					int toold;
					cin >> toold;
					newnode->data.old = toold;
					printf("修改成功！\n");
					break;
				case 4:
					printf("请输入修改后的电话号码：");
					cin >> totel;
				
						strcpy(newnode->data.tel, totel);
						printf("修改成功！");
						break;
					
				default:
					printf("输入错误，请重新输入");
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
			printf("正常退出");
			system("pause");
			exit(0);
			break;
		case 1:
			printf("==================【查找用户信息】===============\n");
			printf("请输入你需要查找的用户名：");
			cin >> data.name;
			printfInfoBynode(List, data.name);
			break;
		case 2:
			printf("==================【录入新用户信息】==============\n");
				printf("请输入姓名，年龄，性别，电话号码：\n");
				fflush(stdin);				
		
			cin >> data.name >> data.old >> data.gender >> data.tel;
			insertInfoBynode(List, data);
			break;
		case 3:
			printf("==================【删除用户信息】================\n");
			cin >> data.name;
			deleteNode(List, data.name);
			break;
		case 4:
			printf("==================【修改用户信息】================\n");
			printf("请输入需要修改信息的人的名字：\n");
			fflush(stdin);
			cin >> data.name;
			changeInfo(List,data.name);
			break;
		case 5:
			printfnode(List);         
			break;
		case 6:
			printf("==================【说明指南】==============\n");
			printf("    感谢各位帮忙测试使用本款程序，对于程序的使用方法做如下解释：\n");
			printf("    本程序功能为录入、修改、删除、查找、浏览信息\n");
			printf("    1.一开始使用本程序时，得先添加信息，否则查找或者修改信息都会弹出查无此人之类的话。\n");
			printf("    2.本程序可以添加N组成员信息，大家可以放心添加。除此之外，如果有输入错误，在菜单界面上按下”修改信息“相对应的按键即可修改相应信息\n");
			printf("    3.为给用户更好的体验，在使用”修改信息“功能的时候，本软件提供对某一信息的精准修改\n");
		default:
			menu();
			printf("输入错误，请重新输入\n");
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

