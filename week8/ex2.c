// ex2
// running ./ex2 & vmstat 1 10 
// we can see that the number of free memory
// is decreasing all the way al we demand more 
// memory. Both si and so are 0 since the process
// is not swapped to the disk, all the time we work
// in the main memory. 
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <unistd.h>

int main() {

    int *arr;

    for (int i = 1 ; i <= 10 ; i++)
    {
        arr = calloc(i * 10485760/4, 4);
        memset(arr, 0, i * 10485760/4);
        sleep(1);
    }

    free(arr);

    return 0;
}