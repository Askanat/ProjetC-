#include <stdlib.h>
#include <stdio.h>
#include "tas.h"

Bool Tas::Tas_ID(int i, int j)
{
    if (eval==NULL)
    {
        return compare(tableau[i],tableau[j]) ;
    }
    return compare(eval[tableau[i]],eval[tableau[j]]);
}

Bool Tas::comparaison(int i, int j)
{
 if (eval==NULL)
 {
  return compare(tableau[i],tableau[j]) ;}
 return compare(eval[tableau[i]],eval[tableau[j]]);
}

void Tas::echange(int i, int j)
{
    if (i<taille_max && j<taille_max)
    {
        int t = tableau[i];
        tableau[i]=tableau[j];
        tableau[j] = t;
        if (flag)
        {
            inverse[tableau[i]]=i;
            inverse[tableau[j]]=j;
        }
    }
}

void Tas::ParcoursVBas(int i)
{
    int fils = 2*i + 1 ;
    fils = ((fils<taille-1 && comparaison(fils+1,fils) ? fils+1 : fils));
    if (fils<taille && comparaison(fils,i))
    {
        echange(i, fils);
        descend(fils);
    }
}

void Tas::ParcoursVHaut(int i)
{
    if (i>0 && comparaison(i,(i-1)/2))
    {
        echange (i,(i-1)/2);
        remonte ((i-1)/2);
    }
}

Tas::Tas(int n)
{
    taille = taille_max = n;
    tableau = new int [n];
    compare = (fptr) inf;
    flag = 0;
    inverse = NULL;
}

Tas::Tas(int * ptr , int n, fptr comp, int * ptr2, Bool f)
{
    taille = taille_max = n;
    flag = 0;
    if (ptr!=NULL)
    {
        tableau = ptr;
        eval = ptr2;
        if(comp!=NULL)
        {
            compare = comp;
        }
        else
        { 
            compare = (fptr) inf;
        }
        if (flag)
        {
            inverse = new int [taille];
            for(int i=0 ; i<taille ; i++)
            {
                if (tableau[i]>taille-1)
                {
                    fprintf(stderr,"Tas non inversible");
                    flag = 0;
                    break;
                }
                inverse[tableau[i]]=i;
            }
        }
    }
    else 
    {
        taille = 0;
        tableau = NULL;
        compare = NULL;
        eval = NULL;
        inverse = NULL;
        flag = 0;
    }
}

Tas::~Tas()
{
    if (flag){
        delete [] inverse;
    }
}

int Tas::GetTaille()
{
    return taille;
}

void Tas::SetTaille (int val)
{
    taille+=val;
}

int Tas::Inverse(int i)
{
    if (flag)
    {
        return (inverse[i]);
    }
    fprintf(stderr,"Tas non réversible !");
    return 0;
}

void Tas::Tri()
{
    if (taille==0)
    {
        fprintf(stderr,"Tas Vide");
        exit(1);
    }
    for (int i=(taille/2 - 1); i>-1 ; i--)
    {
        descend(i);
    }
}