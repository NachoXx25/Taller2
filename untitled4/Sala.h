#include <string>
#include "JosephAlcalino.h"
using namespace std;

class Sala {

private:
    string tipo;
    bool estado;
    int nivel;
    int numeroSala;
    int cantEnemigos;
    string statAdquirida;
    Sala* hijoIzquierdo;
    Sala* hijoDerecho;

public:
    Sala();
    Sala(Sala* hijoIzquierdo, Sala* hijoDerecho);
    Sala(string tipo);
    ~Sala();
    string getTipo();
    void setTipo(string tipo);
    bool getEstado();
    void setEstado(bool estado);
    int getNivel();
    void setNivel(int nivel);
    int getCantEnemigos();
    void setCantEnemigos(int cantEnemigos);
    int getNumeroSala();
    void setNumeroSala(int numeroSala);
    Sala* getHijoIzquierdo();
    void setHijoIzquierdo(Sala* hijoIzq);
    Sala* getHijoDerecho();
    void setHijoDerecho(Sala* hijoDer);
    void incrementarEstadistica (JosephAlcalino josephAlcalino);

};


