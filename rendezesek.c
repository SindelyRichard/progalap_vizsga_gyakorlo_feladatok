#include <stdio.h>
#include <stdlib.h>

void buborek_rendezes(int *tomb,int meret);
void kiir(int *tomb,int meret);
void maximum_kivalasztas_rendezes(int *tomb, int meret);
void minimum_kivalasztas_rendezes(int *tomb, int meret);
void beszuro_rendezes(int *tomb,int meret);
void szamlalo_rendezes(int *tomb,int *index,int meret);

int main()
{
    int tomb[8] = {3,8,2,9,1,45,65,99};
    int index[]={1,1,1,1,1,1,1,1};
    int meret = sizeof(tomb)/sizeof(int);
    buborek_rendezes(tomb,meret);
    kiir(tomb,meret);
    //minimum_kivalasztas_rendezes(tomb,meret);
    //kiir(tomb,meret);
    //maximum_kivalasztas_rendezes(tomb,meret);
    //kiir(tomb,meret);
    //beszuro_rendezes(tomb,meret);
    //kiir(tomb,meret);
    //szamlalo_rendezes(tomb,index,meret);
    //kiir(tomb,meret);
    //kiir(index,meret);
    return 0;
}
void buborek_rendezes(int *tomb,int meret)
{
    int i,j,temp;
    for (i = meret-1; 0<i; --i)
    {
        for (j = 0; j < i; j++)
        {
            if(tomb[j]>tomb[j+1])
            {
               temp=tomb[j];
               tomb[j] = tomb[j+1];
               tomb[j+1]=temp;
            }
        }
        
    }
}
void kiir(int *tomb,int meret)
{
    for (int i = 0; i < meret-1; i++)
    {
        printf("%d\n",tomb[i]);
    }
}
void maximum_kivalasztas_rendezes(int *tomb, int meret)
{
    int i,j,maxindex;
    for (int i = 0; i < meret; i++)
    {
        maxindex = i;
        for (int j = i+1; j < meret; j++)
        {
            if(tomb[j]>tomb[maxindex])
            {
                maxindex = j;
            }
        }
        int temp = tomb[i];
        tomb[i]=tomb[maxindex];
        tomb[maxindex] = temp;
    }
}
void minimum_kivalasztas_rendezes(int *tomb, int meret)
{
    int i,j,minindex;
    for (int i = 0; i < meret; i++)
    {
        minindex = i;
        for (int j = i+1; j < meret; j++)
        {
            if(tomb[j]<tomb[minindex])
            {
                minindex = j;
            }
        }
        int temp = tomb[i];
        tomb[i]=tomb[minindex];
        tomb[minindex] = temp;
    }
}
void beszuro_rendezes(int *tomb,int meret)
{
    int j=1;
    int seged = 0;
    for (int i=2; i < meret; i++)
    {
        seged = tomb[i];
        for (j = i-1; j>=0 && seged<tomb[j]; j--)
        {
            tomb[j+1] = tomb[j];
            
        }
        tomb[j+1] = seged;
    }   
}
void szamlalo_rendezes(int *tomb,int *index,int meret)
{
    for (int i = 1; i < meret; i++)
    {
        for (int j = 0; j < meret; j++)
        {
            if (tomb[j]<tomb[i])
            {
               index[i] = index[i]+1;
            }
            else index[j] = index[j]+1;
        }     
    }
}

