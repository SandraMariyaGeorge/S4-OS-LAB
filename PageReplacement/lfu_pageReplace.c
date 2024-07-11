#include <stdio.h>
#define INT_MAX 999

void display(int f[]);
int search(int a, int f[]);
int findLFU(int freq[], int time[], int nf);
int np, nf;
int f[10];

int main()
{
    printf("Enter the Number of Page Referencing Sequence : ");
    scanf("%d", &np);
    printf("Enter the Number of Frames : ");
    scanf("%d", &nf);
    int f[nf], p[np], freq[nf], time[nf];

    for (int i = 0; i < nf; i++)
    {
        f[i] = -1;
        freq[i] = 0;
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
            // findLFU function is called to find the position of the least frequently used page
            pos = findLFU(freq, time, nf);
            f[pos] = p[i];
            freq[pos] = 1;
            time[pos] = i;
            printf("For %d -", p[i]);
            display(f);
        }
        else
        {
            hit++;
            freq[pos]++;
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

int findLFU(int freq[], int time[], int nf)
{
    int min = INT_MAX, pos = 0;

    for (int i = 0; i < nf; i++)
    {
        if (f[i] == -1) // If frame is empty
            return i;   // This frame can be used immediately
        if (freq[i] < min)
        {
            min = freq[i];
            pos = i;
        }
        else if (freq[i] == min) // If frequencies are the same, check LRU among them
        {
            if (time[i] < time[pos])
            {
                pos = i;
            }
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
