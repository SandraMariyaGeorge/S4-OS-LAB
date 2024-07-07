#include <stdio.h>
void main()
{
    int available[10], allocated[30][30], need[30][30], max[30][30], np,nr, finish[20], req[20], safeseq[10], i, j, p, k, flag = 0,c=0,f=0;
    printf("\nEnter the number of processes: ");
    scanf("%d", &np);
    printf("\nEnter the number of resource types: ");
    scanf("%d", &nr);
    printf("\nEnter the allocation matrix:\n");
    for (i = 0; i < np; i++)
    {
        finish[i] = 0;
        printf("Process %d: ", i);
        for (j = 0; j < nr; j++)
        {
            scanf("%d", &allocated[i][j]);
        }
    }
    printf("\nEnter the Maximum Resource matrix:\n");
    for (i = 0; i < np; i++)
    {
        printf("Process %d: ", i);
        for (j = 0; j < nr; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("\nEnter the available resources:\n");
    for (i = 0; i < nr; i++)
    {
        scanf("%d", &available[i]);
    }
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nr; j++)
        {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
    // Display table
    printf("\n-------------------Resource Allocation Table----------------------\n");
    printf("Process\tAllocated\tMaximum\t\tNeed\t\tAvailable\n");
    for (i = 0; i < np; i++)
    {
        printf("P%d\t", i);
        for (j = 0; j < nr; j++)
        {
            printf("%d ", allocated[i][j]);
        }
        printf("\t\t");
        for (j = 0; j < nr; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\t\t");
        for (j = 0; j < nr; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\t\t");
        if (i == 0)
        {
            for (j = 0; j < nr; j++)
            {
                printf("%d ", available[j]);
            }
        }
        printf("\n");
    }
    printf("\nEnter the requesting process number : ");
    scanf("%d", &p);
    printf("\nEnter the requesting instances : \n");
    for (i = 0; i < nr; i++)
    {
        scanf("%d", &req[i]);
    }

    // Check if request is valid...valid if req<=available and req<=need
    flag = 0;
    for (i = 0; i < nr; i++)
    {
        if (req[i] > available[i] && req[i] > need[p][i])
        {
            flag++;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Request Status : Successfull\n");
        for (i = 0; i < nr; i++)
        {
            available[i] -= req[i];
            need[p][i] -= req[i];
            allocated[p][i] += req[i];
        }
        printf("\n----------Modified Resource allocation table----------\n");
        printf("Process\tAllocated\tMaximum\t\tNeed\t\tAvailable\n");
        for (i = 0; i < np; i++)
        {
            printf("P%d\t", i);
            for (j = 0; j < nr; j++)
            {
                printf("%d ", allocated[i][j]);
            }
            printf("\t\t");
            for (j = 0; j < nr; j++)
            {
                printf("%d ", max[i][j]);
            }
            printf("\t\t");
            for (j = 0; j < nr; j++)
            {
                printf("%d ", need[i][j]);
            }
            printf("\t\t");
            if (i == 0)
            {
                for (j = 0; j < nr; j++)
                {
                    printf("%d ", available[j]);
                }
            }
            printf("\n");
        }

        // Deadlock detection
        for (i=0;i<np;i++)
        {
            if(finish[i]==0)
            {
                f=0;
                for(j=0;j<nr;j++)
                {
                    if(need[i][j]>available[j])
                    {
                        f=1;
                        break;
                    }
                }
                if(f==0)//need<=available
                {
                    for(k=0;k<nr;k++)
                    {
                        available[k]+=allocated[i][k];
                    }
                    finish[i]=1;
                    safeseq[c]=i;
                    printf("\n[Process %d] : Executed\n",i);
                    c++;
                    i=-1;//check again from start
                }
            }
        }
        if(c==np)
        {
            printf("\nSafe sequence : ");
            for(i=0;i<np;i++)
            {
                printf("P%d ",safeseq[i]);
            }
        }
        else
        {
            printf("\nDeadlock detected\n");
        }

        
    }
    else
        printf("\nRequest status : Fail\n");
}
