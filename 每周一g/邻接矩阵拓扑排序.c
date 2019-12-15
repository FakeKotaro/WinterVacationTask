#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct
{
	int vexnum;			//顶点数目
	int arcnum;			//边数目
	int arcs[MAXSIZE][MAXSIZE];
	char vex[MAXSIZE];
	int in[MAXSIZE];
}adj , *AdjMatrix;

typedef struct
{
	int index[MAXSIZE];
	int top;
}stack , *Stack;

void initStack(Stack s)
{
	s->top = 0;
}

int pop(Stack s)
{
	s->top--;
	return s->index[s->top];
}

void push(Stack s , int index) 
{
	s->index[s->top] = index;
	s->top++;
}

int isEmpty(Stack s)
{
	if(s->top == 0)
		return 1;
	return 0;
}

int getIndex(AdjMatrix G , char v)
{
	int i;
	for(i = 0 ; i < G->vexnum ; i++)
	{
		if(G->vex[i] == v)
			return i;
	}
}

void create(AdjMatrix G)
{
	int i , j , a , b;
	char v1 , v2;
	scanf("%d %d" , &G->vexnum , &G->arcnum);
	fflush(stdin);
	for(i = 0 ; i < G->vexnum ; i++)
		scanf("%c",&G->vex[i]);
	fflush(stdin);
	for(i = 0 ; i < G->vexnum ; i++)
		for(j = 0 ; j < G->vexnum ; j++)
			G->arcs[i][j] = 0;
	for(i = 0 ; i < G->vexnum ; i++)
		G->in[i] = 0;
	for(i = 0 ; i < G->arcnum ; i++)
	{
		scanf("<%c,%c>" , &v1 , &v2);
		a = getIndex(G , v1);
		b = getIndex(G , v2);
		G->arcs[a][b] = 1;
		G->in[b]++;
	}
}

void topoSort(AdjMatrix G)
{
	int i;
	Stack s = (Stack) malloc (sizeof(stack));
	initStack(s);
	for(i = 0 ; i < G->vexnum ; i++)
		if(G->in[i] == 0)
			push(s , i);
	while(!isEmpty(s))
	{
		int t = pop(s);
		printf("%c" , G->vex[t]);
		for(i = 0 ; i < G->vexnum ; i++)
  		{
  			if(G->arcs[t][i] == 1)
   			{
    			G->in[i]--;
    			if(G->in[i] ==0)
    				push(s , i);
    		}
		}
	}
}

int main()
{
	AdjMatrix G = (adj *) malloc (sizeof(adj));
	create(G);
	topoSort(G);
}

