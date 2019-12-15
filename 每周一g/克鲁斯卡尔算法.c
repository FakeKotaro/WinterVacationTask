#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

typedef struct
{
	int v1 , v2;
	int weight;
}road,*Road;

typedef struct
{
	char vex[MAXSIZE];
	int vexnum;
	int roadnum;
	road roads[MAXSIZE];
}graph , *Graph;

int root[MAXSIZE];  //²¢²é¼¯

int getIndex(Graph G , char v)
{
	int i , t;
	for(i = 0 ; i < G->vexnum ; i++)
	{
		if(G->vex[i] == v)
			return i;
	}
}

void initGraph(Graph G)
{
	int i, j;
	char v1, v2;
	scanf("%d %d", &G->vexnum, &G->roadnum);
	getchar();
	for (i = 0; i < G->vexnum; i++)
		scanf("%c", &G->vex[i]);
	getchar();
	for (i = 0; i < G->roadnum; i++)
	{
		scanf("(%c,%c,%d)", &v1, &v2, &G->roads[i].weight);
		G->roads[i].v1 = getIndex(G , v1);
		G->roads[i].v2 = getIndex(G , v2);
	}
	for (i = 0; i < G->vexnum; i++)
		root[i] = i;
} 

void order(Graph g)
{
	int i , j;
	int n = g->roadnum;
	for(i = 0 ; i < n ; i++)
	{
		for(j = i + 1 ; j < n ; j++)
		{
			if(g->roads[i].weight > g->roads[j].weight)
			{
				road t = g->roads[i];
				g->roads[i] = g->roads[j];
				g->roads[j] = t;
			}
		}
	}
}

int getRoot(int x)
{
	while(root[x] != x)
		x = root[x];
	return x;
}

void kruskal(Graph g)
{
	int i , t;
	for(i = 0 ; i < g->roadnum ; i++)
	{
		t = 0;
		if(getRoot(g->roads[i].v1) != getRoot(g->roads[i].v2))
		{
			root[getRoot(g->roads[i].v2)] = getRoot(g->roads[i].v1);
			t = 1;
		}
		printf("(%c,%c,%d,%d)" , g->vex[g->roads[i].v1] , g->vex[g->roads[i].v2] , g->roads[i].weight , t);	 
	}
}

int main()
{
	Graph g = (Graph) malloc (sizeof(graph));
	initGraph(g);
	order(g);
	kruskal(g);
}
