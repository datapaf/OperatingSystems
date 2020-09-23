// ex1
#include <stdio.h>
#include <malloc.h>

typedef struct proc {
    int number;
    int t_arrival;
    int t_burst;
} process;

int main() {

    int N; // number of processes
    double TAT_avg = 0, WT_avg = 0;

    scanf("%d", &N);

    process *processes = malloc(N * sizeof(*processes));
    int *CT = malloc(N * sizeof(int));
    int *TA = malloc(N * sizeof(int));
    int *TAT = malloc(N * sizeof(int));
    int *WT = malloc(N * sizeof(int));


    for ( int i = 0 ; i < N ; i++ )
    {
        scanf("%d %d",
              &(processes[i].t_arrival),
              &(processes[i].t_burst));

        processes[i].number = i+1;
    }

    // sorting by AT
    for ( int i = 0 ; i < N ; i++ )
    {
        for ( int j = 0 ; j < N - i - 1 ; j++ )
        {
            if ( processes[j].t_arrival > processes[j+1].t_arrival )
            {
                process temp = processes[j];

                processes[j].number = processes[j+1].number;
                processes[j].t_arrival = processes[j+1].t_arrival;
                processes[j].t_burst = processes[j+1].t_burst;

                processes[j+1].number = temp.number;
                processes[j+1].t_arrival = temp.t_arrival;
                processes[j+1].t_burst = temp.t_burst;
            }
        }
    }



    printf("#\t AT\t BT\t CT\t TAT WT\n");

    for ( int i = 0 ; i < N ; i++ )
    {
        // calculate CT
        if (i != 0)
            CT[i] = CT[i-1] + processes[i].t_burst;
        else
            CT[0] = processes[0].t_burst;

        // calculate TAT
        TAT[i] = CT[i] - processes[i].t_arrival;

        // calculate WT
        WT[i] = TAT[i] - processes[i].t_burst;

        // add TAT[i] to calculation of TAT average
        TAT_avg += TAT[i];

        // add WT[i] to calculation of WT average
        WT_avg += WT[i];

        printf("%d\t %d\t %d\t %d\t %d\t %d\n",
               processes[i].number,
               processes[i].t_arrival,
               processes[i].t_burst,
               CT[i], TAT[i], WT[i]);
    }

    printf("TAT_avg = %f\n", TAT_avg / N);
    printf("WT_avg = %f\n", WT_avg / N);

    return 0;
}