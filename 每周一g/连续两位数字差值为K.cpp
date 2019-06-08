#include<stdio.h>

void solution(int num, int N, int K) 
{
    if (N == 0) 
	{	
		printf("%d  ",num);
        return;
    }
    int last = num % 10;
    if (last + K <= 9)
    	solution(num * 10 + last + K, N - 1, K);
	if (last - K >= 0)
   	    solution(num * 10 + last - K, N - 1, K);
}

void looper(int N,int K)
{
    for (int i = 1; i <= 9; i++)
        solution( i, N - 1, K);      
}

int main(void)
{
	int N,K;
	printf("请输入长度和绝对值：\n");
	scanf("%d %d",&N,&K);
	looper(N,K);
} 

