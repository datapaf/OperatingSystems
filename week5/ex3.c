// task 3
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 4

int counter = 0;
int buffer[N];

bool isProducerSleeping = false;
bool isConsumerSleeping = false;

void Sleep(bool isProducer);
void Wakeup(bool isProducer);

void buffer_add(int item);
int buffer_get();
void buffer_show();

int produce();
void consume(int item);

void *producer();
void *consumer();

/*
 * Deadlock may happen here when counter == 0.
 * Consumer is about to sleep and at that time
 * it is interrupted by the producer which produces 
 * an item fast and tries to wake up the consumer
 * but at this time the consumer was not sleeping yet.
 * Although the producer set up isConsumerSleeping 
 * flag as false, the sleep procedure in consumer
 * has not reached the instruction with setting up 
 * isConsumerSleeping flag so later it reaches this
 * instruction and consumer sleeps. Producer continues
 * to produce until the buffer is full. After that it 
 * also sleeps. The process freezes infinitely.
 */
int main(int argc, char *argv[])
{
    srand(time(0));

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);

    pthread_join(tid2, NULL);
    return 0;
}

void Sleep(bool isProducer)
{
    if (isProducer)
    {
        isProducerSleeping = true;
        while (isProducerSleeping)
        {
            // producer sleeps...
        }
    }
    else
    {
        isConsumerSleeping = true;
        while (isConsumerSleeping)
        {
            // consumer sleeps...
        }
    }
}

void Wakeup(bool isProducer)
{
    if (isProducer)
        isProducerSleeping = false;
    else
        isConsumerSleeping = false;
}

int produce()
{
    return rand() % 10;
}

void consume(int item)
{
    sleep(60);
    //buffer_show();
    printf("%d\n", item);
}

void buffer_add(int item)
{
    buffer[counter] = item;
    counter++;
}

int buffer_get()
{
    int tmp = buffer[counter - 1];
    buffer[counter - 1] = -1;
    counter--;
    return tmp;
}

void buffer_show()
{
    for ( int i = 0 ; i < N ; i++ )
        printf("%d ", buffer[i]);
}

void *producer()
{
    while(1)
    {
        int item = produce();

        if (counter == N)
            Sleep(true);

        buffer_add(item);

        if (counter == 1)
            Wakeup(false);
    }
}

void *consumer()
{
    while(1)
    {
        if (counter == 0)
            Sleep(false);

        int item = buffer_get();

        if (counter == N - 1)
            Wakeup(true);

        consume(item);
    }
}