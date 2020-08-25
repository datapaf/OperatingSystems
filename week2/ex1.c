#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int i_var = INT_MAX;
    float f_var = FLT_MAX;
    double d_var = DBL_MAX;
    
    printf("Integer variable value: %u \n", i_var);
    printf("Floating variable value: %f \n", f_var);
    printf("Double precision floating variable value: %f \n", d_var);
    
    printf("Integer variable size: %u \n", i_var);
    printf("Floating variable size: %f \n", f_var);
    printf("Double precision floating variable size: %f \n", d_var);
    
    return 0;
}
