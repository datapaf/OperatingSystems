// task 1
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// a thread performs actions listed in this procedure
void *ThreadFunction(int i)
{
    printf("The created thread %d performs actions here... \n", i);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int N;
    printf("Enter the number of threads to create: ");
    scanf("%d", &N);

    // identifiers of the created threads are going to be stored here
    pthread_t tid = NULL;

    for (int i = 0; i < N; i++) {

        // if there is some created thread then wait before creating the next one
        if (tid != NULL)
            pthread_join(tid,NULL);

        pthread_create(&tid, NULL, ThreadFunction, i);
        printf("Thread %d created!\n", i);
    }

    // wait the last thread to exit before ending the whole process
    pthread_join(tid,NULL);

    return 0;
}