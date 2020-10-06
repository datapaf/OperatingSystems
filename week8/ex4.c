// ex4
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {

    int *arr;

    // prepare special struct to store info about the resource usage
    struct rusage* usg = malloc(sizeof(struct rusage));

    for (int i = 1 ; i <= 10 ; i++)
    {
        arr = calloc(i * 10485760/4, 4);
        memset(arr, 0, i * 10485760/4);

        // obtain the info about resource usage of this process
        getrusage(RUSAGE_SELF, usg);
        // output the maximal resident set size of this process
        printf("maximal rrs: %ld\n", usg->ru_maxrss);

        sleep(1);
    }

    free(arr);

    return 0;
}
