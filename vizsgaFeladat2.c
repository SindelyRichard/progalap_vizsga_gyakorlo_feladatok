#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct verseny
{
   char *nev;
   int helyezes;
   int pontszam;
}VERSENYZOK;

void feltolt(int *tomb,int size);
void kiir(char **nevek,int *helyezes,int size);
void rendez(char **nevek,int *helyezes,int size);
void elvalaszt();
void pontHelyezes(int *helyezes,int *pont,int size);
void struktFeltolt(char **nevek,int *helyezes,int *pont,VERSENYZOK *vs,int size);
void struktKiir(VERSENYZOK *vs,int size);
void struktBeOlvasas(VERSENYZOK *beOlvas,int size,char *nev);
void fileIras(VERSENYZOK *tomb,int size);
void fileBeolvas(int size);
void fileBeStrukt(VERSENYZOK *tomb,int size,char *nevTemp);

int main()
{
    char *nevek[] = {"Lewis Hamilton", "Giovanna Amati", "Chris Amonatti","Mario Andretti","Bob Anderson"}; 
    int meret = 5;
    int helyezes[5];
    int pont[5];
    feltolt(helyezes,meret);                                     //tömb feltöltése random számokkal
    kiir(nevek,helyezes,meret);                                  //tömb elemeinek kiírása
    rendez(nevek,helyezes,meret);                                //tömb rendezése amximum kiválasztás szerint
    elvalaszt();                                                 //elválasztó vonal
    kiir(nevek,helyezes,meret);                                  //tömb elemeinek kiírása
    elvalaszt();                                                 //elválasztó vonal
    pontHelyezes(helyezes,pont,meret);                           //helyezések szerint kapott pontok
    kiir(nevek,pont,meret);                                      //tömb elemeinek kiírása 
    VERSENYZOK vs[5];                                            //struktúra tömb deklarálása
    elvalaszt();                                                 //elválasztó vonal
    struktFeltolt(nevek,helyezes,pont,vs,meret);                 //struktúra tömb feltöltése 
    struktKiir(vs,meret);                                        //struktúra tömb kiírása
    VERSENYZOK beVs[5];                                          //struktúra tömb deklarálása
    elvalaszt();
    char *nev;
    struktBeOlvasas(beVs,meret,nev);
    struktKiir(beVs,meret);
    elvalaszt();
    fileIras(beVs,meret);
    fileBeolvas(meret);
    VERSENYZOK beStrukt[5];
    char* temp;
    fileBeStrukt(beStrukt,meret,temp);
    elvalaszt();
    struktKiir(beStrukt,meret);
    free(nev);                                                   //memóriaterület felszabadítása
    free(temp);
    return 0;
}
void feltolt(int *tomb,int size)
{
    int j=0;
    int i=0;
    srand(time(0));
    while(i<size)
    {
        int szam=rand()%(20+1-1)+1;
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
}
void kiir(char **nevek,int *helyezes,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\n%s \t %d",nevek[i],helyezes[i]);
    }
    return ;
}
void rendez(char **nevek,int *helyezes,int size)
{
    //maximum kiválasztás rendezés
    int i,j,maxindex;
    for (i = 0; i < size; i++)
    {
        maxindex = i;
        for (j = i+1; j < size; j++)
        {
            if(helyezes[j]>helyezes[maxindex])
            {
                maxindex = j;
            }
        }
        char *temp1 = nevek[i];
        int temp2 = helyezes[i];
        helyezes[i]=helyezes[maxindex];
        nevek[i] = nevek[maxindex];
        helyezes[maxindex]=temp2;
        nevek[maxindex]=temp1;
    }
    return ;
}
void elvalaszt()
{
    printf("\n--------------\n");
}
void pontHelyezes(int *helyezes,int *pont,int size)
{
    /*
       20-15 -> 1 pont
       14-10 -> 2 pont
       9-5   -> 3 pont
       4-2   -> 4 pont
       1     -> 5 pont
    */
    for (int i = 0; i < size; i++)
    {
        if(helyezes[i]<=20 && helyezes[i]>=15)
        {
           pont[i] = 1;
        }
        else if(helyezes[i]<=14 && helyezes[i]>=10)
        {
           pont[i] = 2;
        }
        else if(helyezes[i]<=9 && helyezes[i]>=5)
        {
           pont[i] = 3;
        }
        else if(helyezes[i]<=4 && helyezes[i]>=2)
        {
           pont[i] = 4;
        }
        else if(helyezes[i]==1)
        {
           pont[i] = 5;
        }
        else ;
    }
    return ;
}
void struktFeltolt(char **nevek,int *helyezes,int *pont,VERSENYZOK *vs,int size)
{
    for (int i = 0; i < size; i++)
    {
        vs[i].nev = nevek[i];
        vs[i].helyezes = helyezes[i];
        vs[i].pontszam=pont[i];
    }
    return ;
}
void struktKiir(VERSENYZOK *vs,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\n%s \t %d -> %d",vs[i].nev,vs[i].helyezes,vs[i].pontszam);
    }
    return ;
}
void struktBeOlvasas(VERSENYZOK *beOlvas,int size,char *nev)
{
    int helyezett;
    int potnszamok;  
    char ch;
    for (int i = 0; i < 5; i++)
    {
       
       
       nev=(char*)malloc(20*sizeof(char));                         //memoira lefoglalása
       printf("\nIrja be a %d.versenyzo nevet!",i+1);
       scanf("%[^\n]s",nev);
       printf("\nIrja be a %d.versenyzo helyezeset!",i+1);
       scanf("%d",&helyezett);
       printf("\nIrja be a %d.versenyzo pontszamat!",i+1);
       scanf("%d",&potnszamok);
       beOlvas[i].nev=nev;
       beOlvas[i].helyezes=helyezett;
       beOlvas[i].pontszam=potnszamok;
       helyezett=0;
       potnszamok=0;
       while(ch=getchar()!='\n');                                   //input buffer végére éünk, így nem olvassa be a "szemetet"
    }
    
    return ;
}
void fileIras(VERSENYZOK *tomb,int size)
{
    FILE *fptr;
    fptr=fopen("versenyzok2.txt","w");
    if(fptr==NULL)
    {
            printf("\nError!");
            exit(1);
    }
    for (int i = 0; i < size; i++)
    {
        fprintf(fptr,"%s\t%d\t%d\n",tomb[i].nev,tomb[i].helyezes,tomb[i].pontszam);
    }
    fclose(fptr);
    return ;
}
void fileBeolvas(int size)
{
    FILE *fptr;
    char ch;
    if((fptr=fopen("versenyzok2.txt","r"))==NULL)
    {
       printf("\nError!");
       exit(1);
    }
    do {
        ch = fgetc(fptr);
        printf("%c", ch);
 
        
    } while (ch != EOF);
    fclose(fptr);
    return ;
}
void fileBeStrukt(VERSENYZOK *tomb,int size,char *nevTemp)
{
    FILE *fptr;
    char ch;
    int j=0;
    int i=0;
    int helyezesek;
    int pontsz;
    fptr=fopen("versenyzok2.txt","r");
    if(fptr==NULL)
    {
        printf("\nError");
        exit(1);
    }
    else
    {
        while(j<size)
        {
            nevTemp=(char*)malloc(20*sizeof(char));
            if((fscanf(fptr,"%[^\t]%d\t%d",nevTemp,&helyezesek,&pontsz))!=EOF)
            {
            tomb[j].nev=nevTemp;
            tomb[j].helyezes=helyezesek;
            tomb[j].pontszam=pontsz;
            helyezesek=0;
            pontsz=0;
            j++;
            
            }
            else
            {
                break;
            }
        }
        fclose(fptr);
    }
    return;
}
