// ex2
#include <stdio.h>
#include <malloc.h>

int main() {
    int N;

    printf("Print the size of the array here: ");
    scanf("%d", &N);

    int *arr = malloc(N*sizeof(int));

    for ( int i = 0 ; i < N ; i++ )
        arr[i] = i;

    for ( int i = 0 ; i < N ; i++ )
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}