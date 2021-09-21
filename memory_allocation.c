#include <stdio.h>

int n_processes, n_mem_blocks;
int mem_blocks[20], processes[20];

void first_fit()
{
    // FIRST FIT

    int available[20] = {0}; //available acts as bool array to check if the given mem block is occupied
    // 0 - memory is available, 1- Memory is occupied

    printf("\nFIRST FIT:\n");
    printf("\nProcess No\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n_processes; i++)
    {
        int tmp_flag = 0; //To check for not allocated after inner loop ends
        for (int j = 0; j < n_mem_blocks; j++)
        {
            if (available[j] == 0 && processes[i] <= mem_blocks[j])
            {
                printf("%d\t\t%d\t\t%d\n", (i + 1), processes[i], (j + 1));
                available[j] = 1;
                tmp_flag = 1;
                break;
            }
        }
        if (tmp_flag == 0)
            printf("%d\t\t%d\t\tNot Allocated\n", (i + 1), processes[i]);
    }
}

void best_fit()

    {
        int available[20] = {0}; //available acts as bool array to check if the given mem block is occupied
        // 0 - memory is available, 1- Memory is occupied

        // Best Fit
        printf("\nBEST FIT:\n");
        printf("\nProcess No.\tProcess Size\tBlock No.\n");
        for (int i = 0; i < n_processes; i++)
        {
            int min_avail_block = -1;
            int tmp_index = -1;
            for (int j = 0; j < n_mem_blocks; j++)
            {
                if (available[j] == 0 && processes[i] <= mem_blocks[j])
                {
                    if (min_avail_block == -1) // For first case
                    {
                        min_avail_block = mem_blocks[j];
                        tmp_index = j;
                    }
                    else if (min_avail_block >= mem_blocks[j])
                    {
                        min_avail_block = mem_blocks[j];
                        tmp_index = j;
                    }
                }
            }

            if (min_avail_block != -1)
            {
                available[tmp_index] = 1;
                printf("%d\t\t%d\t\t%d\n", (i + 1), processes[i], (tmp_index + 1));
            }
            else
            {
                printf("%d\t\t%d\t\tNot Allocated\n", (i + 1), processes[i]);
            }
        }
    }

    void worst_fit()
    {
        int available[20] = {0}; //available acts as bool array to check if the given mem block is occupied
        // 0 - memory is available, 1- Memory is occupied

        // Worst Fit
        printf("\nWORST FIT:\n");
        printf("\nProcess No.\tProcess Size\tBlock No.\n");
        for (int i = 0; i < n_processes; i++)
        {
            int max_avail_block = -1;
            int tmp_index = -1;
            for (int j = 0; j < n_mem_blocks; j++)
            {
                if (available[j] == 0 && processes[i] <= mem_blocks[j])
                {
                    if (max_avail_block <= mem_blocks[j])
                    {
                        max_avail_block = mem_blocks[j];
                        tmp_index = j;
                    }
                }
            }

            if (max_avail_block != -1)
            {
                available[tmp_index] = 1;
                printf("%d\t\t%d\t\t%d\n", (i + 1), processes[i], (tmp_index + 1));
            }
            else
            {
                printf("%d\t\t%d\t\tNot Allocated\n", (i + 1), processes[i]);
            }
        }
    }

int main()
{

    printf("Enter the size of processes & memory blocks:");
    scanf("%d %d", &n_processes, &n_mem_blocks);
    printf("\nEnter memory blocks:\n");
    for (int i = 0; i < n_mem_blocks; i++)
    {
        scanf("%d", &mem_blocks[i]);
    }

    printf("\nEnter processes:\n");
    for (int i = 0; i < n_processes; i++)
    {
        scanf("%d", &processes[i]);
    }

    first_fit();
    best_fit();
    worst_fit();

    
}
