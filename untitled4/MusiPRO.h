#include <string>
#include <iostream>
#include "Mazmorra.h"
#include "Enemigo.h"
using namespace std;


class MusiPRO {

private:
    Mazmorra mazmorra1;
    JosephAlcalino josephAlcalino1;
    int cantEnemigos();
    void investigarSalaSiguiente(JosephAlcalino josephAlcalino,Enemigo enemigo);
    int incrementoStats();
    static void informaciones(JosephAlcalino josephAlcalino);

public:
    MusiPRO();
    void menu();
};