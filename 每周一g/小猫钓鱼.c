#include <stdio.h>
#define sSize 10
#define qSize 100

struct queue
{
	int data[qSize];
	int head , tail; 
};

struct stack
{
	int data[sSize];
	int top;
};

void initQueue(struct queue * q)
{
	q->head = 1;
	q->tail = 1;
}

void initStack(struct stack * s)
{
	s->top = 0;
}

void getQueue(struct queue * q , int n)
{
	printf("��������ֵ��");
	int i;
	for(i = 0 ; i < n  ; i++)
		scanf("%d" , &q->data[q->tail++]);
}

int main()
{
	struct queue * q1 = (struct queue *) malloc (sizeof(struct queue)); 
	struct queue * q2 = (struct queue *) malloc (sizeof(struct queue));
	struct stack * s = (struct stack *) malloc (sizeof(struct stack));
	initQueue(q1);
	initQueue(q2);
	initStack(s);
	int i , temp , n1 , n2;
	int book[10] = {0};
	printf("���һ�ĳ�ʼ������");
	scanf("%d" , &n1);
	getQueue(q1 , n1);
	printf("��Ҷ��ĳ�ʼ������");
	scanf("%d" , &n2);
	getQueue(q2 , n2);
	
	while(q1->head < q1->tail && q2->head < q2->tail)
	{
		//���һ���� 
		temp = q1->data[q1->head++];
		if(book[temp] == 0)
		{
			s->data[++s->top] = temp;
			book[temp] = 1;
		}
		else
		{
			q1->data[q1->tail++] = temp;
			while(s->data[s->top] != temp)
			{
				book[s->data[s->top]] = 0;
				q1->data[q1->tail++] = s->data[s->top--];
			}
		}
		
		//��Ҷ����� 
		temp = q2->data[q2->head++];
		if(book[temp] == 0)
		{
			s->data[++s->top] = temp;
			book[temp] = 1;
		}
		else
		{
			q2->data[q2->tail++] = temp;
			while(s->data[s->top] != temp)
			{
				book[s->data[s->top]] = 0;
				q2->data[q2->tail++] = s->data[s->top--];
			}
		}
	}
	if(q1->tail == q1->head)
		printf("���һ����");
	else
		printf("��Ҷ�����"); 
} 
