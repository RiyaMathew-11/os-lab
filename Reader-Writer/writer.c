#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
	printf("WRITER\nEnter whitespace to exit\n\n");

	int shmid;
	key_t key = 1234;

	if ((shmid = shmget(key, 100, IPC_CREAT | 0666)) < 0) {
		printf("shared memory initialization failed\n");
		return 0;
	}

	int* mem = (int*) shmat(shmid, NULL, 0);
	*mem = 0;

	while (1) {
		char x[64];
		printf("message: ");
		fgets(x, 64, stdin);

		if (x[0] == ' ') {
			*mem = 2;
			printf("\nexiting..\n");
			exit(0);
		}

		int* mem = (int*) shmat(shmid, NULL, 0);
		memcpy(mem + 4, x, 50);

		*mem = 1;
		shmdt(mem);
	}

	return 0;
}
