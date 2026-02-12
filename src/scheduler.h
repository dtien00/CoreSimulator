#include "process.h" /* Header file for our process structure */

#define MAX_PROCESSES 10 /* Maximum number of processes that can exist in the list/queue */

#ifndef SCHEDULER
#define SCHEDULER
typedef struct {
    Process list[MAX_PROCESSES];
    int id;
} Scheduler;

int addProcess(Scheduler sch, Process p){
    /* Looks to add some process p to the Schedule object list */
    /* @param p: The Process object to add to the list */
    /* @return: 
        - 0: Failed
        - 1: Successfully added to the Process list
        - 2: Current Schedule object is full (attempting to add an 11th process)
    */

    for(int i; i<MAX_PROCESSES; i++){
        if (sch.list[i].id == -1) {
            sch.list[i] = p;
            return 1;
        }

    }
}

int removeProcess(Scheduler sch, int id){
    /* Looks to remove a process from the Process list based on its ID */
    /* @param id: ID of the Process object to remove */
    /* @return:
        - 0: Failed
        - 1: Successfully removed
        - 2: Given id does not match any of the current Process' IDs
    */

    Process empty;
    empty.id = -1;

    for(int i = 0; i<MAX_PROCESSES; i++){
        if(sch.list[i].id == id){
            sch.list[i] = empty;
            return 1;
        }
    }
    return 2;
}

int runProcess(Scheduler sch, int id){
    /* For now, let us say each process contains a message we need to print as output. We also adjust the process state accordingly */
    /* @param sch: Scheduler object we reference */
    /* @param id: ID of the Process object to remove */
    /* @return:
        - 0: Failed
        - 1: Successfully ran
    */

    for (int i = 0; i< MAX_PROCESSES; i++){
        if(sch.list[i].id == id){
            printf("Outputting %s\n", sch.list[i].msg);
            return 1;
        }
    }
    return 0;
}

#endif
