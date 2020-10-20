#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

unsigned int currentINode;
char* currentFilename;

int filter(const struct dirent* entry)
{
    return (entry->d_ino == currentINode
    	&& strcmp(entry->d_name, currentFilename)) ? 1 : 0;
}

int main()
{
	DIR *d;
  	struct dirent *dir;

  	d = opendir("./tmp/");
  	
  	if (d) {
    	while ((dir = readdir(d)) != NULL) {
    		struct dirent **namelist = NULL;
    		currentINode = dir->d_ino;
    		currentFilename = dir->d_name;

    		int n = scandir("./tmp/", &namelist, filter, NULL);
    		while (n--) {
            	printf("%s\n", namelist[n]->d_name);
        	}

    		free(namelist);
    	}
    	closedir(d);
  	}

	return 0;
}