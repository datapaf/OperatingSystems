// task 2
// EXPLANATION:
// either in case of 3 iterations 8 processes or
// in case of 5 iterations 32 processes are created and
// they all end in 5 seconds after the forking
#include <unistd.h>

int main() {

    for ( int i = 0 ; i < 5 ; i++ )
    {
        fork();
    }

    sleep(5);

    return 0;
// task 2
// EXPLANATION:
// either in case of 3 iterations 8 processes or
// in case of 5 iterations 32 processes are created 
// (as at each forking the number of processes doubles) and
// they all end in 5 seconds after the forking.    
#include <unistd.h>

int main() {

    for ( int i = 0 ; i < 5 ; i++ )
    {
        fork();
    }

    sleep(5);

    return 0;
}