#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
	printf("READER\n\n");

	int shmid;
	key_t key = 1234;
	
	if ((shmid = shmget(key, 100, 0666)) < 0) {
		printf("failed to gain access to shared memory\n");
		return 0;
	}

	while(1) {
		int* mem = (int*) shmat(shmid, NULL, 0);

		if (*mem == 0) { 
			usleep(300000);
			continue;
		}

		if (*mem == 2) {
			printf("\nwriter process has terminated, exiting..\n");
			shmctl(shmid, IPC_RMID, NULL);
			exit(0);
		}

		printf("message from writer: %s", (char*)(mem + 4));

		*mem = 0;
		shmdt(mem);
	}

	return 0;
}
