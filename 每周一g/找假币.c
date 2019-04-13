#include <stdio.h>

int coins[1001] = {0};											//全局变量 

int getK(int n)
{
	if(n % 3 == 0)
		return n / 3;
	else
		return n / 3 + 1;
}
 
int getWeight(int left , int right)								//获得一堆中硬币重量和 
{
	int sum = 0;
	int i;
	for(i = left ; i <= right ; i++)
		sum += coins[i];
	return sum;
}

int findCoin(int right , int left)
{
	int n = right - left + 1;   		 //n为该堆硬币数量 
	int k1 = left + getK(n) - 1;		 //k1为第一堆最后一个下标 
	int k2 = left + 2 * getK(n) - 1;	 //k2为第二堆最后一个下标
	
	if(getWeight(left , k1) == getWeight(k1 + 1 , k2))		  //前两堆相等，在第三堆中找
	{
		if(right - k2 == 1)									  //如果最后一堆只有一个，则该硬币为假币 
			return right; 
		else
		{
			left = k2 + 1;									  //否则继续对最后一堆查找 
			return findCoin(left , right);
		}
	} 
	
	else if(getWeight(left , k1) < getWeight(k1 + 1 , k2))   //如果第一堆小于第二堆，查找第一堆 
	{
		if(k1 == left)
		{
            return left;
        } 
		else 
		{
        	right = k1;
            return findCoin(left , right);
        }
	} 
	
	else													//第二堆小于第一堆，查找第二堆 
	{
		if ((k2 - k1) == 1)
        	return k2;
         else 
		 {
            left = k1 + 1;
            right = k2;
            return findCoin(left , right);
        }
	}
}

int main()
{
	int n ,i ,index;
	printf("请输入硬币数量：");
	scanf("%d" ,&n);
	printf("请输入假币下标：");
	scanf("%d" ,&i);
	coins[i] = -1;
	index = findCoin(0 , n);
	printf("假币下标为%d" ,index);
}

