I am looking to simulate a single core, then a two core processor that each have their own scheduler structure within it.
Each scheduler structure contains a processor list that can be run or suspending while running.
Each process can be written as a structure that can contain data about it looks to achieve, an enum for what state it is in.
Afterwards, look to try and implement a 'work-stealer' aspect: if a scheduler is empty, try to take the process from the other scheduler.

Look to implement multithreading for each core processor.

# The following functions are defined in each file:
 * main.c
 -- Populate, execute, and manage the processor cores' processes during runtime.
 
 * process.h
 -- Definition of the process structure. Currently, we will treat each process as a print message, as we can also observe the order in which they are handled. Process structure contains the character message, positive integer ID, and state value

 * scheduler.h
 -- Definition of the scheduler structure. This contains a list of processess and looks to manage them while looking to empty it through execution. Should contain methods of adding a process to its list, removing a process from its list, running a process from its list.
 -- As a potential stretch goal, look to see if I can implement a behavior setting for the scheduler to determine how to choose the next process to run; instead of FIFO, perhaps determine a resource metric for each to choose the quickest one (message character count).

 * core.h
 -- Definition of the core structure. Each instance is meant to simulate one core of a CPU, which each contains their own scheduler structure. Should include methods to run its scheduler, with multithreading to manage multiple cores with their own schedulers and processes.
 -- As a stretch goal, independent of scheduler's, look to implement a 'work steal' behavior, where if the scheduler of one core has an empty list of processes to run, look towards other cores and their scheduler's to determine if there are any READY or SUSPENDED processes left to take, add to their own scheduler structure, and run it.