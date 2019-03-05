#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct STU
{
	char name[20];
	char xuehao[20];
	int chinese;
	int math;
	int english;
	float ave;
	int sum;
	struct STU * next;
}stu;

/*******************************************************************以下为函数封装************************************************************************************/ 


//登录
int Denglu(void)
{
	FILE * user;
	char username[20];
	char code[20];
	char code2[20];
	int choice,i;
	int flag = 0;
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃* * * * * * * * * * * * 学生管理系统 * * * * * * * * * * * *┃\n");
	printf("\t\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                         ① 登录                            ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                         ② 注册                            ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                         ③ 退出系统                        ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	printf("\n\n\t\t\t\t\t\t     请选择:");
	scanf("%d",&choice);
	system("cls");
	if(choice == 1)
	{
		for(i=0;i<3;i++)
		{
			printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
			printf("\t\t\t  ┃* * * * * * * * * * 欢迎使用学生管理系统! * * * * * * * * * *┃\n");
			printf("\t\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
			printf("\n\n\n\t\t\t\t\t请输入用户名：");
			scanf("%s",username);
			user = fopen(username,"r");
			if(user == NULL)
			{
				if(i<2)
				{
					printf("\n\n\n\n\n\t\t\t\t\t用户名不存在，请重新输入！");
					Sleep(1000);
				}
				system("cls");
			}	
			else if(user != NULL)
			{
				printf("\n\t\t\t\t\t请输入密码：  ");
				scanf("%s",code);
				fscanf(user,"%s",code2);
				if( strcmp(code,code2) == 0)
				{
					printf("\n\n\n\n\n\t\t\t\t\t\t    登陆成功！");
					Sleep(1000);
					flag = 1; 
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\n\n\n\t\t\t\t\t 您输入的密码不正确！"); 
					Sleep(1000);
					system("cls");	
				}
				
			}
		}
		return flag;
	} 
	
	if(choice == 2)
	{
		while(1)
		{
			printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
			printf("\t\t\t  ┃* * * * * * * * * * 欢迎使用学生管理系统! * * * * * * * * * *┃\n");
			printf("\t\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
			printf("\n\n\n\t\t\t\t\t请输入用户名：");
			scanf("%s",username);
			user = fopen(username,"r");
			if(user != NULL)
			{
				printf("\n\n\n\n\n\t\t\t\t\t\t该用户名已存在！"); 
				Sleep(1000);
				system("cls");
			}	
			else
			{
				user = fopen(username,"w");
				printf("\n\t\t\t\t\t请输入密码：  ");
				scanf("%s",&code);
				fprintf(user,"%s",code);
				printf("\n\n\n\n\n\t\t\t\t\t\t 注册成功！");
				Sleep(1000);
				system("cls");
				break;
			}
		}
		return 1;
	}
	else
		return 3;
} 

//添加信息
void Add(struct STU * stu)
{
	int sum;
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         添加学生信息                       ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	struct STU * NewStu = (struct STU *) malloc ( sizeof( struct STU ) );
	if(NewStu)
	{
		NewStu->next = stu->next;
		stu->next = NewStu;
		printf("\t\t\t请输入学生姓名：");
		scanf("%s",NewStu->name) ;
		printf("\t\t\t请输入学生学号：");
		scanf("%s",NewStu->xuehao);
		printf("\t\t\t请输入学生语文成绩：");
		scanf("%d",&NewStu->chinese);
		printf("\t\t\t请输入学生数学成绩：");
		scanf("%d",&NewStu->math);
		printf("\t\t\t请输入学生英语成绩：");
		scanf("%d",&NewStu->english);
		NewStu->ave = (NewStu->chinese + NewStu->math + NewStu->english) / 3.0;
		NewStu->sum = NewStu->chinese + NewStu->math + NewStu->english;
		printf("\n\n\t\t\t\t\t\t      添加成功！");
	}
	else
		printf("\n\n\t\t\t\t\t\t      添加失败，请检查内存！"); 
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
	getchar();
	getchar(); 
	
} 

//打印学生信息 
void PrintList(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         查看所有学生                        ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	struct STU * pMove = stu->next;
	if(pMove)
	{
		while(pMove)
			{
				printf("\t\t\t\t\t\t   姓名：%s\n",pMove->name);
				printf("\t\t\t\t\t\t   学号：%s\n",pMove->xuehao);
				printf("\t\t\t\t\t\t   语文：%d\n",pMove->chinese);
				printf("\t\t\t\t\t\t   数学：%d\n",pMove->math);
				printf("\t\t\t\t\t\t   英语：%d\n",pMove->english);
				printf("\t\t\t\t\t\t   平均：%.1f\n",pMove->ave);
				printf("\t\t\t\t\t\t   总分：%d\n",pMove->sum);
				printf("\n");
				pMove = pMove->next;
			}
			
	}
	else
	printf("\n\n\t\t\t\t\t\t   当前无学生信息！");
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
	getchar();
	getchar();
}

//查找
void Search(struct STU * stu)
{
	int choice;
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         查找学生信息                       ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	char name2[20];
	char name3[20];
	int flag = 1;
	struct STU * pMove = stu->next;
	printf("\t\t\t\t    1.按姓名查找\n\n\t\t\t\t    2.按学号查找\n\n\t\t\t\t    3.混合查找");
	printf("\n\n\n\t\t\t\t\t\t 请输入查找方式：");
	scanf("%d",&choice);
	system("cls");
	if (choice == 1)
	{
		printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
		printf("\t\t\t  ┃                         查找学生信息                       ┃\n");
		printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
		printf("\n\n\n\n\n\t\t\t\t\t\t  请输入姓名："); 
		scanf("%s",name2);
		while(pMove)
		{
			if( strcmp( name2, pMove->name) == 0 )
			{
				printf("\n\n");
				printf("\t\t\t\t\t\t   姓名：%s\n",pMove->name);
				printf("\t\t\t\t\t\t   学号：%s\n",pMove->xuehao);
				printf("\t\t\t\t\t\t   语文：%d\n",pMove->chinese);
				printf("\t\t\t\t\t\t   数学：%d\n",pMove->math);
				printf("\t\t\t\t\t\t   英语：%d\n",pMove->english); 
				printf("\t\t\t\t\t\t   平均：%.1f\n",pMove->ave);
				printf("\t\t\t\t\t\t   总分：%d\n",pMove->sum);
				flag = 0;
			}
			pMove = pMove->next;
		}
		if (flag == 1)
			printf("\n\n\n\n\n\n\t\t\t\t\t\t     查无此人！");
	}
	else if(choice == 2)
	{	
		printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
		printf("\t\t\t  ┃                         查找学生信息                       ┃\n");
		printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
		printf("\n\n\n\t\t\t\t\t\t  请输入学号："); 
		scanf("%s",name2);
		while(pMove)
		{
			if( strcmp( name2, pMove->xuehao) == 0 )
			{
				printf("\n\n");
				printf("\t\t\t\t\t\t   姓名：%s\n",pMove->name);
				printf("\t\t\t\t\t\t   学号：%s\n",pMove->xuehao);
				printf("\t\t\t\t\t\t   语文：%d\n",pMove->chinese);
				printf("\t\t\t\t\t\t   数学：%d\n",pMove->math);
				printf("\t\t\t\t\t\t   英语：%d\n",pMove->english); 
				printf("\t\t\t\t\t\t   平均：%.1f\n",pMove->sum);
				flag = 0;
			}
			pMove = pMove->next;
		}
		if (flag == 1)
			printf("\n\n\n\n\t\t\t\t\t\t     查无此人！");
		
	}
	else if(choice == 3)
	{
		printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
		printf("\t\t\t  ┃                         查找学生信息                       ┃\n");
		printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
		printf("\n\n\n\n\n\t\t\t\t\t\t  请输入姓名："); 
		scanf("%s",name2);
		printf("\n\n\n\t\t\t\t\t\t  请输入学号："); 
		scanf("%s",name3);
		while(pMove)
		{
			if( strcmp( name2, pMove->name) == 0 )
			{
				if( strcmp( name3, pMove->xuehao) == 0 )
				{
					printf("\n\n");
					printf("\t\t\t\t\t\t   姓名：%s\n",pMove->name);
					printf("\t\t\t\t\t\t   学号：%s\n",pMove->xuehao);
					printf("\t\t\t\t\t\t   语文：%d\n",pMove->chinese);
					printf("\t\t\t\t\t\t   数学：%d\n",pMove->math);
					printf("\t\t\t\t\t\t   英语：%d\n",pMove->english); 
					printf("\t\t\t\t\t\t   平均：%.1f\n",pMove->sum);
					flag = 0;
				}
				
			}
			pMove = pMove->next;
		}
		if (flag == 1)
			printf("\n\n\n\n\t\t\t\t\t\t     查无此人！");
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
	getchar();
	getchar(); 
}

//删除
void Delete(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         删除学生信息                       ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	char name2[20];
	struct STU * pMove = stu->next;
	struct STU * pFront = stu;
	printf("\t\t\t\t\t\t 请输入学生姓名：");
	scanf("%s",name2);
	while(1)
	{
		if (pMove ==NULL)
		{
			printf("\n\n\n\n\t\t\t\t\t\t     查无此人！");
			break; 
		}
		if( strcmp( name2, pMove->name) != 0 )
		{
			pFront = pMove;
			pMove = pMove->next;
		}
		else if( strcmp( name2, pMove->name) == 0 )
		{
			pFront->next = pMove->next;
			free(pMove);
			printf("\n\n\n\n\t\t\t\t\t\t     删除成功！");
			break;
		}
	}
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
	getchar();
	getchar(); 
} 

//修改信息
void Change(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         修改学生信息                       ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	char name2[20];
	int choice; 
	struct STU * pMove = stu->next;
	printf("\t\t\t\t\t\t 请输入学生姓名：");
	scanf("%s",name2);
	while(1)
	{
		if (pMove ==NULL)
		{
			printf("\n\n\n\n\t\t\t\t\t\t     查无此人！");
			break; 
		}
		if( strcmp( name2, pMove->name) != 0 )
			pMove = pMove->next;
		else if( strcmp( name2, pMove->name) == 0 )
		{
			printf("\n\n\n");
			printf("\t\t\t\t\t\t  ①姓名\n");
			printf("\t\t\t\t\t\t  ②学号\n");
			printf("\t\t\t\t\t\t  ③语文\n");
			printf("\t\t\t\t\t\t  ④数学\n");
			printf("\t\t\t\t\t\t  ⑤英语\n");
			
			printf("\n\n\n\t\t\t\t\t\t 请输入修改选项："); 
			scanf("%d",&choice);
			getchar();
			system("cls");
			printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
			printf("\t\t\t  ┃                         修改学生信息                       ┃\n");
			printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
			printf("\n\n\n\t\t\t\t\t\t 将此项修改为："); 
			
			switch(choice)
			{
				case 1:
					scanf("%s",pMove->name);
					break;
				case 2:
					scanf("%s",pMove->xuehao);
					break;
				case 3:
					scanf("%d",&pMove->chinese);
					break;
				case 4:
					scanf("%d",&pMove->math);
					break;
				case 5:
					scanf("%d",&pMove->english);
					break;
			}
			if(choice == 3 || choice == 4 || choice == 5)
			{
				pMove->ave = (pMove->chinese + pMove->math + pMove->english) / 3.0;
				pMove->sum = pMove->chinese + pMove->math + pMove->english;
			}
				
			printf("\n\n\n\n\t\t\t\t\t\t     修改成功！");
			break;
		}
	}
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
	getchar();
	getchar(); 
} 

//排序
void Order(struct STU * stu)
{
	char X2[20];
	char N2[20];
	int M2;
	int C2;
	int E2;
	float A2;
	int S2;
	struct STU * pMove = stu->next->next;
	struct STU * pNext = stu->next;
	int choice; 
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         排序学生信息                       ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
	printf("\n\n\t\t\t\t    1.按平均分升序\n\n\t\t\t\t    2.按平均分降序\n\n\t\t\t\t    3.按总分升序\n\n\t\t\t\t    4.按总分降序");
	printf("\n\n\n\n\t\t\t\t\t\t     请选择："); 
	scanf("%d",&choice); 
	system("cls");
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃                         排序学生信息                       ┃\n");
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
	if(pMove == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\t\t   当前无学生信息！");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
		getchar();
		getchar();
	} 
	else if(choice == 1)
	{
		for(pMove = stu->next;pMove != NULL;pMove = pMove->next)
		{
			for(pNext = pMove->next;pNext != NULL;pNext = pNext->next)
			{
				if(pMove->ave >= pNext->ave)
				{
					strcpy(N2,pMove->name);
					strcpy(pMove->name,pNext->name);
					strcpy(pNext->name,N2);
					strcpy(X2,pMove->xuehao);
					strcpy(pMove->xuehao,pNext->xuehao);
					strcpy(pNext->xuehao,X2);
					C2 = pMove->chinese;
					pMove->chinese = pNext->chinese;
					pNext->chinese = C2;
					M2 = pMove->math;
					pMove->math = pNext->math;
					pNext->math = M2;
					E2 = pMove->english;
					pMove->english = pNext->english;
					pNext->english = E2;
					S2 = pMove->sum;
					pMove->sum = pNext->sum;
					pNext->sum = S2;
					A2 = pMove->ave;
					pMove->ave = pNext->ave;
					pNext->ave = A2;
					
				}
			}
		}
		printf("\n\n\n\n\t\t\t\t\t\t      排序成功！");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
		getchar();
		getchar(); 
	}
	else if(choice == 2)
	{
		for(pMove = stu->next;pMove != NULL;pMove = pMove->next)
		{
			for(pNext = pMove->next;pNext != NULL;pNext = pNext->next)
			{
				if(pMove->ave <= pNext->ave)
				{
					strcpy(N2,pMove->name);
					strcpy(pMove->name,pNext->name);
					strcpy(pNext->name,N2);
					strcpy(X2,pMove->xuehao);
					strcpy(pMove->xuehao,pNext->xuehao);
					strcpy(pNext->xuehao,X2);
					C2 = pMove->chinese;
					pMove->chinese = pNext->chinese;
					pNext->chinese = C2;
					M2 = pMove->math;
					pMove->math = pNext->math;
					pNext->math = M2;
					E2 = pMove->english;
					pMove->english = pNext->english;
					pNext->english = E2;
					S2 = pMove->sum;
					pMove->sum = pNext->sum;
					pNext->sum = S2;
					A2 = pMove->ave;
					pMove->ave = pNext->ave;
					pNext->ave = A2;
				}
			}
		}
		printf("\n\n\n\n\t\t\t\t\t\t      排序成功！");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
		getchar();
		getchar(); 
	}
	else if(choice == 3)	
	{
		for(pMove = stu->next;pMove != NULL;pMove = pMove->next)
		{
			for(pNext = pMove->next;pNext != NULL;pNext = pNext->next)
			{
				if(pMove->sum >= pNext->sum)
				{
					strcpy(N2,pMove->name);
					strcpy(pMove->name,pNext->name);
					strcpy(pNext->name,N2);
					strcpy(X2,pMove->xuehao);
					strcpy(pMove->xuehao,pNext->xuehao);
					strcpy(pNext->xuehao,X2);
					C2 = pMove->chinese;
					pMove->chinese = pNext->chinese;
					pNext->chinese = C2;
					M2 = pMove->math;
					pMove->math = pNext->math;
					pNext->math = M2;
					E2 = pMove->english;
					pMove->english = pNext->english;
					pNext->english = E2;
					S2 = pMove->sum;
					pMove->sum = pNext->sum;
					pNext->sum = S2;
					A2 = pMove->ave;
					pMove->ave = pNext->ave;
					pNext->ave = A2;
				}
			}
		}
		printf("\n\n\n\n\t\t\t\t\t\t      排序成功！");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
		getchar();
		getchar(); 
	}
	else
	{
		for(pMove = stu->next;pMove != NULL;pMove = pMove->next)
		{
			for(pNext = pMove->next;pNext != NULL;pNext = pNext->next)
			{
				if(pMove->sum <= pNext->sum)
				{
					strcpy(N2,pMove->name);
					strcpy(pMove->name,pNext->name);
					strcpy(pNext->name,N2);
					strcpy(X2,pMove->xuehao);
					strcpy(pMove->xuehao,pNext->xuehao);
					strcpy(pNext->xuehao,X2);
					C2 = pMove->chinese;
					pMove->chinese = pNext->chinese;
					pNext->chinese = C2;
					M2 = pMove->math;
					pMove->math = pNext->math;
					pNext->math = M2;
					E2 = pMove->english;
					pMove->english = pNext->english;
					pNext->english = E2;
					S2 = pMove->sum;
					pMove->sum = pNext->sum;
					pNext->sum = S2;
					A2 = pMove->ave;
					pMove->ave = pNext->ave;
					pNext->ave = A2;
				}
			}
		}
		printf("\n\n\n\n\t\t\t\t\t\t      排序成功！");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  按回车返回主菜单");
		getchar();
		getchar(); 
	}
}
	
//主界面
void Welcome(void)
{
	printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
	printf("\t\t\t  ┃* * * * * * * * * * * * 学生管理系统 * * * * * * * * * * * *┃\n");
	printf("\t\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ① 添加学生信息                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ② 查找学生信息                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ③ 删除学生信息                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ④ 修改学生信息                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ⑤ 查看所有学生                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ⑥ 排序学生信息                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┃                      ⑦ 退出管理系统                       ┃\n"); 
	printf("\t\t\t  ┃                                                            ┃\n"); 
	printf("\t\t\t  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"); 
	printf("\t\t\t\t\t\t   请选择功能:");
	 
	
}

//从文件中读数据 
void init(struct STU * stu)
{
	FILE * fp = fopen("stuinfo.dat","r");
	while(1)
	{
		struct STU * NewStu = (struct STU *) malloc ( sizeof( struct STU ) );
		if(fscanf(fp,"%s\t%s\t%d\t%d\t%d\t%f\t%d\n",NewStu->name,NewStu->xuehao,&NewStu->chinese,&NewStu->math,&NewStu->english,&NewStu->ave,&NewStu->sum) == EOF)
		{
			free(NewStu);
			break;
		}
		NewStu->next = stu->next;
		stu->next = NewStu;
	}
	fclose(fp);
}

//将数据保存到文件中
void Save(struct STU * stu) 
{
	FILE * fp = fopen("stuinfo.dat","w");
	if(fp == NULL)
		fp = fopen("stuinfo.dat","a");
	struct STU * pMove = stu->next;
	while(pMove)
	{
		fprintf(fp,"%s\t%s\t%d\t%d\t%d\t%f\t%d\n",pMove->name,pMove->xuehao,pMove->chinese,pMove->math,pMove->english,pMove->ave,pMove->sum);
		pMove = pMove->next;
	}
	fclose(fp);
}


/****************************************************************函数封装结束，以下为主函数***************************************************************************/
int main()
{
	struct STU * stu = (struct STU *) malloc ( sizeof( struct STU ) ); 
	stu->next = NULL;
	int choice;
	int flag = Denglu();
	if (flag == 0)
	{
		printf("\n\n\n\t\t\t  ┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n");
		printf("\t\t\t  ┃* * * * * * * * * * 欢迎使用学生管理系统! * * * * * * * * * *┃\n");
		printf("\t\t\t  ┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		printf("\n\n\n\n\n\n\n\t\t\t\t           错误次数过多，即将关闭程序"); 
		Sleep(1000); 
	}
	else if(flag == 3)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t感谢您的使用，程序将在2秒后关闭");
		Sleep(1000);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t感谢您的使用，程序将在1秒后关闭");
		Sleep(1000);
		system("cls");
	}
	
	else
	{ 
		init(stu);
		while(1)
		{
			system("cls");
			Welcome();
			scanf("%d",&choice);
			if (choice == 7)
			{
				Save(stu);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t感谢您的使用，程序将在2秒后关闭");
				Sleep(1000);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t感谢您的使用，程序将在1秒后关闭");
				Sleep(1000);
				system("cls");
				break; 
			}
			else
			{
				switch (choice)
				{
					case 1:
						Add(stu);
						break;
					case 2:
						Search(stu);
						break;
					case 3:
						Delete(stu);
						break;
					case 4:
						Change(stu);
						break;
					case 5:
						PrintList(stu);
						break;
					case 6:
						Order(stu);
						break;
				} 
			}
		}
	}
}

