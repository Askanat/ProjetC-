#ifndef SOMMET_H
#define SOMMET_H
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <list>

using namespace std;

class Sommet
{
private:
	int nb_arc;
    int id;
    list<int> *poids;

public:

	Sommet();

    Sommet(int _id, int size);

    Sommet(int _id, list<int> *_p);

    ~Sommet();

    int getId();

    list<int>* getPoidsVoisins();

    void setArete(int nb_arc, int poids);

    void delArete(int *nb_arc);

    int getArcNb();

    void delSommet(int *id);
};

#endif //SOMMET_H