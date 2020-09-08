// task 1
// OUTPUT:
//  Hello from parent [11129 - 0]
//  Hello from parent [11129 - 1]
//  Hello from parent [11129 - 2]
//  Hello from parent [11129 - 3]
//  Hello from parent [11129 - 4]
//  Hello from parent [11129 - 5]
//  Hello from parent [11129 - 6]
//  Hello from parent [11129 - 7]
//  Hello from parent [11129 - 8]
//  Hello from parent [11129 - 9]
//  Hello from child [0 - 0]
//  Hello from child [0 - 1]
//  Hello from child [0 - 2]
//  Hello from child [0 - 3]
//  Hello from child [0 - 4]
//  Hello from child [0 - 5]
//  Hello from child [0 - 6]
//  Hello from child [0 - 7]
//  Hello from child [0 - 8]
//  Hello from child [0 - 9]
//
// EXPLANATION:
//  Firstly there was only one process. It forks into
//  to the two same processes starting after the next
//  instruction after forking. The parent is being
//  given a non-zero pid and the child is being
//  given a zero pid if it was created. Then they
//  execute the cycle concurrently

#include <stdio.h>
#include <unistd.h>

int main() {

    int n = 10;
    int pid = fork();
    for ( int i = 0 ; i < n ; i++ )
    {
        if (pid > 0)
            printf("Hello from parent [%d - %d]\n", pid, i);
        if (pid == 0)
            printf("Hello from child [%d - %d]\n", pid, i);
    }

    return 0;
}
