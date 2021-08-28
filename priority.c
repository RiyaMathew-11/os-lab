// Non-Preemptive Priority Scheduling

#include<stdio.h>
 int main()
{
  // Constraint - Maximum of 10 processes can be allocated in queue
  int n_processes,process_id[10], pri_burst_time[10],priority[10], pri_waiting_time[10], pri_turn_aroundtime[10], i, j,pos,temp;

float avg_wait_time = 0, avg_turnaround_time = 0;

// Collecting user input for number of processes and burst times

printf("Enter number of processes: ");
scanf("%d", &n_processes);
printf("Enter Burst times: ");

for(i=0; i<n_processes; i++){
  printf("P%d: ", i+1);
  scanf("%d", &pri_burst_time[i] );
  printf("P%d Priority: ", i+1);
  scanf("%d", &priority[i] );

  process_id[i] = i+1;

}
  
   //sorting of priority using selection sort
    for(i=0;i<n_processes;i++)
    {
        pos=i;
        for(j=i+1;j<n_processes;j++)
        {
            if(priority[j] < priority[pos])
                pos=j;
        }
         temp= priority[i];
         priority[i]= priority[pos];
         priority[pos]=temp;

        //  Updating Burst time
  
        temp= pri_burst_time[i];
         pri_burst_time[i]= pri_burst_time[pos];
         pri_burst_time[pos]=temp;
  
        // Simultaneously updating process id according to burst time
        temp=process_id[i];
        process_id[i]=process_id[pos];
        process_id[pos]=temp;
    }
   
  //  Calculating waiting time
    pri_waiting_time[0]=0;            
  
    for(i=1;i<n_processes;i++)
    {
        pri_waiting_time[i]=0;
        // for(j=0;j<i;j++)
            pri_waiting_time[i]=pri_burst_time[i-1] + pri_waiting_time[i-1];
  
    }

// Calculating Turnaround time

for(i=0; i<n_processes; i++){
  pri_turn_aroundtime[i] = pri_burst_time[i] + pri_waiting_time[i];

  // Calculating average waiting and turnaround time
  
  avg_wait_time += pri_waiting_time[i];
  avg_turnaround_time += pri_turn_aroundtime[i];
}

// Printing 

printf("\nProcess\t\tPriority\t\tBurstTime\t\tWaiting Time\t\tTurnaround Time");

for(i=0; i<n_processes; i++){
  printf("\nP%d\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t\t%d", process_id[i], priority[i],pri_burst_time[i], pri_waiting_time[i], pri_turn_aroundtime[i]);

}

printf("\n\n");

printf("Average Waiting Time: %0.2f", avg_wait_time/n_processes);
printf("\nAverage Turnaround Time: %0.2f\n", avg_turnaround_time/n_processes);

}
 
