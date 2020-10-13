#include <stdio.h>
#include <malloc.h>
#include <memory.h>

int isHitIndex(int pageNumber, int num_of_pages, int* pages_in_memory)
{
    for ( int i = 0 ; i < num_of_pages ; i++ )
    {
        if (pages_in_memory[i] == pageNumber)
            return i;
    }
    return -1;
}

void print_pages_in_memory(int num_of_frames, int* pages_in_memory)
{
    for ( int i = 0 ; i < num_of_frames ; i++ )
        printf("%d ", pages_in_memory[i]);
    printf("\n");
}

void print_counters(int num_of_frames, int* counters)
{
    for ( int i = 0 ; i < num_of_frames ; i++ )
        printf("%d ", counters[i]);
    printf("\n");
}

void update_counters(int* R, int num_of_frames, int* counters)
{
    for ( int i = 0 ; i < num_of_frames ; i++ )
        counters[i] = (counters[i] >> 1) | (R[i] << sizeof(int)*8 - 2);
}

int find_index_of_page_to_evict(int num_of_frames, int* counters, int* pages_in_memory)
{
    int index_of_page_to_evict = 0;
    int minCounter = counters[0];
    for ( int j = 0 ; j < num_of_frames ; j++ )
    {
        if (pages_in_memory[j] == -1)
            return j;

        if (counters[j] < minCounter)
        {
            minCounter = counters[j];
            index_of_page_to_evict = j;
        }
    }
    return index_of_page_to_evict;
}

int main() {

    FILE *dataFile;
    dataFile = fopen("Lab 09 input.txt","r");

    int num_of_frames;
    printf("Enter the number of frames in memory: ");
    scanf("%d", &num_of_frames);

    int* R = malloc(num_of_frames*sizeof(int));
    memset(R, 0, num_of_frames*sizeof(int));

    int* pages_in_memory = malloc(num_of_frames*sizeof(int));
    memset(pages_in_memory, -1, num_of_frames*sizeof(int));

    int* counters = malloc(num_of_frames*sizeof(int));
    memset(counters, 0, num_of_frames*sizeof(int));

    int currentPageNumber;
    int num_of_hits = 0;
    int num_of_misses = 0;
    for ( int i = 0 ; i < 1000 ; i++ )
    {
        //print_pages_in_memory(num_of_frames, pages_in_memory);
        //print_counters(num_of_frames, counters);

        fscanf(dataFile, "%d ", &currentPageNumber);
        //printf("%d\n", currentPageNumber);

        int index = isHitIndex(currentPageNumber,num_of_frames,pages_in_memory);

        if (index != -1)
        {
            //printf("Hit\n");
            num_of_hits++;

            R[index] = 1;
            //printf("Reference bit of %d is set to 1\n", currentPageNumber);

            update_counters(R,num_of_frames,counters);
            //printf("Counters are updated\n");

        } else {
            //printf("Miss\n");
            num_of_misses++;

            // finding a page with the minimal counter that is going to be evicted
            int index_of_page_to_evict = find_index_of_page_to_evict(num_of_frames,counters,pages_in_memory);
            //printf("Index of the page to evict is %d\n", index_of_page_to_evict);

            // evict the found page and insert the necessary page instead
            pages_in_memory[index_of_page_to_evict] = currentPageNumber;
            //printf("The page is evicted\n");
            // set the reference bit of the inserted page to 0
            R[index_of_page_to_evict] = 0;
            //printf("Reference bit of %d is set to 1\n", currentPageNumber);

            update_counters(R, num_of_frames, counters);
            //printf("Counters are updated\n");
        }
    }

    printf("Hits: %d\n", num_of_hits);
    printf("Misses: %d\n", num_of_misses);
    printf("Hit/Miss: %f\n", (float)(num_of_hits)/(float)num_of_misses);

    return 0;
}
