#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX 10
struct process
{
  int at, bt, ct, tt, wt;
  char pname[10];
} p[MAX], temp, gant[MAX], idle, min;
void main()
{
  int loc, time, i, n, j, g;
  float tat = 0, twt = 0;
  printf("Enter the number of processes :");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    printf("Enter process name,Arrival time and Burst Time of process : \n");
    scanf("%s%d%d",p[i].pname,&p[i].at, &p[i].bt);
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
  idle.bt = 0;
  for (i = 0, g = 0, time = 0; i < n; i++)
  {
    if (time < p[i].at)
    {
      gant[g] = idle;
      gant[g++].ct = time = p[i--].at;
    }
    else
    {
      loc = i;
      for (j = i, min.bt = p[j].bt; j < n && p[j].at <= time; j++)
      {
        if (p[j].bt < min.bt)
        {
          min = p[j];
          loc = j;
        }
      }
      if (i != loc)
      {
        p[loc] = p[i];
        p[i] = min;
      }
      time += p[i].bt;
      p[i].ct = time;
      gant[g++] = p[i];
    }
  }
  for (i = 0; i < n; i++)
  {
    p[i].tt = p[i].ct - p[i].at;
    p[i].wt = p[i].tt - p[i].bt;
    twt = twt + p[i].wt;
    tat = tat + p[i].tt;
  }
  printf("Gantt chart:\n");
  for (i = 0; i < g; i++)
  {
    if (gant[i].bt == 0)
      printf("| Idle\t");
    else
      printf("| %s\t", gant[i].pname);
  }
  printf("|\n");
  printf("0\t");
  for (i = 0; i < g; i++)
    printf("%2d\t", gant[i].ct);
  printf("\nTable :\n");
  printf(" _________________________________\n");
  printf("|Process| AT | BT | CT | TT | WT |\n");
  printf("|--------------------------------|\n");
  for (i = 0; i < n; i++)
  {
    printf("|%s \t| %2d | %2d | %2d | %2d | %2d |\n", p[i].pname, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
  }
  printf(" _________________________________\n");
  twt = twt / n;
  tat = tat / n;
  printf("\nAverage WT:%f\n", twt);
  printf("Average TT:%f\n", tat);
}
