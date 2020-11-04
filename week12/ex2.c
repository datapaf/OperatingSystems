#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
    
    char buffer[BUF_SIZE];

    int outfd;
    if (argc == 3 && strcmp(argv[1], "-a") == 0)
    	outfd = open(argv[2], O_WRONLY | O_APPEND);
    else
    	outfd = open(argv[1], O_WRONLY);

    ssize_t nread = 0;
    while((nread = read(STDIN_FILENO, buffer, BUF_SIZE)) != 0) 
    {
        write(STDOUT_FILENO, buffer, nread);
        write(outfd, buffer, nread);
    };

    return 0;
}
