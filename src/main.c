#include <stdio.h>
#include "core.h"
#include "process.h"
#include "scheduler.h"
#include <pthread.h>

void* foo(void* arg) {
    printf("Created a new thread\n");
    return NULL;
 }


void* foo1(void* arg) {
    char *str = (char*)arg;
    printf("Created a new thread %s\n", str);
    return NULL;
}

int main(){
    // Further implementation will go here to create cores, schedulers, and processes.
    printf("Kernelground Simulation Starting...\n");

    Core c1;
    c1.id = 1;

    Scheduler s1;
    c1.sch = s1;

    printf("Core %d processes:\n %d\n", c1.id, c1.sch.list->id);

    // Create a pthread_t variable to store
    // thread ID
    pthread_t thread1;
    pthread_t thread2;
    
    // Creating a new thread. 
    pthread_create(&thread1, NULL, foo, NULL);
    pthread_create(&thread2, NULL, foo1, "yatta");

    printf("Intermediate?\n");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

