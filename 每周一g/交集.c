#include <stdio.h>
#define SIZE 20

int HashMap[10] = {0};

int main()
{
	int n1 , n2 , i;
	int nums1[SIZE] , nums2[SIZE];
	printf("�������һ���������ָ�����\n");
	scanf("%d" , &n1) ;
	printf("�������һ�����飺\n");
	for(i = 0 ; i < n1 ; i++)
	{
		scanf("%d" , &nums1[i]);
		HashMap[nums1[i]] = 1; 
	}
	 
	printf("������ڶ����������ָ�����\n"); 
	scanf("%d" , &n2) ;
	printf("������ڶ������飺\n");
	for(i = 0 ; i < n2 ; i++)
	{
		scanf("%d" , &nums2[i]);
		if(HashMap[nums2[i]] == 1)
		{
			printf("%d  ", nums2[i]);
			HashMap[nums2[i]] ++;
		}
	}
} 
