#ifndef GRAPHE_H
#define GRAPHE_H
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include "Sommet.cpp"

class Graphe
{
private:
    Sommet sommet;

public:
    Graphe();

    ~Graphe();

    void ajoutSommet(int _id, int size);

    int ajouterArete(int _etatArrivee, int _poids);

    void supprimerSommet(int *_id);

    void supprimerArrete(int *numArete);

    void afficherGraphe();
};

#endif // GRAPHE_H