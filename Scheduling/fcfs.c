#include <stdio.h>
#include <string.h>
struct pr
{
    int at, bt, tt, wt, ct;
    char prname[10];
} p[10], temp;

struct gantt
{
    int st, ct;
    char prname[10];
} g[10];

void main()
{
    int i, j, n, pt = 0, gt = 0, timeelapsed = 0;
    float totalt = 0, totalw = 0;
    float avgwt, avgtt;
    printf("Enter the no. of processes\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the process details\n");
        printf("Enter process name :\n");
        scanf("%s", p[i].prname);
        printf("Enter its Arrival time :");
        scanf("%d", &p[i].at);
        printf("Enter its Burst time :");
        scanf("%d", &p[i].bt);
    }
    printf("processes entered are:\n");
    printf("pr_name\tAT\tBT\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\n", p[i].prname, p[i].at, p[i].bt);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    printf("processes sorted according to arrival time\n");
    printf("pr_name\tAT\tBT\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\n", p[i].prname, p[i].at, p[i].bt);
    }
    while (pt < n)
    {
        if (timeelapsed >= p[pt].at)
        {

            g[gt].st = timeelapsed;
            timeelapsed += p[pt].bt;
            g[gt].ct = timeelapsed;
            strcpy(g[gt].prname, p[pt].prname);
            p[pt].tt = g[gt].ct - p[pt].at;
            p[pt].wt = g[gt].st - p[pt].at;
            p[pt].ct = timeelapsed;
            pt++;
            gt++;
        }
        else
        {
            g[gt].st = timeelapsed;
            g[gt].ct = p[pt].at;
            timeelapsed = g[gt].ct;
            strcpy(g[gt].prname, "idle");
            gt++;
        }
    }
    printf("PROCESS TABLE\n");
    printf("Pr_name\tAT\tBT\tCT\tWT\tTT\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t", p[i].prname);
        printf("%d\t", p[i].at);
        printf("%d\t", p[i].bt);
        printf("%d\t", p[i].ct);
        printf("%d\t", p[i].wt);
        printf("%d\n", p[i].tt);
        totalw += p[i].wt;
        totalt += p[i].tt;
    }

    printf("GANTT CHART\n");
    for (i = 0; i < gt; i++)
    {
        printf("%s\t|", g[i].prname);
    }
    printf("\n%d\t", g[gt].st);
    for (i = 0; i < gt; i++)
    {
        printf("%d\t", g[i].ct);
    }

    avgwt = totalw / n;
    avgtt = totalt / n;
    printf("\nAverage waiting time =%f\n", avgwt);
    printf("Average turnaround time = %f\n", avgtt);
}