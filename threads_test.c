#include "threads.h"

#include <stdio.h>



void one();

void two();

void three();

int global = 0;


int main()

{

	RunQ = NewItem();

	InitQueue(&RunQ);

	start_thread(one);

	start_thread(two);

  start_thread(three);
	run();

	return 0;

}



void one()

{

	int i = 0;

	while(global >= 0)

	{
      global++;
			i++;
		  printf("This is %d th execution of thread 1 with global var value % d", i, global);

	   	yield();

	}

}



void two()

{
	int i = 0;

	while(global >= 0)

	{
			global= global+2;
			i++;
			printf("This is %d th execution of thread 2 with global var value % d", i, global);

			yield();

	}

}

void three()

{
	int i = 0;

	while(global >= 0)

	{
			global= global+3;
			i++;
			printf("This is %d th execution of thread 3 with global var value % d", i, global);

			yield();

	}

}
