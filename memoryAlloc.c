#include <stdio.h>
void display();
struct block
{
    int id, size, allocated;
} b[10], temp;

struct process
{
    int id, size, blkno;
} p[10];
int nb, np;
void firstfit()
{
    int i,j;
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nb; j++)
        {
            if (b[j].size >= p[i].size && b[j].allocated == 0)
            {
                b[j].allocated = 1;
                p[i].blkno = b[j].id;
                break;
            }
        }
    }
    display();
}

void bestfit()
{
    int i,j;
    for (i = 0; i < nb-1; i++)
    {
        for (j = 0; j < nb-1; j++)
        {
            if (b[j].size > b[j + 1].size)
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
        printf("\n");
    }
    firstfit();
}

void worstfit()
{
    int i,j;
    for (i = 0; i < nb-1; i++)
    {
        for (j = 0; j < nb-1; j++)
        {
            if (b[j].size < b[j + 1].size)
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    firstfit();
}

void display()
{
    int i,j;
    for (i = 0; i < np; i++)
    {
        if (p[i].blkno != -1)
        {
            printf("Process %d-%d is allocated to block %d- ", p[i].id, p[i].size, p[i].blkno);
            for(j=0;j<nb&&p[i].blkno!=b[j].id;j++);
            printf("%d\n",b[j].size);
        }
    }
    for (i = 0; i < np; i++)
    {
        if (p[i].blkno == -1)
        {
            printf("Process %d-%d is not allocated\n", p[i].id,p[i].size);
        }
    }
}

int main()
{
    int i, ch;
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the block details:\n");
    for (i = 0; i < nb; i++)
    {
        printf("Block %d: ", i);
        scanf("%d %d", &b[i].id, &b[i].size);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the process details:\n");
    for (i = 0; i < np; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &p[i].id, &p[i].size);
    }

    do
    {
        // intialize block as not allocated and process block number
        for (i = 0; i < nb; i++)
            b[i].allocated = 0;
        for (i = 0; i < np; i++)
            p[i].blkno = -1;

        printf("1--First Fit\n2--Best Fit\n3--Worst Fit\n4--Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            //display blocks
            for(i=0;i<nb;i++)
                printf("%d \t",b[i].size);
            printf("\n");
            firstfit();
            break;
        case 2:
            bestfit();
            break;
        case 3:
            worstfit();
            break;
        case 4:
            break;
        }
    } while (ch != 4);
    return 0;
}