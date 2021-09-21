#include <stdio.h>

int main()
{

    int n_processes, n_resources;
    int total_resources[20], available_resources[20], work[20], finish[20] = {0};
    int exec_process_list[20]; // Store the final safe sequence state(if it exists)
    int ctr = 0;               // Index for exec_process_list
    int max[20][20], allocation[20][20], need[20][20];
    printf("Enter the number of processes & resources:");
    scanf("%d %d", &n_processes, &n_resources);
    printf("\nEnter Max matrix:\n");
    for (int i = 0; i < n_processes; i++)
    {
        for (int j = 0; j < n_resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("\nEnter Allocation matrix:\n");
    for (int i = 0; i < n_processes; i++)
    {
        for (int j = 0; j < n_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter total resources: ");
    for (int i = 0; i < n_resources; i++)
        scanf("%d", &total_resources[i]);

    // Finding available resources
    for (int i = 0; i < n_resources; i++)
    {
        available_resources[i] = total_resources[i];
        for (int j = 0; j < n_processes; j++)
        {
            available_resources[i] -= allocation[j][i];
        }
        work[i] = available_resources[i];
    }

    // Finding need matrix
    // Formula: NEED[i][j] = MAX[i][j] - ALLOCATION[i][j]
    for (int i = 0; i < n_processes; i++)
    {
        for (int j = 0; j < n_resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // SAFETY Algorithm
    for (int i = 0; i < n_processes; i++)
    {
        if (finish[i] == 0)
        {
            finish[i] = 1;
            for (int j = 0; j < n_resources; j++)
            {
                if (finish[i] == 1 && need[i][j] > work[j])
                {
                    finish[i] = 0;
                    break;
                }
            }
            char ch,tmp_index = i;
            if (finish[i] == 1)
            {
                exec_process_list[ctr] = i + 1; //Storing process number
                ctr++;

                printf("\n\nAll the resources can be allocated to Process %d\n", (i + 1));
                printf("Available resources are: ");
                for (int k = 0; k < n_resources; k++)
                {
                    work[k] += allocation[i][k];
                    printf("%d ", work[k]);
                }
                i = -1; // Resetting i to 0 to start calculating from 1st process
                ch = 'y';
            }
            else
            {
                ch = 'n';
            }
            printf("\nProcess %d executed?: %c", tmp_index, ch);
        }
    }

    int tmp_flag = 1;
    for (int i = 0; i < n_processes; i++)
    {
        if (finish[i] == 0)
        {
            tmp_flag = 0;
            break;
        }
    }
    if (tmp_flag == 1)
    {
        printf("\n\nSystem is in safe mode.\nThe given state is a safe state: ");
        for (int i = 0; i < n_processes; i++)
        {
            printf("%d  ", exec_process_list[i]);
        }
    } else {
        printf("\n\nSystem is in unsafe state.");

    }
}
