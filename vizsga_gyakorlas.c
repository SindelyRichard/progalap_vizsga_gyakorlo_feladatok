#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randFeltolt(int *tomb,int meret);
void atrendez(char **tomb1,int *tomb2,int meret);
void kiir(char **tomb1,int *tomb2,int meret);
void pontszam(char **tomb1,int *tomb2,int meret);
int main()
{
    char *versenyzok[] = {"Bende","Benedek","Jonas","Aladin","Jozsef","Sandor"};
    int eredmeny[6];
    int size = 6;
    randFeltolt(eredmeny,size);
    kiir(versenyzok,eredmeny,size);
    printf("-----------------\n");
    atrendez(versenyzok,eredmeny,size);
    kiir(versenyzok,eredmeny,size);
    pontszam(versenyzok,eredmeny,size);
    return 0;
}
void randFeltolt(int *tomb,int meret)
{
    int j=0;
    int i=0;
    srand(time(0));
    while(i<meret)
    {
        int szam = rand()%(20+1-1)+1;
        j=0;
        while(j<i)
        {
            if(tomb[j]==szam)
            {
                break;
            }
            j++;
        }
        if(j==i)
        {
            tomb[i]=szam;
            i++;
        }
        
    }
    return ;
}
void atrendez(char **tomb1,int *tomb2,int meret)
{
    int i,j;
    for (i = meret-1; 0<i; --i)
    {
        for (j = 0; j < i; ++j)
        {
            if(tomb2[j]>tomb2[j+1])
            {
                int temp = tomb2[j];
                tomb2[j] = tomb2[j+1];
                tomb2[j+1] = temp;
                char *temp2 = tomb1[j];
                tomb1[j] = tomb1[j+1];
                tomb1[j+1] = temp2;
            }
        }
        
    }
    
    return ;
}
void kiir(char **tomb1,int *tomb2,int meret)
{
    for (int i = 0; i < meret; i++)
    {
        printf("%s %d\n",tomb1[i],tomb2[i]);
    }
    return ;
}
void pontszam(char **tomb1,int *tomb2,int meret)
{
    //20-10 5pont,9-4helyezett 10pont,3-1helyezett 20pont
    for (int i = 0; i < meret; i++)
    {
        if(tomb2[i]<=20 && tomb2[i]>=10)
        {
            printf("%s %d pont\n",tomb1[i],5);
        }
        else if(tomb2[i]<=9 && tomb2[i]>=4)
        {
            printf("%s %d pont\n",tomb1[i],10);
        }
        else if(tomb2[i]<=3 && tomb2[i]>=1)
        {
            printf("%s %d pont\n",tomb1[i],20);
        }
    }
    
    return ;
}