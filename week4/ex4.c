// task 4
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void enter_command(char *com, int size)
{
    fgets(com, size, stdin);
}

int main() {
    while (true) {
        char com[100];
        enter_command(com, 100);
        system(com);
    }
}