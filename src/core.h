#include "scheduler.h"

#ifndef CORE
#define CORE
typedef struct {
    Scheduler sch; // Scheduler associated with the core
    int id; // Core ID
} Core;

#endif CORE

void runScheduler(int protocol){
    /* Based on the protocol parameter value, runs a specific scheduler behavior */
    /* @param protocol: Determines Scheduler object behavior to be performed 
        - 1: addProcess
        - 2: removeProcess
        - 3: runProcess
    */

    
}