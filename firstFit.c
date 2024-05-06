#include<stdio.h>
#define max 25
void main()
{
    int frag[max], b[max], p[max], i, j, nb, np, temp, lowest = 10000;
    static int bf[max], ff[max];
    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);
    printf("Enter the number of process:");
    scanf("%d", &np);
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the processes :-\n");
    for (i = 1; i <= np; i++)
    {
        printf("Process %d:", i);
        scanf("%d", &p[i]);
    }
    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - p[i];
                if (temp >= 0)
                    if (lowest > temp)
                    {
                        ff[i] = j;
                        lowest = temp;
                    }
            }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
        lowest = 10000;
    }
    printf("\nProcess No\tProcess Size \tBlock No\tBlock Size\tFragment");
    for (i = 1; i <= np && ff[i] != 0; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], ff[i], b[ff[i]], frag[i]);
}