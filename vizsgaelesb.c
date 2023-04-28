#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void feltolt(int *tomb,int size);
void rendezes(int *tomb, int size);
void kiir(int *tomb, double *tomb2, int size);
double tti(double magas, int suly);
char *ttiErtek(double tti);
void elvalaszt();

int main(){
    double magassag[] = {1.8,1.4,1.58,1.67,1.9,1.86};
    int size = sizeof(magassag)/sizeof(double);
    int testsuly[size];
    feltolt(testsuly,size);
    rendezes(testsuly,size);
    kiir(testsuly,magassag,size);
    elvalaszt();
    for (int i = 0; i < size; i++)
    {
        printf("\n%.2lf",tti(magassag[i],testsuly[i]));
    }
    char *testMegn[3] = {"sovany", "normal","tulsulyos"};
    printf("\nIrja be (sovany,normal,tulsulyos)");
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
                printf("\nTTI: 0-18.9");
                break;
            case 1:
                 printf("\nTTI: 18.5-24.99");
                 break;
            case 2:
                  printf("\nTTI: 25-40");
            default:
                break;
            }
        }
    }
    free(s);
    printf("\nIrja be az on magassagat (meterbe) es az on testsulyat! (magassag,testsuly)");
    double beMagassag;
    int beSuly;
    scanf("%lf,%d",&beMagassag,&beSuly);
    double ttiValt = tti(beMagassag,beSuly);
    printf("\nAz on testtomegindexe: %.2lf",ttiValt);
    printf("\nKategoria: %s",ttiErtek(ttiValt));
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
      printf("\n%.2lf\t%d",tomb2[i],tomb[i]);
   }
   
}
double tti(double magas, int suly)
{
    double eredmeny = suly/(magas*magas);
    return eredmeny;
}
char *ttiErtek(double tti)
{
    if(tti>0 && tti<18.5)
    {
        return "Sovany";
    }
    if(tti>18.49 && tti<25)
    {
        return "Normal";
    }
    if(tti>24.99)
    {
        return "tulsulyos";
    }
}
void elvalaszt()
{
    printf("\n");
    return ;
}
