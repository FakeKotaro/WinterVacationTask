#include <stdio.h>

int book[10] = {0};
int nums[10];
int n;

void dfs(int step)
{
	int i;
	if(step == n + 1)
	{
		for(i = 1 ; i < n + 1 ;i++)
			printf("%d" , nums[i]);
		printf("\n");
		return;
	}
	
	for(i = 1 ; i < n + 1 ;i++)
	{
		if(book[i] == 0)
		{
			nums[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}
	return;
} 

int main()
{
	scanf("%d" , &n);
	dfs(1);
}
