/*������Ϊ����ѧ������ϵͳ����������+ģ�黯˼�룬����������˿���̨��ۣ�����ȱ�ݣ�����������飡 
  ���ʱ�䣺2019.1.27
  �����ߣ��ż�ΰ 
  ��������Dec-c++ 
*/  

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
	struct STU * next;
}stu;

struct DATA
{
	char name[20];
	char xuehao[20];
	int chinese;
	int math;
	int english;

}data;

/*******************************************************************����Ϊ������װ************************************************************************************/ 

//�����Ϣ
void Add(struct STU * stu)
{
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
	system("cls");
	printf("\n\n\n\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t  ��                         ����ѧ����Ϣ                       ��\n");
	printf("\t\t\t  ����������������������������������������������������������������������������������������������������������������������������\n\n"); 
	char name2[20];
	struct STU * pMove = stu->next;
	printf("\t\t\t\t\t\t ������ѧ��������");
	scanf("%s",name2);
	while(1)
	{
		if (pMove == NULL)
		{
			printf("\n\n\n\n\t\t\t\t\t\t     ���޴��ˣ�");
			break; 
		}
		if( strcmp( name2, pMove->name) != 0 )
			pMove = pMove->next;
		else if( strcmp( name2, pMove->name) == 0 )
		{
			printf("\n\n");
			printf("\t\t\t\t\t\t   ������%s\n",pMove->name);
			printf("\t\t\t\t\t\t   ѧ�ţ�%s\n",pMove->xuehao);
			printf("\t\t\t\t\t\t   ���ģ�%d\n",pMove->chinese);
			printf("\t\t\t\t\t\t   ��ѧ��%d\n",pMove->math);
			printf("\t\t\t\t\t\t   Ӣ�%d\n",pMove->english);
			break;
		}
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
					scanf("%d",pMove->chinese);
					break;
				case 4:
					scanf("%d",pMove->math);
					break;
				case 5:
					scanf("%d",pMove->english);
					break;
			}
			printf("\n\n\n\n\t\t\t\t\t\t     �޸ĳɹ���");
			break;
		}
	}
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  ���س��������˵�");
	getchar();
	getchar(); 
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
		if(fscanf(fp,"%s\t%s\t%d\t%d\t%d\n",NewStu->name,NewStu->xuehao,&NewStu->chinese,&NewStu->math,&NewStu->english) == EOF)
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
		fprintf(fp,"%s\t%s\t%d\t%d\t%d\n",pMove->name,pMove->xuehao,pMove->chinese,pMove->math,pMove->english);
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
	init(stu);
	while(1)
	{
		system("cls");
		Welcome();
		scanf("%d",&choice);
		if (choice == 6)
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
			}
		}
	}
}

