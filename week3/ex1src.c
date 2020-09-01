#include <stdio.h>

int main() {

    int* pc;
    int c;
    
    c = 22;
    
    printf("Address of c:%d\n", &c);
    printf("Address of c:%d\n\n", c);
    
    pc = &c;
    
    printf("Address of pc:%d\n", pc);
    printf("Address of pc:%d\n\n", *pc);
    
    c = 11;
    
    printf("Address of pc:%d\n", pc);
    printf("Address of pc:%d\n\n", *pc);
    
    *pc = 2;
    
    printf("Address of c:%d\n", &c);
    printf("Address of c:%d\n\n", c);
    
    return 0;
}