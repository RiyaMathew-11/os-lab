#include <stdio.h>
#include <stdlib.h>

int waiting_time[10] = {0}, turn_aroundtime[10] = {0} ;
int avg_wait_time, avg_turnaround_time, i, j, pos, temp;

void display(int n_processes, int* process_id, int* burst_time, int* waiting_time, int* turn_aroundtime, int avg_wait_time, int avg_turnaround_time){
    printf("\nProcess\t\t\tBurstTime\t\t\tWaiting Time\t\t\tTurnaround Time");
    int i;
    for (i = 0; i < n_processes; i++)
    {
        printf("\nP%d\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t\t%d", process_id[i],
               burst_time[i], waiting_time[i], turn_aroundtime[i]);
    }
    printf("\nAverage Waiting Time: %0.2f", (float)avg_wait_time / n_processes);
    printf("\nAverage Turnaround Time: %0.2f\n\n",
           (float)avg_turnaround_time / n_processes);
}

void fcfs(int n_processes, int* burst_time, int* process_id){

    // Calculating waiting time
    avg_wait_time = avg_turnaround_time = 0;
    waiting_time[0] = 0;

    for (i = 1; i < n_processes; i++)
    {
        waiting_time[i] = 0;
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }

    // Calculating Turnaround time

    for (i = 0; i < n_processes; i++)
    {
        turn_aroundtime[i] = burst_time[i] + waiting_time[i];

        // Calculating average waiting and turnaround time

        avg_wait_time += waiting_time[i];
        avg_turnaround_time += turn_aroundtime[i];
    }

    display(n_processes, process_id, burst_time, waiting_time, turn_aroundtime, avg_wait_time, avg_turnaround_time);
}

void sjf(int n_processes, int* burst_time, int* process_id){

  int sjf_processid[n_processes];
  for(i=0; i<n_processes; i++)
    sjf_processid[i] = process_id[i];
  int pos, temp;
  avg_wait_time = avg_turnaround_time = 0;
  // Sorting of burst times using selection Sorting
  for (i = 0; i < n_processes; i++)
    {
        pos = i;
        for (j = i + 1; j < n_processes; j++)
        {
            if (burst_time[j] < burst_time[pos])
                pos = j;
        }

        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;

        // Simultaneously updating process id according to burst time
        temp = sjf_processid[i];
        sjf_processid[i] = sjf_processid[pos];
        sjf_processid[pos] = temp;
    }

    // Calculate waiting time

    waiting_time[0] = 0;

    for (i = 1; i < n_processes; i++)
    {
        waiting_time[i] = 0;
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }

    // Calculating Turnaround time

    for (i = 0; i < n_processes; i++)
    {
        turn_aroundtime[i] = burst_time[i] + waiting_time[i];

        // Calculating average waiting and turnaround time

        avg_wait_time += waiting_time[i];
        
        avg_turnaround_time += turn_aroundtime[i];
    }

    display(n_processes, sjf_processid, burst_time, waiting_time, turn_aroundtime, avg_wait_time, avg_turnaround_time);
}

void priority_scheduling(int n_processes, int* process_id, int* burst_time, int* priority){

    int priority_processid[n_processes];
    for(i=0; i<n_processes; i++)
      priority_processid[i] = process_id[i];
    avg_wait_time = avg_turnaround_time = 0;
    for (i = 0; i < n_processes; i++)
    {
        pos = i;
        for (j = i + 1; j < n_processes; j++)
        {
            if (priority[j] < priority[pos])
                pos = j;
        }
        temp = priority[i];
        priority[i] = priority[pos];
        priority[pos] = temp;

        //  Updating Burst time

        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;

        // Simultaneously updating process id according to burst time
        temp = priority_processid[i];
        priority_processid[i] = priority_processid[pos];
        priority_processid[pos] = temp;
    }

    //  Calculating waiting time
    waiting_time[0] = 0;

    for (i = 1; i < n_processes; i++)
    {
        waiting_time[i] = 0;
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
    }

    // Calculating Turnaround time

    for (i = 0; i < n_processes; i++)
    {
        turn_aroundtime[i] = burst_time[i] + waiting_time[i];

        // Calculating average waiting and turnaround time

        avg_wait_time += waiting_time[i];
        avg_turnaround_time += turn_aroundtime[i];
    }

    // Printing the output
    display(n_processes, priority_processid, burst_time, waiting_time, turn_aroundtime, avg_wait_time, avg_turnaround_time);
}

void robin_robin(int n_processes, int* burst_time, int* arrival_time, int quantum){

    avg_wait_time = avg_turnaround_time = 0;
    int sum = 0, count = 0, y;
    y = n_processes;
    // initialise a tmp array with burst times
    int tmp[n_processes];
    for(i=0; i<n_processes;i++)
      tmp[i] = burst_time[i];
    
    printf("\nProcess\t\t\tBurstTime\t\t\tWaiting Time\t\t\tTurnaround Time");
    for (sum = 0, i = 0; y != 0;)
    {
        if (tmp[i] <= quantum && tmp[i] > 0) // define the conditions
        {
            sum = sum + tmp[i];
            tmp[i] = 0;
            count = 1;
        }
        else if (tmp[i] > 0)
        {
            tmp[i] = tmp[i] - quantum;
            sum = sum + quantum;
        }
        if (tmp[i] == 0 && count == 1)
        {
            y--; //decrement the process no.
            printf("\nP%d \t\t\t\t %d\t\t\t\t\t %d\t\t\t\t\t %d", i + 1, burst_time[i], sum - arrival_time[i], sum - arrival_time[i] - burst_time[i]);
            avg_wait_time = avg_wait_time + sum - arrival_time[i] - burst_time[i];
            avg_turnaround_time = avg_turnaround_time + sum - arrival_time[i];
            count = 0;
        }
        if (i == n_processes - 1)
        {
            i = 0;
        }
        else if (arrival_time[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    printf("\n Average Waiting Time: \t%0.2f",(float)avg_wait_time / n_processes );
    printf("\n Average Turnaround Time: \t%0.2f", (float)avg_turnaround_time / n_processes);
}

int main()
{
    int ch, n_processes, i;

    printf("\nEnter number of processes: ");
    scanf("%d", &n_processes);

    int burst_time[n_processes];

    printf("\nEnter Burst Times\n");
    for(i=0; i<n_processes;i++){
        printf("P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    int process_id[n_processes];
    for(i=0; i<n_processes; i++)
        process_id[i] = i+1;
    do
    {
        printf("\n");
        printf("1: FCFS\n");
        printf("2: SJF\n");
        printf("3: Priority\n");
        printf("4: Round Robin\n");
        printf("5: Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            printf("\nFirst-cum-First-Serve Algorithm\n");
            fcfs(n_processes, burst_time, process_id);
            break;
        case 2:
        {
            printf("\nShortest Job First Algorithm\n");
            sjf(n_processes, burst_time, process_id);
            break;
        }
        case 3:{

            printf("\nPriority Scheduling Algorithm\n");
            int priority[n_processes];
            printf("Enter priority order: \n");
            for(i=0; i<n_processes; i++){
                printf("P%d ",i+1);
                scanf("%d",&priority[i]);
            }
            priority_scheduling(n_processes, process_id, burst_time, priority);
            break;
        }
        case 4:
        {
            printf("\nRound Robin Algorithm\n");
            int arrival_time[n_processes];
            for(i=0; i<n_processes; i++)
              arrival_time[i] = 0;
            int quantum;
            printf("Enter Time Quantum: ");
            scanf("%d", &quantum);
            robin_robin(n_processes, burst_time, arrival_time, quantum);
            break;

        }
        case 5:
            printf("\n Exiting");
            exit(1);
            break;
        default:
            printf("INVALID CHOICE");
            break;
        }
    } while (ch != 5);

    return 0;
}
