// Code to demonstrate FCFS algorithm 
// Implemented using FIFO queue 
// User Input - Number of processes and process burst time
// Calculate Waiting and Turnaround time


#include<stdio.h>
 
int main(){
// Constraint - Maximum of 10 processes can be allocated in queue
// Getting the datastructures and variables

int n_processes, fc_burst_time[10], fc_waiting_time[10], fc_turn_aroundtime[10], i, j;

int avg_wait_time = 0, avg_turnaround_time = 0;

// Collecting user input for number of processes and burst times

printf("Enter number of processes: ");
scanf("%d", &n_processes);
printf("Enter Burst times: ");

for(i=0; i<n_processes; i++){
  printf("P%d: ", i+1);
  scanf("%d", &fc_burst_time[i] );
}


// Calculating waiting time 

fc_waiting_time[0] = 0;

for(i=1; i<n_processes; i++){
  fc_waiting_time[i] = 0;

  for(j=0; j<i; j++){
    fc_waiting_time[i] += fc_burst_time[j];
  }
}

// Calculating Turnaround time

for(i=0; i<n_processes; i++){
  fc_turn_aroundtime[i] = fc_burst_time[i] + fc_waiting_time[i];

  // Calculating average waiting and turnaround time
  
  avg_wait_time += fc_waiting_time[i];
  avg_turnaround_time += fc_turn_aroundtime[i];
}

// Printing 

printf("\nProcess\t\t\tBurstTime\t\t\tWaiting Time\t\t\tTurnaround Time");

for(i=0; i<n_processes; i++){
  printf("\nP%d\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t\t%d", i+1, fc_burst_time[i], fc_waiting_time[i], fc_turn_aroundtime[i]);

}

printf("\n\n");

printf("Average Waiting Time: %d", avg_wait_time/n_processes);
printf("\nAverage Turnaround Time: %d\n", avg_turnaround_time/n_processes);

}
