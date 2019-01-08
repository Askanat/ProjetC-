#include "Sommet.h"

Sommet::Sommet(){}

Sommet::Sommet(int _id, int size)
{
    (*this).id = _id;
    (*this).poids = new std::list<int> ();
    (*this).poids->assign(0, size);
    (*this).nb_arc = (*this).nb_arc +1;
}

Sommet::Sommet(int _id, list<int> *_p)
{
    (*this).id = _id;
    (*this).poids = _p;
    (*this).nb_arc = (*this).nb_arc +1;
}

Sommet::~Sommet()
{
    delete poids;
}

int Sommet::getId()
{
    return id;
}

list<int>* Sommet::getPoidsVoisins()
{
    return poids;
}

void Sommet::setArete(int numArete, int poids)
{
    list<int>::iterator it = (*this).poids->begin();
    for (int i = 0; i < numArete; ++i)
    { ++it;}
    (*this).poids->insert(it, poids);
}

void Sommet::delSommet(int *id)
{
    delete id;
}

void Sommet::delArete(int *numArete)
{
    delete numArete;
}

int Sommet::getArcNb()
{
    return nb_arc;
}