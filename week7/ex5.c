// ex5
#include <stdio.h>
#include <malloc.h>

int main()
{
    char **s = malloc(sizeof(char*));
    char foo[] = "Hello World\0";
    *s = foo;
    printf("s is %s\n",*s);
    (*s)[0] = foo[0];
    printf("s[0] is %c\n",(*s)[0]);
    return(0);
}