#include <stdio.h>

#define ARRAY_SIZE 20

void bubble_sort(int *array, int n)
{
    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int j = 0 ; j < n - i - 1 ; j++ )
        {
            if ( array[j] > array[j+1] )
            {
                int t = array[j];
                array[j] = array[j+1];
                array[j+1] = t;
            }
        }
    }
}

int main() {
    
    int array[ARRAY_SIZE];
    for ( int i = 0 ; i < ARRAY_SIZE ; i++ ) {
        array[i] = ARRAY_SIZE - i;
        printf("%d ", array[i]);
    }
    printf("\n");

    bubble_sort(array,ARRAY_SIZE);

    for ( int i = 0 ; i < ARRAY_SIZE ; i++ ) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}