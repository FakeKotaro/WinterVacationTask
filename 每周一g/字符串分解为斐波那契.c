#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int nums[30];
int length;
int cnt = 0;

int getSize(int n)
{
	int count = 0;
    while(n)
	{
        n = n / 10;
        count++;
    }
    return count;
}

bool solution(char * s , int begin)
{
	int i , j ;
	for(i = begin ; i < length - 2 ; i++)
	{ 
		char s1[30];
		for(j = i + 1 ; j < length ; j++)
		{
			char s2[30] = {"\0"}, s3[30] = {"\0"};
			strncpy(s1 , s + begin , i + 1 - begin);
			strncpy(s2 , s + i + 1 , j - i);
			if((s1[0] == '0' || s2[0] == '0') && strcmp(s1 , "0") != 0 && strcmp(s2 , "0") != 0) 
				break;
			int n1 = atoi(s1);
			int n2 = atoi(s2);
			int sum = n1 + n2;
			int p = getSize(sum);
			strncpy(s3 , s + j + 1 , p);
			int n3 = atoi(s3);
		
			if(n3 == sum)
			{
				nums[cnt] = n1;
				nums[cnt + 1] = n2;
				nums[cnt + 2] = n3;
				cnt++;
				if(j + p + 1 == length)
					return true;
				
				if(solution(s , i + 1))
					return true;
				else
					cnt--;	
				break;
			}			
		}
	}
	return false;
}

int main()
{
	int i;
	char s[30];
	gets(s);
	length = strlen(s);
	if(solution(s , 0 ))
	{
		for(i = 0 ; i < cnt + 2 ; i++)
			printf("%d " , nums[i]);
	}
	else
		printf("[]");
}
 
