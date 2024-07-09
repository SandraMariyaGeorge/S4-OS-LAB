#include <stdio.h>
#define INT_MAX 999
void display(int f[]);
int search(int a, int f[]);
int findLRU(int time[], int nf);
int np, nf;

int main()
{
    printf("Enter the Number of Page Referencing Sequence : ");
    scanf("%d", &np);
    printf("Enter the Number of Frames : ");
    scanf("%d", &nf);

    int f[nf], p[np], time[nf];

    for (int i = 0; i < nf; i++)
    {
        f[i] = -1;
        time[i] = -1; 
    }

    printf("Enter the Page Referencing Sequence : ");
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &p[i]);
    }

    int miss = 0, hit = 0;

    for (int i = 0; i < np; i++)
    {
        int pos = search(p[i], f);
        if (pos == -1)
        {
            miss++;
            // findLRU function is called to find the position of the least recently used page
            pos = findLRU(time, nf);
            f[pos] = p[i];
            time[pos] = i;
            printf("For %d -", p[i]);
            display(f);
        }
        else
        {
            hit++;
            time[pos] = i;
            printf("For %d -  HIT\n", p[i]);
        }
    }
    printf("\n\nPAGE FAULT : %d\n", miss);
    return 0;
}

int search(int a, int f[])
{
    for (int i = 0; i < nf; i++)
    {
        if (a == f[i])
        {
            return i;
        }
    }
    return -1;
}

int findLRU(int time[], int nf)
{
    int min = INT_MAX, pos = 0;
    for (int i = 0; i < nf; i++)
    {
        if (time[i] == -1) // If frame has not been used
            return i; // This frame can be used immediately
        if (time[i] < min)
        {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

void display(int f[])
{
    for (int i = 0; i < nf; i++)
    {
        if (f[i] == -1)
            printf(" - ");
        else
            printf(" %d", f[i]);
    }
    printf("\n");
}