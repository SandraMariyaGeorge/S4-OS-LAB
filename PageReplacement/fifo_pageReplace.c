#include<stdio.h>
void display(int f[]);
int search(int a,int f[]);
int np,nf,j=0;
int main()
{

    printf("Enter the Number of Page Referencing Sequence : ");
    scanf("%d",&np);
    printf("Enter the Number of Frames : ");
    scanf("%d",&nf);

    int f[nf] , p[np];

    for(int i = 0 ; i < nf ; i++)
    {
        f[i] = -1;
    }

    printf("Enter the Page Referencing Sequence : ");
    for(int i = 0 ; i < np ; i++)
    {
        scanf("%d",&p[i]);
    }

    int miss= 0,hit= 0;

    for(int i = 0 ; i < np ; i++)
    {
        if(search(p[i],f)==-1)
        {
            miss++;
            f[j]=p[i];
            j=(j+1)%nf;
            printf("For %d -",p[i]);
            display(f);
        }
        else
        {
            hit++;
            printf("For %d -  HIT\n",p[i]);
        }
    }
    printf("\n\nPAGE FAULT : %d",miss);
}
int search(int a,int f[])
{
    int i;
    for(i=0;i<nf;i++)
    {
        if(a==f[i])
        {
            return 0;
        }
    }
    return -1;
}
void display(int f[])
{
    int i;
    for(i=0;i<nf;i++)
    {
        if(f[i]==-1)
            printf("  ");
        else
            printf(" %d",f[i]);
    }
    printf("\n");
}
