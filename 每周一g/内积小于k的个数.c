#include <stdio.h>

void getNum(int * nums , int n , int k)
{
	int slow = 0 ,fast = 0;
	int mul = 1;
	int count = 0;
	for(fast = 0 ; fast < n ; fast++)
	{
        mul *= nums[fast];
        while (mul >= k)
		{
            mul /= nums[slow];
            slow ++;
        }
            count += fast - slow + 1;
    }
        printf("\n个数为：%d" , count);
}

int main()
{
	int n , i , k;
	printf("请输入数组元素个数：");
	scanf("%d" , &n);
	int nums[n];
	printf("请输入数组元素：");
	for(i = 0 ; i < n ; i++)
		scanf("%d" , &nums[i]);
	printf("请输入上限值：");
	scanf("%d" , &k);
	
	getNum(nums , n , k);
}
