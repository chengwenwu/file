#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include "shm_com.h"
int main(){
	int shmid;
	srand((unsigned int)getpid());
	shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
	if (shmid == -1) {
	  fprintf(stderr, "shmget failed\n");
	  exit(EXIT_FAILURE);
	}
	void *shared_memory = (void *)0;
    shared_memory = shmat(shmid, (void *)0, 0);
	if (shared_memory == (void *)-1) {
	  fprintf(stderr, "shmat failed\n");
	  exit(EXIT_FAILURE);
	}
	printf("Memory attached at %X\n", (long)shared_memory);
	struct shared_use_st *shared_stuff;
	shared_stuff = (struct shared_use_st *)shared_memory;
	shared_stuff->written = 0;
	int running = 1;
	while(running){
	  if (shared_stuff->written){
	    printf("You wrote: %s", shared_stuff->text);
	    sleep( rand() % 4 );
	    shared_stuff->written = 0;
	    if (strncmp(shared_stuff->text, "end", 3) == 0) {
		running = 0;
	    }
	   }
	}
	if (shmdt(shared_memory) == -1){
	    fprintf(stderr, "shmdt failed\n");
	    exit(EXIT_FAILURE);
	}
	if (shmctl(shmid, IPC_RMID, 0) == -1){
	    fprintf(stderr, "shmctl(IPC_RMID) failed\n");
	    exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
