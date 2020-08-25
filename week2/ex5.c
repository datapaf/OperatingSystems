#include <stdio.h>
#include <stdbool.h>

void print_triangle(int n, bool isRightAngle)
{
    if (isRightAngle)
    {
        int stars_number = 0;
    
        for (int i = 0 ; i < n ; i++) 
        {
            stars_number += 1;
            
            for ( int j = 0 ; j < stars_number ; j++ )
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else 
    {
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
    }
}

void print_arrow(int n)
{
    int stars_number = 0;
    
    for (int i = 1 ; i <= n ; i++) 
    {   
        if ( n%2 == 0 )
        {
            if ( i < n/2 + 1 )
            {
                stars_number++;
            } 
            else if ( i > n/2 + 1 )
            {
                stars_number--;
            }
        }
        else
        {
            if ( i < (n+1)/2 + 1 )
            {
                stars_number++;
            } 
            else if ( i >= (n+1)/2 + 1 )
            {
                stars_number--;
            }
        }


        for ( int j = 0 ; j < stars_number ; j++ )
        {
            printf("*");
        }
        printf("\n");
    }
}

void print_square(int n)
{
    int stars_number = n;
    
    for (int i = 1 ; i <= n ; i++) 
    {   
        for ( int j = 0 ; j < stars_number ; j++ )
        {
            printf("*");
        }
        printf("\n");
    }
}


int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("No enough parameters provided!\n");
        return -1;
    }

    int n = strtol(argv[1], NULL, 0);


    switch(strtol(argv[2], NULL, 0))
    {
        case 1:
            print_triangle(n,false);
            break;
        case 2:
            print_triangle(n,true);
            break;
        case 3:
            print_arrow(n);
            break;
        case 4:
            print_square(n);
            break;
        default:
            printf("No such shape!\n");
            break;
    }

    return 0;
}