#include "Enemigo.h"

Enemigo::Enemigo(float salud, float armadura, float ataque) {
    this->salud = salud;
    this->armadura = armadura;
    this->ataque = ataque;
}

Enemigo::~Enemigo() {

}

float Enemigo::getSalud() {
    return this->salud;
}

float Enemigo::getArmadura() {
    return this->armadura;
}

float Enemigo::getAtaque() {
    return this->ataque;
}
