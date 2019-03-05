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

/*******************************************************************����Ϊ������װ************************************************************************************/ 


//��¼
int Denglu(void)
{
	FILE * user;
	char username[20];
	char code[20];
	char code2[20];
	int choice,i;
	int flag = 0;
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��* * * * * * * * * * * * ѧ������ϵͳ * * * * * * * * * * * *��\n");
	printf("\t\t\t  �ǩ�������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                         �� ��¼                            ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                         �� ע��                            ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                         �� �˳�ϵͳ                        ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	printf("\n\n\t\t\t\t\t\t     ��ѡ��:");
	scanf("%d",&choice);
	system("cls");
	if(choice == 1)
	{
		for(i=0;i<3;i++)
		{
			printf("\n\n\n\t\t\t  ������������������������������������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t  ��* * * * * * * * * * ��ӭʹ��ѧ������ϵͳ! * * * * * * * * * *��\n");
			printf("\t\t\t  �ǩ���������������������������������������������������������������������������������������������������������������������������\n");
			printf("\n\n\n\t\t\t\t\t�������û�����");
			scanf("%s",username);
			user = fopen(username,"r");
			if(user == NULL)
			{
				if(i<2)
				{
					printf("\n\n\n\n\n\t\t\t\t\t�û��������ڣ����������룡");
					Sleep(1000);
				}
				system("cls");
			}	
			else if(user != NULL)
			{
				printf("\n\t\t\t\t\t���������룺  ");
				scanf("%s",code);
				fscanf(user,"%s",code2);
				if( strcmp(code,code2) == 0)
				{
					printf("\n\n\n\n\n\t\t\t\t\t\t    ��½�ɹ���");
					Sleep(1000);
					flag = 1; 
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\n\n\n\t\t\t\t\t ����������벻��ȷ��"); 
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
			printf("\n\n\n\t\t\t  ������������������������������������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t  ��* * * * * * * * * * ��ӭʹ��ѧ������ϵͳ! * * * * * * * * * *��\n");
			printf("\t\t\t  �ǩ���������������������������������������������������������������������������������������������������������������������������\n");
			printf("\n\n\n\t\t\t\t\t�������û�����");
			scanf("%s",username);
			user = fopen(username,"r");
			if(user != NULL)
			{
				printf("\n\n\n\n\n\t\t\t\t\t\t���û����Ѵ��ڣ�"); 
				Sleep(1000);
				system("cls");
			}	
			else
			{
				user = fopen(username,"w");
				printf("\n\t\t\t\t\t���������룺  ");
				scanf("%s",&code);
				fprintf(user,"%s",code);
				printf("\n\n\n\n\n\t\t\t\t\t\t ע��ɹ���");
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

//�����Ϣ
void Add(struct STU * stu)
{
	int sum;
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         ���ѧ����Ϣ                       ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	struct STU * NewStu = (struct STU *) malloc ( sizeof( struct STU ) );
	if(NewStu)
	{
		NewStu->next = stu->next;
		stu->next = NewStu;
		printf("\t\t\t������ѧ��������");
		scanf("%s",NewStu->name) ;
		printf("\t\t\t������ѧ��ѧ�ţ�");
		scanf("%s",NewStu->xuehao);
		printf("\t\t\t������ѧ�����ĳɼ���");
		scanf("%d",&NewStu->chinese);
		printf("\t\t\t������ѧ����ѧ�ɼ���");
		scanf("%d",&NewStu->math);
		printf("\t\t\t������ѧ��Ӣ��ɼ���");
		scanf("%d",&NewStu->english);
		NewStu->ave = (NewStu->chinese + NewStu->math + NewStu->english) / 3.0;
		NewStu->sum = NewStu->chinese + NewStu->math + NewStu->english;
		printf("\n\n\t\t\t\t\t\t      ��ӳɹ���");
	}
	else
		printf("\n\n\t\t\t\t\t\t      ���ʧ�ܣ������ڴ棡"); 
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
	getchar();
	getchar(); 
	
} 

//��ӡѧ����Ϣ 
void PrintList(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         �鿴����ѧ��                        ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	struct STU * pMove = stu->next;
	if(pMove)
	{
		while(pMove)
			{
				printf("\t\t\t\t\t\t   ������%s\n",pMove->name);
				printf("\t\t\t\t\t\t   ѧ�ţ�%s\n",pMove->xuehao);
				printf("\t\t\t\t\t\t   ���ģ�%d\n",pMove->chinese);
				printf("\t\t\t\t\t\t   ��ѧ��%d\n",pMove->math);
				printf("\t\t\t\t\t\t   Ӣ�%d\n",pMove->english);
				printf("\t\t\t\t\t\t   ƽ����%.1f\n",pMove->ave);
				printf("\t\t\t\t\t\t   �ܷ֣�%d\n",pMove->sum);
				printf("\n");
				pMove = pMove->next;
			}
			
	}
	else
	printf("\n\n\t\t\t\t\t\t   ��ǰ��ѧ����Ϣ��");
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
	getchar();
	getchar();
}

//����
void Search(struct STU * stu)
{
	int choice;
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         ����ѧ����Ϣ                       ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	char name2[20];
	char name3[20];
	int flag = 1;
	struct STU * pMove = stu->next;
	printf("\t\t\t\t    1.����������\n\n\t\t\t\t    2.��ѧ�Ų���\n\n\t\t\t\t    3.��ϲ���");
	printf("\n\n\n\t\t\t\t\t\t ��������ҷ�ʽ��");
	scanf("%d",&choice);
	system("cls");
	if (choice == 1)
	{
		printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t  ��                         ����ѧ����Ϣ                       ��\n");
		printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n");
		printf("\n\n\n\n\n\t\t\t\t\t\t  ������������"); 
		scanf("%s",name2);
		while(pMove)
		{
			if( strcmp( name2, pMove->name) == 0 )
			{
				printf("\n\n");
				printf("\t\t\t\t\t\t   ������%s\n",pMove->name);
				printf("\t\t\t\t\t\t   ѧ�ţ�%s\n",pMove->xuehao);
				printf("\t\t\t\t\t\t   ���ģ�%d\n",pMove->chinese);
				printf("\t\t\t\t\t\t   ��ѧ��%d\n",pMove->math);
				printf("\t\t\t\t\t\t   Ӣ�%d\n",pMove->english); 
				printf("\t\t\t\t\t\t   ƽ����%.1f\n",pMove->ave);
				printf("\t\t\t\t\t\t   �ܷ֣�%d\n",pMove->sum);
				flag = 0;
			}
			pMove = pMove->next;
		}
		if (flag == 1)
			printf("\n\n\n\n\n\n\t\t\t\t\t\t     ���޴��ˣ�");
	}
	else if(choice == 2)
	{	
		printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t  ��                         ����ѧ����Ϣ                       ��\n");
		printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n");
		printf("\n\n\n\t\t\t\t\t\t  ������ѧ�ţ�"); 
		scanf("%s",name2);
		while(pMove)
		{
			if( strcmp( name2, pMove->xuehao) == 0 )
			{
				printf("\n\n");
				printf("\t\t\t\t\t\t   ������%s\n",pMove->name);
				printf("\t\t\t\t\t\t   ѧ�ţ�%s\n",pMove->xuehao);
				printf("\t\t\t\t\t\t   ���ģ�%d\n",pMove->chinese);
				printf("\t\t\t\t\t\t   ��ѧ��%d\n",pMove->math);
				printf("\t\t\t\t\t\t   Ӣ�%d\n",pMove->english); 
				printf("\t\t\t\t\t\t   ƽ����%.1f\n",pMove->sum);
				flag = 0;
			}
			pMove = pMove->next;
		}
		if (flag == 1)
			printf("\n\n\n\n\t\t\t\t\t\t     ���޴��ˣ�");
		
	}
	else if(choice == 3)
	{
		printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t  ��                         ����ѧ����Ϣ                       ��\n");
		printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n");
		printf("\n\n\n\n\n\t\t\t\t\t\t  ������������"); 
		scanf("%s",name2);
		printf("\n\n\n\t\t\t\t\t\t  ������ѧ�ţ�"); 
		scanf("%s",name3);
		while(pMove)
		{
			if( strcmp( name2, pMove->name) == 0 )
			{
				if( strcmp( name3, pMove->xuehao) == 0 )
				{
					printf("\n\n");
					printf("\t\t\t\t\t\t   ������%s\n",pMove->name);
					printf("\t\t\t\t\t\t   ѧ�ţ�%s\n",pMove->xuehao);
					printf("\t\t\t\t\t\t   ���ģ�%d\n",pMove->chinese);
					printf("\t\t\t\t\t\t   ��ѧ��%d\n",pMove->math);
					printf("\t\t\t\t\t\t   Ӣ�%d\n",pMove->english); 
					printf("\t\t\t\t\t\t   ƽ����%.1f\n",pMove->sum);
					flag = 0;
				}
				
			}
			pMove = pMove->next;
		}
		if (flag == 1)
			printf("\n\n\n\n\t\t\t\t\t\t     ���޴��ˣ�");
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
	getchar();
	getchar(); 
}

//ɾ��
void Delete(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         ɾ��ѧ����Ϣ                       ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	char name2[20];
	struct STU * pMove = stu->next;
	struct STU * pFront = stu;
	printf("\t\t\t\t\t\t ������ѧ��������");
	scanf("%s",name2);
	while(1)
	{
		if (pMove ==NULL)
		{
			printf("\n\n\n\n\t\t\t\t\t\t     ���޴��ˣ�");
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
			printf("\n\n\n\n\t\t\t\t\t\t     ɾ���ɹ���");
			break;
		}
	}
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
	getchar();
	getchar(); 
} 

//�޸���Ϣ
void Change(struct STU * stu)
{
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         �޸�ѧ����Ϣ                       ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	char name2[20];
	int choice; 
	struct STU * pMove = stu->next;
	printf("\t\t\t\t\t\t ������ѧ��������");
	scanf("%s",name2);
	while(1)
	{
		if (pMove ==NULL)
		{
			printf("\n\n\n\n\t\t\t\t\t\t     ���޴��ˣ�");
			break; 
		}
		if( strcmp( name2, pMove->name) != 0 )
			pMove = pMove->next;
		else if( strcmp( name2, pMove->name) == 0 )
		{
			printf("\n\n\n");
			printf("\t\t\t\t\t\t  ������\n");
			printf("\t\t\t\t\t\t  ��ѧ��\n");
			printf("\t\t\t\t\t\t  ������\n");
			printf("\t\t\t\t\t\t  ����ѧ\n");
			printf("\t\t\t\t\t\t  ��Ӣ��\n");
			
			printf("\n\n\n\t\t\t\t\t\t �������޸�ѡ�"); 
			scanf("%d",&choice);
			getchar();
			system("cls");
			printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t  ��                         �޸�ѧ����Ϣ                       ��\n");
			printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
			printf("\n\n\n\t\t\t\t\t\t �������޸�Ϊ��"); 
			
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
				
			printf("\n\n\n\n\t\t\t\t\t\t     �޸ĳɹ���");
			break;
		}
	}
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
	getchar();
	getchar(); 
} 

//����
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
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         ����ѧ����Ϣ                       ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n");
	printf("\n\n\t\t\t\t    1.��ƽ��������\n\n\t\t\t\t    2.��ƽ���ֽ���\n\n\t\t\t\t    3.���ܷ�����\n\n\t\t\t\t    4.���ֽܷ���");
	printf("\n\n\n\n\t\t\t\t\t\t     ��ѡ��"); 
	scanf("%d",&choice); 
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         ����ѧ����Ϣ                       ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n");
	if(pMove == NULL)
	{
		printf("\n\n\n\n\t\t\t\t\t\t   ��ǰ��ѧ����Ϣ��");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
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
		printf("\n\n\n\n\t\t\t\t\t\t      ����ɹ���");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
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
		printf("\n\n\n\n\t\t\t\t\t\t      ����ɹ���");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
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
		printf("\n\n\n\n\t\t\t\t\t\t      ����ɹ���");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
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
		printf("\n\n\n\n\t\t\t\t\t\t      ����ɹ���");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
		getchar();
		getchar(); 
	}
}
	
//������
void Welcome(void)
{
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��* * * * * * * * * * * * ѧ������ϵͳ * * * * * * * * * * * *��\n");
	printf("\t\t\t  �ǩ�������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� ���ѧ����Ϣ                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� ����ѧ����Ϣ                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� ɾ��ѧ����Ϣ                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� �޸�ѧ����Ϣ                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� �鿴����ѧ��                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� ����ѧ����Ϣ                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ��                      �� �˳�����ϵͳ                       ��\n"); 
	printf("\t\t\t  ��                                                            ��\n"); 
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	printf("\t\t\t\t\t\t   ��ѡ����:");
	 
	
}

//���ļ��ж����� 
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

//�����ݱ��浽�ļ���
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


/****************************************************************������װ����������Ϊ������***************************************************************************/
int main()
{
	struct STU * stu = (struct STU *) malloc ( sizeof( struct STU ) ); 
	stu->next = NULL;
	int choice;
	int flag = Denglu();
	if (flag == 0)
	{
		printf("\n\n\n\t\t\t  ������������������������������������������������������������������������������������������������������������������������������\n");
		printf("\t\t\t  ��* * * * * * * * * * ��ӭʹ��ѧ������ϵͳ! * * * * * * * * * *��\n");
		printf("\t\t\t  �ǩ���������������������������������������������������������������������������������������������������������������������������\n");
		printf("\n\n\n\n\n\n\n\t\t\t\t           ����������࣬�����رճ���"); 
		Sleep(1000); 
	}
	else if(flag == 3)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t��л����ʹ�ã�������2���ر�");
		Sleep(1000);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t��л����ʹ�ã�������1���ر�");
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
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t��л����ʹ�ã�������2���ر�");
				Sleep(1000);
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t��л����ʹ�ã�������1���ر�");
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

