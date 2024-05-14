#include <stdio.h>
#include <string.h>
struct process
{
	int at, bt, ct, tt, wt, pr, status;
	char name[10];
} p[50], temp;
struct gant
{
	int st,ct;
	char name[10];

}gant[50];
int main()
{
	int i, n, j, g, f, min;
	float tat = 0, twt = 0;
	int idle = 0, ls = 0;

	printf("Enter the number of processes :");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter Process name Arrival time, Burst Time and Priority of process %d : \n", i + 1);
		scanf("%s%d%d%d", p[i].name, &p[i].at, &p[i].bt, &p[i].pr);
		p[i].status = 0;
	}
	i = 0;
	while (ls < n)
	{
		for (j = 0, f = 0; j < n; j++)
		{
			if (i >= p[j].at && p[j].status == 0) // jth process can be taken to ready q
			{
				if (f == 0) // ready q was empty
				{
					min = j;
					f = 1;
				}
				else if (p[min].pr >= p[j].pr && p[min].at > p[j].at)
				{
					min = j;
				}
			}
		}
		if (idle == 0 && f == 0) // front=0 means ready q empty
		{
			strcpy(gant[g].name, "Idle");
			gant[g].st = i;
			gant[g].ct=i+1;
			i++;
			idle = 1;
		}
		else if (f == 1) // f=1,processes are in ready q
		{
			if (idle == 1) // previously CPU was idle
			{
				gant[g].ct = i;
				g++;
				idle = 0;
			}
			strcpy(gant[g].name, p[min].name);
			p[min].status = 1;
			gant[g].st = i;
			gant[g].ct = i + p[min].bt;
			i = gant[g].ct;
			p[min].ct = gant[g].ct;
			p[min].tt = p[min].ct - p[min].at;
			p[min].wt = p[min].tt - p[min].bt;
			g++;
			ls++;
		}
		else
		{
			i++;
		}
	}

	printf("Gantt chart:\n");
	for (i = 0; i < g; i++)
	{
		printf("| %s   ", gant[i].name);
	}

	printf("|\n");
	printf("0\t");
	for (i = 0; i < g; i++)
		printf("%d\t", gant[i].ct);

	printf("\nTable :\n");
	printf(" _____________________________________\n");
	printf("|Process| AT | BT | P  | CT | TT | WT |\n");
	printf("|-------------------------------------|\n");
	for (i = 0; i < n; i++)
	{
		printf("|%s \t| %d | %d | %d | %d | %d | %d |\n", p[i].name, p[i].at, p[i].bt, p[i].pr, p[i].ct, p[i].tt, p[i].wt);
		twt = twt + p[i].wt;
		tat = tat + p[i].tt;
	}
	printf(" _____________________________________\n");
	twt = twt / n;
	tat = tat / n;
	printf("\nAverage WT:%f\n", twt);
	printf("Average TT:%f\n", tat);
}