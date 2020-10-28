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
	// reading from ex1.txt 

	const char* read_filepath = "ex1.txt";

	int read_fd = open(read_filepath, O_RDWR);	
	
	struct stat read_fileInfo;
	fstat(read_fd, &read_fileInfo);

	// retreive the content	of the file using mapped io
    char* text = mmap(NULL, read_fileInfo.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, read_fd, 0);


    // writing to ex1.memcpy.txt

	const char* filepath = "ex1.memcpy.txt";

	FILE* fp = fopen(filepath, "w");
	ftruncate(fileno(fp), read_fileInfo.st_size);
	fclose(fp);

	// opening the file in the O_RDWR mode 
	int fd = open(filepath, O_RDWR);

	// getting the size of the file
	struct stat fileInfo;
	fstat(fd, &fileInfo);

	// create mapped io to write to the file	
    char* map = mmap(NULL, fileInfo.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    memcpy(map, text, fileInfo.st_size);
    
	munmap(map, fileInfo.st_size);
	close(fd);

	return 0;
}