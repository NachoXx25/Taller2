#pragma once

class Enemigo {

private:
    float salud;
    float armadura;
    float ataque;

public:
    Enemigo(float salud, float armadura, float ataque);
    ~Enemigo();
    float getSalud();
    float getArmadura();
    float getAtaque();

};
