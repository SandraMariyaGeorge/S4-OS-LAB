#include<stdio.h>
#include<unistd.h>

void create();
void first();
void best();
void worst();
int mb[100], mp[100], np, nb, i, j, op, k, n , flag[100], flag1[100], l = -1, temp;

int main() {
    do {
        printf("1: FIRST FIT\n2: BEST FIT\n3: WORST FIT\n");
        printf("Enter your choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                create();
                first();
                break;

            case 2:
                create();
                best();
                break;

            case 3:create();
                   worst();
               break;

            default:
                printf("Incorrect option\n");
                break;
        }
    } while (op < 4);
    return 0;
}

void create() {
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the memory space for each block: ");
    for (i = 0; i < nb; i++) {
        scanf("%d", &mb[i]);
        flag[i]=0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &np);
    printf("Enter the size of each process: ");
    for (i = 0; i < np; i++) {
        scanf("%d", &mp[i]);
         flag1[i]=0;
    }
}

void first() {
    for (i = 0; i < np; i++) {
        for (j = 0; j < nb; j++) {
            if (mp[i] <= mb[j] && flag[j] == 0) {
                mb[j] -= mp[i];
                flag[j] = 1;
                 flag1[i] = 1;
                k = j;
                break;
            }
        }
        if(flag1[i]==1)
        {
        printf("Process %d allocated @[%d]", mp[i], k);
        printf("Current partition: ");
        for (l = 0; l < nb; l++) {
            printf("%d\t", mb[l]);
        }
        printf("\n");
        }
        else{
            printf("process %d has to wait\n",mp[i]);
        }
    }
}

void best() {
   
    for (i = 0; i < np; i++) {
          l=-1;
        for (j = 0; j < nb; j++) {
           
            if (mp[i] <= mb[j] && flag[j] == 0) 
            {
               temp=mb[j];
               for(k = 0;k < nb; k++)
               {
                 if(mb[k] <= temp && flag[k] == 0 && mp[i] <= mb[k])
                 {
                    temp=mb[k];
                    l=k;
                 }
               }
            }
          
        }
          if(l != -1)
            {
                 mb[l] -= mp[i];
                flag[l] = 1;
                flag1[i]=1;
                 printf("Process %d allocated @[%d]", mp[i], l);
                printf("Current partition: ");
                for (n = 0; n < nb; n++) 
                {
                    printf("%d\t", mb[n]);
                }
                printf("\n");
            
            }
        else{
            printf("process %d has to wait\n",mp[i]);
        }
    }
}
void worst()
{
    
    for (i = 0; i < np; i++)
     {
         temp=mb[0];
        for (j = 1; j < nb; j++) 
        {
           
            if(temp<mb[j]&&flag[j]==0)
            {
                temp=mb[j];
                k=j;
            }
        
        }
        if(flag[k]==0)
        {
             mb[k] -= mp[i];
                flag[k] = 1;
                flag1[i]=1;
            
        }
        
             if(flag1[i]==1)
        {
        printf("Process %d allocated @[%d]", mp[i], k);
        printf("Current partition: ");
        for (l = 0; l < nb; l++) {
            printf("%d\t", mb[l]);
        }
        printf("\n");
        }
        else{
            printf("process %d has to wait\n",mp[i]);
        }
    }


}