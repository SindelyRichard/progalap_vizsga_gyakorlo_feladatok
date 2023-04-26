#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void feltolt(int *tomb,int size);
void rendezes(int *tomb, int size);
void kiir(int *tomb, double *tomb2, int size);
double tti(double magas, int suly);

int main(){
    double magassag[] = {1.8,1.4,1.58,1.67,1.9,1.86};
    int size = sizeof(magassag)/sizeof(double);
    int testsuly[size];
    feltolt(testsuly,size);
    rendezes(testsuly,size);
    kiir(testsuly,magassag,size);
    for (int i = 0; i < size; i++)
    {
        printf("%.2lf\n",tti(magassag[i],testsuly[i]));
    }
    char *testMegn[3] = {"sovany", "normal","tulsulyos"};
    printf("Irja be (sovany,normal,tulsulyos)\n");
    char *s;
    s = (char*)malloc(2*sizeof(char));
    scanf("%s",s);
    for (int i = 0; i < 3; i++)
    {
        if(strcmp(s,testMegn[i])==0)
        {
            switch (i)
            {
            case 0:
                printf("\n0-60kg");
                break;
            case 1:
                 printf("\n70-85kg");
                 break;
            case 2:
                  printf("\n85-90kg");
            default:
                break;
            }
        }
    }
    free(s);
    return 0;
}
void feltolt(int *tomb, int size)
{
   srand(time(0));
   for (int i = 0; i < size; i++)
   {
      tomb[i] = rand()%(81-40)+40;
   }
   
}
void rendezes(int *tomb, int size)
{
    int i,j,temp,maxindex;
    for (i = 0; i < size-1; i++)
    {
        maxindex = i;
        for (j=i+1; j < size-1; j++)
        {
            if(tomb[j]>tomb[maxindex])
            {
                maxindex = j;
           }
        }
        temp = tomb[i];
        tomb[i] = tomb[maxindex];
        tomb[maxindex] = temp;
        
    }
    
}
void kiir(int *tomb, double *tomb2, int size)
{
   for (int i = 0; i < size; i++)
   {
      printf("%.2lf\t%d\n",tomb2[i],tomb[i]);
   }
   
}
double tti(double magas, int suly)
{
    double eredmeny = suly/(magas*magas);
    return eredmeny;
}
