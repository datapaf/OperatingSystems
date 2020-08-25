#include <stdio.h>

int main()
{
	char str[20];
	printf("enter string:\n");

	scanf("%s", str);
	
	int t = strlen(str);
	for (int i = t - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}
	
	printf("\n");	
		
	return 0;
}
