#include "Graphe.h"

Graphe::Graphe()
{
    list<Sommet> sommet;
    (*this).sommet = Sommet();

    Sommet *it [9999];
    for (int i = 0; i < sizeof(sommet); i++)
    {
        it[i] = new Sommet(i, sizeof(sommet));
    }
}

Graphe::~Graphe()
{
    sommet.~Sommet();
}

void Graphe::ajoutSommet(int _id, int size)
{
    Sommet(_id, size);
}

int Graphe::ajouterArete(int _etatArrivee, int _poids)
{
    sommet.setArete(_etatArrivee, _poids);
}

void Graphe::supprimerSommet(int *_id)
{
    sommet.delSommet(_id);
}

void Graphe::supprimerArrete(int *numArete)
{
    sommet.delArete(numArete);
}

void Graphe::afficherGraphe()
{
    cout << sommet.getPoidsVoisins();
}