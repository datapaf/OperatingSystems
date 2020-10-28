#include <stdio.h>
#include <unistd.h>

int main()
{
	// replacing stdin buffer with my_buffer of size 5 
	char my_bufer[5];
	setvbuf(stdin, my_buffer, _IOLBF, 5);
	

	char* hello = "Hello";
	
	for ( int i = 0 ; i < 5 ; i++ )
	{
		// filling my_buffer with characters
		printf("%c", hello[i]);
		sleep(1);
	}

	// 'Hello' prints out when the buffer becomes full

	return 0;
}