#include "q.h"

#define SIZE 8192



TCB_t *RunQ;



void start_thread(void (*function)(void))

{

	void *stack = malloc(SIZE);

	TCB_t *tcb = NewItem();

	init_TCB(tcb, function, stack, SIZE);

	AddQueue(&RunQ, tcb);

}



void run()

{

	ucontext_t parent;

	getcontext(&parent);

	swapcontext(&parent, &(RunQ->context));

}



void yield() 

{

	TCB_t *pointed, *pointee;

	pointee = RunQ;

	RotateQ(&RunQ);

	pointed = RunQ;

	swapcontext(&(pointee->context), &(pointed->context));

}
