#include<stdio.h>

void
priority ()
{
  // Constraint - Maximum of 10 processes can be allocated in queue
  int n_processes, process_id[10], pri_burst_time[10], priority[10],
    pri_waiting_time[10], pri_turn_aroundtime[10], i, j, pos, temp;

  float avg_wait_time = 0, avg_turnaround_time = 0;

// Collecting user input for number of processes and burst times

  printf ("Enter number of processes: ");
  scanf ("%d", &n_processes);
  printf ("Enter Burst times: ");

  for (i = 0; i < n_processes; i++)
    {
      printf ("P%d: ", i + 1);
      scanf ("%d", &pri_burst_time[i]);
      printf ("P%d Priority: ", i + 1);
      scanf ("%d", &priority[i]);

      process_id[i] = i + 1;

    }

  //sorting of priority using selection sort
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

      temp = pri_burst_time[i];
      pri_burst_time[i] = pri_burst_time[pos];
      pri_burst_time[pos] = temp;

      // Simultaneously updating process id according to burst time
      temp = process_id[i];
      process_id[i] = process_id[pos];
      process_id[pos] = temp;
    }

  //  Calculating waiting time
  pri_waiting_time[0] = 0;

  for (i = 1; i < n_processes; i++)
    {
      pri_waiting_time[i] = 0;
      // for(j=0;j<i;j++)
      pri_waiting_time[i] = pri_burst_time[i - 1] + pri_waiting_time[i - 1];

    }

// Calculating Turnaround time

  for (i = 0; i < n_processes; i++)
    {
      pri_turn_aroundtime[i] = pri_burst_time[i] + pri_waiting_time[i];

      // Calculating average waiting and turnaround time

      avg_wait_time += pri_waiting_time[i];
      avg_turnaround_time += pri_turn_aroundtime[i];
    }

// Printing 

  printf
    ("\nProcess\t\tPriority\t\tBurstTime\t\tWaiting Time\t\tTurnaround Time");

  for (i = 0; i < n_processes; i++)
    {
      printf ("\nP%d\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t\t%d",
	      process_id[i], priority[i], pri_burst_time[i],
	      pri_waiting_time[i], pri_turn_aroundtime[i]);

    }

  printf ("\n\n");

  printf ("Average Waiting Time: %0.2f", avg_wait_time / n_processes);
  printf ("\nAverage Turnaround Time: %0.2f\n",
	  avg_turnaround_time / n_processes);

}


void
sjf ()
{
  // Constraint - Maximum of 10 processes can be allocated in queue
  int n_processes, process_id[10], sjf_burst_time[10], sjf_waiting_time[10],
    sjf_turn_aroundtime[10], i, j, pos, temp;

  float avg_wait_time = 0, avg_turnaround_time = 0;

// Collecting user input for number of processes and burst times

  printf ("Enter number of processes: ");
  scanf ("%d", &n_processes);
  printf ("Enter Burst times: ");

  for (i = 0; i < n_processes; i++)
    {
      printf ("P%d: ", i + 1);
      scanf ("%d", &sjf_burst_time[i]);
      process_id[i] = i + 1;

    }

  //sorting of burst times using selection sort
  for (i = 0; i < n_processes; i++)
    {
      pos = i;
      for (j = i + 1; j < n_processes; j++)
	{
	  if (sjf_burst_time[j] < sjf_burst_time[pos])
	    pos = j;
	}

      temp = sjf_burst_time[i];
      sjf_burst_time[i] = sjf_burst_time[pos];
      sjf_burst_time[pos] = temp;

      // Simultaneously updating process id according to burst time
      temp = process_id[i];
      process_id[i] = process_id[pos];
      process_id[pos] = temp;
    }

  //  Calculating waiting time
  sjf_waiting_time[0] = 0;

  for (i = 1; i < n_processes; i++)
    {
      sjf_waiting_time[i] = 0;
      // for(j=0;j<i;j++)
      sjf_waiting_time[i] = sjf_burst_time[i - 1] + sjf_waiting_time[i - 1];

    }

// Calculating Turnaround time

  for (i = 0; i < n_processes; i++)
    {
      sjf_turn_aroundtime[i] = sjf_burst_time[i] + sjf_waiting_time[i];

      // Calculating average waiting and turnaround time

      avg_wait_time += sjf_waiting_time[i];
      avg_turnaround_time += sjf_turn_aroundtime[i];
    }

// Printing 

  printf ("\nProcess\t\t\tBurstTime\t\t\tWaiting Time\t\t\tTurnaround Time");

  for (i = 0; i < n_processes; i++)
    {
      printf ("\nP%d\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t\t%d", process_id[i],
	      sjf_burst_time[i], sjf_waiting_time[i], sjf_turn_aroundtime[i]);

    }

  printf ("\n\n");

  printf ("Average Waiting Time: %0.2f", avg_wait_time / n_processes);
  printf ("\nAverage Turnaround Time: %0.2f\n",
	  avg_turnaround_time / n_processes);

}

void
fcfs ()
{
  // Constraint - Maximum of 10 processes can be allocated in queue
// Getting the datastructures and variables

  int n_processes, fc_burst_time[10], fc_waiting_time[10],
    fc_turn_aroundtime[10], i, j;

  int avg_wait_time = 0, avg_turnaround_time = 0;

// Collecting user input for number of processes and burst times

  printf ("Enter number of processes: ");
  scanf ("%d", &n_processes);
  printf ("Enter Burst times: ");

  for (i = 0; i < n_processes; i++)
    {
      printf ("P%d: ", i + 1);
      scanf ("%d", &fc_burst_time[i]);
    }


// Calculating waiting time 

  fc_waiting_time[0] = 0;

  for (i = 1; i < n_processes; i++)
    {
      fc_waiting_time[i] = 0;

      for (j = 0; j < i; j++)
	{
	  fc_waiting_time[i] += fc_burst_time[j];
	}
    }

// Calculating Turnaround time

  for (i = 0; i < n_processes; i++)
    {
      fc_turn_aroundtime[i] = fc_burst_time[i] + fc_waiting_time[i];

      // Calculating average waiting and turnaround time

      avg_wait_time += fc_waiting_time[i];
      avg_turnaround_time += fc_turn_aroundtime[i];
    }

// Printing 

  printf ("\nProcess\t\t\tBurstTime\t\t\tWaiting Time\t\t\tTurnaround Time");

  for (i = 0; i < n_processes; i++)
    {
      printf ("\nP%d\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t\t%d", i + 1,
	      fc_burst_time[i], fc_waiting_time[i], fc_turn_aroundtime[i]);

    }

  printf ("\n\n");

  printf ("Average Waiting Time: %d", avg_wait_time / n_processes);
  printf ("\nAverage Turnaround Time: %d\n",
	  avg_turnaround_time / n_processes);
}




int
main ()
{
  int ch;
  do
    {

      printf ("1: FCFS\n");
      printf ("2: SJF\n");
      printf ("3: Priority\n");
      printf ("4: Round Robin\n");
      printf ("5: Exit\n");
      printf ("Enter a choice: \n");
      scanf ("%d", &ch);
      switch (ch)
	{
	case 1:
	  fcfs ();
	  break;
	case 2:
	  sjf ();
	  break;
	case 3:
	  priority ();
	  break;
	case 4:
	  printf ("4: Round Robin\n");
	  break;
	case 5:
	  exit (1);
	  break;
	default:
	  printf ("INVALID CHOICE");
	  break;
	}
    }
  while (ch == 1 || ch == 2 || ch == 3 || ch == 4 || ch == 5);

  return 0;
}
