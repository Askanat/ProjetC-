#ifndef TAS_H
#define TAS_H
#include <stdio.h>

class Tas
{
public :
 	int taille;
 	int taille_max;
 	int * tableau;
 	int * eval;
 	int * inverse;
 	Bool flag;
 	fptr compare;
 	Bool Tas_ID(int i, int j);
 	Bool comparaison(int i, int j) ;
 	void echange( int i, int j);
 	void ParcoursVBas(int i);
 	void ParcoursVHaut(int i);
	Tas(int n);
	Tas(int * ptr=NULL, int n=0, fptr comp=NULL, int * ptr2=NULL, Bool f = faux);
 	~Tas();
 	void SetTaille(int val);
 	int GetTaille();
	int ExtrMinimum();
 	int Inverse(int i);
 	void Tri();
 	typedef Bool (*fptr)(int, int) ;
} ;

#endif