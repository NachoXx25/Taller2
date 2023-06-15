#include "Sala.h"

Sala::Sala() {
    this->nivel = 1;
    this->estado = false;
    this->numeroSala = 1;
    this->cantEnemigos = 0;
    this->tipo = "";
    this->statAdquirida = "";
    this->hijoDerecho = nullptr;
    this->hijoIzquierdo = nullptr;

}
Sala::Sala(Sala *hijoIzquierdo, Sala *hijoDerecho) {
    this->hijoIzquierdo = hijoIzquierdo;
    this->hijoDerecho = hijoDerecho;
}

Sala::Sala(string tipo) {
    if(tipo == "Caverna" || tipo == "Taberna"){
        this->tipo = tipo;
    }else {
        throw ("EL tipo ingresado no es valido");
    }
}

Sala::~Sala() {
    hijoDerecho = nullptr;
    hijoIzquierdo = nullptr;
}

string Sala::getTipo() {
    return this->tipo;
}

void Sala::setTipo(string tipo) {
    this->tipo = tipo;
}

Sala* Sala::getHijoIzquierdo() {
    return this->hijoIzquierdo;
}

void Sala::setHijoIzquierdo(Sala *hijoIzq) {
    this->hijoIzquierdo = hijoIzq;
}

Sala *Sala::getHijoDerecho() {
    return this->hijoDerecho;
}

void Sala::setHijoDerecho(Sala *hijoDer) {
    this->hijoDerecho = hijoDer;
}

void Sala::incrementarEstadistica(JosephAlcalino josephAlcalino) {
    return;
}

bool Sala::getEstado() {
    return this->estado;
}

void Sala::setEstado(bool estado) {
    this->estado = estado;
}

int Sala::getNivel() {
    return this->nivel;
}

void Sala::setNivel(int nivel) {
    this->nivel = nivel;
}

int Sala::getNumeroSala() {
    return this->numeroSala;
}

void Sala::setNumeroSala(int numeroSala) {
    this->numeroSala = numeroSala;
}

int Sala::getCantEnemigos() {
    return this->cantEnemigos;
}

void Sala::setCantEnemigos(int cantEnemigos) {
    this->cantEnemigos = cantEnemigos;
}