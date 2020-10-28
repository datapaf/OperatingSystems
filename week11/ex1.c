#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int main()
{
	const char* text = "This is a nice day";
	int size = strlen(text) + 1;

	const char* filepath = "ex1.txt";

	FILE* fp = fopen(filepath, "w");
	ftruncate(fileno(fp), size - 1);
	fclose(fp);

	// opening the file in the O_RDWR mode 
	int fd = open(filepath, O_RDWR);

	// getting the size of the file
	struct stat fileInfo;
	fstat(fd, &fileInfo);

	// doing memory mapped io	
    char* map = mmap(NULL, fileInfo.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    for ( int i = 0 ; i < size ; i++ )
    	map[i] = text[i];

	munmap(map, fileInfo.st_size);
	close(fd);

	return 0;
}