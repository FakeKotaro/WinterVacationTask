#include <stdio.h>

int nums[100];
int n , min = 0;

void dfs(int step , int sum)
{
	if(step == n - 1 || step == n - 2)
	{
		if(sum < min)
			min = sum;
		return;
	}
	
	dfs(step + 1 , sum + nums[step + 1]);
	dfs(step + 2 , sum + nums[step + 2]);
}

int main()
{
	int i;
	printf("请输入个数：");
	scanf("%d" , &n);
	printf("请输入每一阶花费体力数：");
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d" , &nums[i]);
		min += nums[i];
	}
	dfs(-1 , 0);
	printf("%d" , min);
}
