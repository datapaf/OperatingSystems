#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("No parameters provided!\n");
        return -1;
    }

    int n = strtol(argv[1], NULL, 0);


    int stars_number = -1;
    
    for (int i = 0 ; i < n ; i++)
    {
        int level = n - (i+1);
        stars_number += 2;
        
        for ( int j = 0 ; j < level ; j++ )
        {
            printf(" ");
        }
        
        for ( int j = 0 ; j < stars_number ; j++ )
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}