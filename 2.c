#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodePointer;
typedef struct node {
	int item;
	nodePointer edge;
} node;

void print(nodePointer adj[]);
void input(nodePointer adj[], nodePointer* tmp);
int main()
{
	int i = 0,j,start,store,num,edge_num;
	char type;
	FILE* fp;
	fp = fopen("input.txt", "r");
	nodePointer *adjList, tmp;
	fscanf(fp, "%c", &type);
	fscanf(fp, "%d %d", &num,&edge_num);
	adjList = calloc(num,sizeof(*adjList));
	if (type == 'u')
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d", &start);
			tmp = malloc(sizeof(*tmp));
			tmp->edge = NULL;
			fscanf(fp, "%d", &tmp->item);
			input(&adjList[start], &tmp);

			store = start;
			start = tmp->item;

			tmp = malloc(sizeof(*tmp));
			tmp->edge = NULL;
			tmp->item = store;
			input(&adjList[start], &tmp);


		}
	}
	if (type == 'd')
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d", &start);
			tmp = malloc(sizeof(*tmp));
			tmp->edge = NULL;
			fscanf(fp, "%d", &tmp->item);
			input(&adjList[start], tmp);
		}
	}
	for (j = 0; j < num; j++)
	{
		printf("adjList [%d]", j);
		print(&adjList[j]);

	}
	return 0;
}
void input(nodePointer adj[], nodePointer* tmp)
{
	if (!(*adj))
	{
		(*adj) = *tmp;
	}
	else
	{
		(*tmp)->edge = (*adj);
		(*adj) = *tmp;
	}
}
void print(nodePointer adj[])
{
	nodePointer cur = (*adj);
	while (1)
	{
		if (!cur)
			break;
		printf("%4d", cur->item);
		cur = cur->edge;
	}
	puts(" ");
}