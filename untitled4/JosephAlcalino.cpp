#include "JosephAlcalino.h"

JosephAlcalino::JosephAlcalino(float salud, float armadura, float ataque, int nivel) {
    this->salud = salud;
    this->armadura = armadura;
    this->ataque = ataque;
    this->nivel= nivel;
}

JosephAlcalino::JosephAlcalino() {
    this->salud = 100;
    this->armadura = 5;
    this->ataque = 30;
    this->nivel= 1;
}

JosephAlcalino::~JosephAlcalino() {

}

int JosephAlcalino::getNivel() {
    return this->nivel;
}

void JosephAlcalino::setNivel(int nivel) {
    this->nivel = nivel;
}

float JosephAlcalino::getSalud() {
    return this->salud;
}

float JosephAlcalino::getArmadura() {
    return this->armadura;
}

float JosephAlcalino::getAtaque() {
    return this->ataque;
}

void JosephAlcalino::setSalud(float salud) {
    this->salud = salud;
}

void JosephAlcalino::setArmadura(float armadura) {
    this->armadura = armadura;
}

void JosephAlcalino::setAtaque(float ataque) {
    this->ataque = ataque;
}





