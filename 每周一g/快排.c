#include <stdio.h>
#define SIZE 51
int a[SIZE];

void quickSort(int left , int right)
{
	int i,j,temp,flag;
	if(left > right)
		return;
	
	flag = a[left];
	i = left;
	j = right;
	
	while(i != j)
	{
		while(a[j] >= flag && i < j)
			j--;
		while(a[i] <= flag && i < j)
			i++;
		if(i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	
	a[left] = a[i];
	a[i] = flag;
	
	quickSort(left , i - 1);
	quickSort(i + 1 , right);
}

int main()
{
	int i,n;
	scanf("%d" ,&n);
	for(i = 1 ; i <= n ; i++)
	{
		scanf("%d" ,&a[i]);
		printf("%d\t" ,a[i]);
	}
	
	printf("\n");
	quickSort(1,n);
	for(i = 1 ; i <= n ; i++)
	{
		printf("%d\t" ,a[i]);
	}
}
