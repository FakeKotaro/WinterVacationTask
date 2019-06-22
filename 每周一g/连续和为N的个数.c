#include <stdio.h>

int main()
{
	int num , ans = 1;
	double n;
	scanf("%d" , &num);
	for(n = 2 ; num / n - n / 2 + 0.5 > 0 ; n++ )
		if(num / n - n / 2 + 0.5 == (int)(num / n - n / 2 + 0.5))
			ans++;
	printf("%d" , ans);
} 
