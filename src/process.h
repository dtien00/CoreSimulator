/* The structure for a process we wish to run */

#define MAX_LEN 255 /* Maximum message length for a process message */

extern enum processState{
    READY = 1,
    RUNNING,
    SUSPENDED,
    TERMINATED
}; /* We do not need a COMPLETED state, as once the process is done we can simply DISCARD it */

#ifndef PROCESS
#define PROCESS

typedef struct{
    char msg[MAX_LEN]; /* A message that the process will print when it is run; this is just to simulate some work being done by the process */
    enum processState state; /* The current state of the process */
    int id; /* A positive integer value that can be used as an ID for the process */
} Process;

#endif // PROCESS

int initialize_msg(char str[], int ctr){
    /* This will initiailize our message with the provided string to print */
    /* as well as an integer value to designate the particular process */
 
    /* @param msg: A character buffer containing the message we wish to print */
    /* @param ctr: A positive integer value that is used an ID for a specific process */
    /* @return:
        - 0 if there is some error with storing the message for the process (too long, etc.)
        - 1 if the process is successfully initialized
        - 2 if the message is too long; will require truncation with "..."
    */

    char msg[MAX_LEN]; /* We need to use the global message buffer to store the message for the process */

    /* Invalid ID */
    if (ctr < 0)
        return 0; 

    /* Copy the message into the buffer */
    for (int i = 0; i < MAX_LEN ; i++){
        msg[i] = str[i];
        if (str[i] == '\0')
            return 2;
    }

    return 1;

}

void set_state(Process p, enum processState new_state){
    /* This will set the state of the process to the new state provided */
    /* @param new_state: The new state we wish to set the process to */

    p.state = new_state;
}