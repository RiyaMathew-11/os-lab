// Non-Preemptive Shortest Job First

#include<stdio.h>
 int main()
{
  // Constraint - Maximum of 10 processes can be allocated in queue
  int n_processes,process_id[10], sjf_burst_time[10], sjf_waiting_time[10], sjf_turn_aroundtime[10], i, j,pos,temp;

float avg_wait_time = 0, avg_turnaround_time = 0;

// Collecting user input for number of processes and burst times

printf("Enter number of processes: ");
scanf("%d", &n_processes);
printf("Enter Burst times: ");

for(i=0; i<n_processes; i++){
  printf("P%d: ", i+1);
  scanf("%d", &sjf_burst_time[i] );
  process_id[i] = i+1;

}
  
   //sorting of burst times using selection sort
    for(i=0;i<n_processes;i++)
    {
        pos=i;
        for(j=i+1;j<n_processes;j++)
        {
            if(sjf_burst_time[j] < sjf_burst_time[pos])
                pos=j;
        }
  
        temp= sjf_burst_time[i];
         sjf_burst_time[i]= sjf_burst_time[pos];
         sjf_burst_time[pos]=temp;
  
        // Simultaneously updating process id according to burst time
        temp=process_id[i];
        process_id[i]=process_id[pos];
        process_id[pos]=temp;
    }
   
  //  Calculating waiting time
    sjf_waiting_time[0]=0;            
  
    for(i=1;i<n_processes;i++)
    {
        sjf_waiting_time[i]=0;
        // for(j=0;j<i;j++)
            sjf_waiting_time[i]=sjf_burst_time[i-1] + sjf_waiting_time[i-1];
  
    }

// Calculating Turnaround time

for(i=0; i<n_processes; i++){
  sjf_turn_aroundtime[i] = sjf_burst_time[i] + sjf_waiting_time[i];

  // Calculating average waiting and turnaround time
  
  avg_wait_time += sjf_waiting_time[i];
  avg_turnaround_time += sjf_turn_aroundtime[i];
}

// Printing 

printf("\nProcess\t\t\tBurstTime\t\t\tWaiting Time\t\t\tTurnaround Time");

for(i=0; i<n_processes; i++){
  printf("\nP%d\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t\t%d", process_id[i], sjf_burst_time[i], sjf_waiting_time[i], sjf_turn_aroundtime[i]);

}

printf("\n\n");

printf("Average Waiting Time: %0.2f", avg_wait_time/n_processes);
printf("\nAverage Turnaround Time: %0.2f\n", avg_turnaround_time/n_processes);

}
