#include <stdio.h>
int main()
{
	char ch;
	while(1)
	{
		printf("*");
		
		if(ch==27)
		{
			scanf("%d", &ch);
			break;
					
		}
	
	}
	return 0;
}
