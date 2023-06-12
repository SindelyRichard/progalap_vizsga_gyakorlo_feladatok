#include <stdio.h>

void buborek_rendezes(int *tomb,int meret);
void kiir(int *tomb,int meret);
void beszuro_rendezes(int *tomb,int meret);

int main()
{
    int tomb[]={12,22,34,88,1,5};
    int meret=sizeof(tomb)/sizeof(int);
    buborek_rendezes(tomb,meret);
    //beszuro_rendezes(tomb,meret);
    kiir(tomb,meret);
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
    for (int i = 0; i < meret; i++)
    {
        printf("\n%d",tomb[i]);
    }
    
}
void beszuro_rendezes(int *tomb,int meret)
{
    int j;
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
