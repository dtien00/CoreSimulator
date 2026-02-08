#include <stdio.h>
#include "core.h"
#include "process.h"
#include "scheduler.h"

int main(){
    printf("Kernelground Simulation Starting...\n");

    // Further implementation will go here to create cores, schedulers, and processes.

    return 0;
}

Core* createCore(int id){
    /* Creates and returns pointer to a newly initialized Core object */
    Core init;
    init.id = id;

    return &init;
}