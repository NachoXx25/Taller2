#include <random>
#include "Mazmorra.h"

Mazmorra::Mazmorra() {
    this->raiz = new Sala();

    this->qMazmorra = *new queue<Sala*>;

    this->qMazmorra.push(this->raiz);
    this->qMazmorra.push(this->raiz);
}

Mazmorra::~Mazmorra() {
    destruirArbol(this->raiz);
}


void Mazmorra::agregarRecursivo(Sala* sala,queue<Sala*>& q,bool& estado) { //TODO: validar que no se pueden agregar salas sobre el nivel 5.
    if(!estado){
        Sala* aux = q.front();
        if(aux->getHijoIzquierdo() != nullptr && aux->getHijoDerecho() != nullptr){
            q.pop();
            agregarRecursivo(sala,q,estado);
        }
        else if(aux->getHijoIzquierdo() != nullptr && aux->getHijoDerecho() == nullptr){
            q.pop();
            aux->setHijoDerecho(sala);
            q.push(sala);
            q.push(sala);
            estado = true;
            agregarRecursivo(sala,q,estado);
        }
        else if(aux->getHijoIzquierdo() == nullptr && aux->getHijoDerecho() == nullptr){
            q.pop();
            aux->setHijoIzquierdo(sala);
            q.push(sala);
            q.push(sala);
            estado = true;
            agregarRecursivo(sala,q,estado);
        }
    }
    return;
}


void Mazmorra::eliminarRecursivo() {



}

void Mazmorra::eliminar(int dato) {
    return;
}

void Mazmorra::recorrerRecursivo(Sala *sala) {
    return;
}

void Mazmorra::recorridoPorOrden(Sala * raiz) {//todo teoricamente hablando si creamos una instancia de arbol, y le entregamos la raiz a este metodo, este metodo es capaz de ir imprimiendo por orden cada tipo de nodo que ya esta recorrido

    if (raiz == nullptr){ //todo en funcion el numero de la sala, de manera generica hacer que si el jugdor llega al siguiente nivel, se incrementen sus stats
        return;
    }

    queue<Sala*> queue1;
    queue1.push(raiz);

    Sala* actual;

    while (!queue1.empty()){
        actual = queue1.front();
        queue1.pop();
        if (actual->getEstado()){//si el estado es true, quiere decir que fue recorrida //todo idear manera que imprima como arbol de manera generalizada

            cout << actual->getNivel() << " "; // se imprime su nivel si es que fue recorrida

            if (actual->getHijoIzquierdo()){ //se insertan sus  hijos al queue
                queue1.push(actual->getHijoIzquierdo());
            }
            if (actual->getHijoDerecho()){
                queue1.push(actual->getHijoDerecho());
            }
        }

    }


}

Sala *Mazmorra::crearSalaYDefinirTipo() {
    Sala* sala = new Sala();
    random_device rd;
    mt19937 generador(rd());
    discrete_distribution<> distribucion({80,20});

    switch (distribucion(generador)) {
        case 0:
            sala->setTipo("Caverna");
            break;
        case 1:
            sala->setTipo("Taberna");
            break;
    }
    return sala;
}

Sala *Mazmorra::crearRaizInicial() {
    Sala* raiz = new Sala();
    return raiz;
}

void Mazmorra::destruirArbol(Sala *sala) {
    if(sala != nullptr){
        destruirArbol(sala->getHijoIzquierdo());
        destruirArbol(sala->getHijoDerecho());
        delete sala;
    }
}

queue<Sala*>& Mazmorra::getQueue() {
    return this->qMazmorra;
}
