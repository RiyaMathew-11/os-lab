#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


int enable_sync; // Check to enable or disable synchronisation

int semaphore = 1;
int slp__ms = 100;


// describe wait()
void wait(){
  while(semaphore == 0);
    semaphore--;
}

// describe signal
void signal(){
  semaphore++;
}

int buffer[7];

void producer_process(){
    int producer_stash[7] = {100, 200, 300, 400, 500, 600, 700};

    int i = 0;
    while(i < 7){
      if (enable_sync)
        wait();

// Adding elements from producer stash to buffer
      usleep(slp__ms);
      buffer[i] = producer_stash[i];
      i++;

      signal();
      usleep(slp__ms);
    }
}

void consumer_process() {
  int i = 0;

  while(i < 7){
    if (enable_sync)
      wait();

// Consumer side printing

    usleep(slp__ms);
    printf("%d ", buffer[i]);
    i++;

    signal();
    usleep(slp__ms);
  }
}

int main(){

  int choice;
  printf("Producer Consumer problem using semaphore.\n");
  printf("Enter Choice: 1. Enable Synchronisation 2. Disable Synchronisation\nEnter Choice: ");
  scanf("%d", &choice);
  
  // Create parent thread references

  pthread_t tp, tc;

  // Fixiing flag
  enable_sync = (choice==1) ? 1 : 0 ;

  pthread_create(&tp, NULL, (void*)producer_process, NULL);
	pthread_create(&tc, NULL, (void*)consumer_process, NULL);

	pthread_join(tp, NULL);
	pthread_join(tc, NULL);

  return 0;

}
