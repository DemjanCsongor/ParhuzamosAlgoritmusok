#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

void wait_four(void * args);
void wait_eight(void * args);
void printout(char* s);
pthread_mutex_t value_mutex = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    pthread_t t;
    pthread_create(&t,NULL,wait_four,NULL);
    printout("[main] 8 sec waiting\n");
    Sleep(8000);
    printout("[main] KESZ!\n");
    pthread_join(t,NULL);

    pthread_create(&t,NULL,wait_eight,NULL);
    printout("[main] 4 sec waiting\n");
    Sleep(4000);
    printout("[main] DONE!\n");
    pthread_join(t,NULL);
    return 0;
}

void  wait_four(void * args)
{
    printout("[thread] 4 sec waiting\n");
    Sleep(4000);
    printf("[thread] DONE!\n");
}

void wait_eight(void * args)
{
    printout("[thread] 8 sec waiting\n");
    Sleep(8000);
    printf("[thread] DONE!\n");
}

void printout(char* s)
{
    pthread_mutex_lock(&value_mutex); 
    printf("%s", s);
    pthread_mutex_unlock(&value_mutex);
}
