#include <unistd.h>
#include "MusiPRO.h"
#include <random>
#include <math.h>

MusiPRO::MusiPRO() {

    this->mazmorra1 = *new Mazmorra();
    this->josephAlcalino1 = *new JosephAlcalino();
}

void MusiPRO::menu(){

    string opcion;

    while(true){

        cout << "Bienvenido a MusiPRO: " << "\n";
        cout << "1) Iniciar partida" << "\n";
        cout << "2) Salir" << "\n";
        cin >> opcion;

        if (opcion == "1"){
            Enemigo enemigo = *new Enemigo(50,5,30);
            while(true){
                cout << "1) Informacion" << "\n";
                cout << "2) Investigar siguiente sala" << "\n";
                cout << "3) Volver al menu principal" << "\n";
                cin >> opcion;

                if(opcion == "1"){

                    informaciones(this->josephAlcalino1);

                    cout<< "Volviendo al menu principal..." << endl;
                    sleep(1);
                    continue;
                }
                else if (opcion == "2"){
                    investigarSalaSiguiente(this->josephAlcalino1,enemigo);
                }
                else if(opcion == "3"){
                    cout << "Volviendo al menu principal...";
                    sleep(2);
                    break;

                }
                else{
                    cout << "Ha ingresado una opcion invalida, vuelva a intentarlo nuevamente" << "\n";
                }
            }
        }
        else if (opcion == "2"){
            break;
        }
        else{
            cout << "Ha ingresado una opcion invalida, vuelva a intentarlo";
        }
    }

}
//todo logica de que al pasar al siguiente nivel del arbol se actualizan las estadisticas del joseph

#pragma region Metodos Privados

void MusiPRO::investigarSalaSiguiente(JosephAlcalino josephAlcalino,Enemigo enemigo) {
    Sala* sala = this->mazmorra1.crearSalaYDefinirTipo();
    bool estado = false;
    mazmorra1.agregarRecursivo(sala,this->mazmorra1.getQueue(),estado);

    if (sala->getTipo() == "Caverna"){
        sala->setCantEnemigos(cantEnemigos());
        cout << "Nivel: " << sala->getNivel() << "\n";
        cout << "Sala: " << sala->getNumeroSala() << "\n";
        cout << "Tipo sala: " << sala->getTipo() << "\n";
        cout << "Enemigos: " << sala->getCantEnemigos() << "\n";

        float core;

        core = (josephAlcalino.getSalud() + josephAlcalino.getArmadura() - enemigo.getAtaque()*sala->getCantEnemigos()) - (enemigo.getSalud() * sala->getCantEnemigos() + enemigo.getArmadura() * sala->getCantEnemigos() - josephAlcalino.getAtaque());

        if (core <= 0){
            cout << "\n" << "Core: " << core << "\n";
            cout << "Resultado: Derrota" << "\n";
            cout << "Has muerto!" << "\n";
            cout << "Sala alcanzada :" << sala->getNumeroSala() << "\n";
            cout << "Nivel: " << sala->getNivel() << "\n";
            this->mazmorra1.~Mazmorra();
            //todo destruir a joseph y a TODOS los nodos del arbol (quizas eso solucione todos los problemas de memoria)
        }
        else if (core > 0){
            cout << "Core: " << core << "\n";
            cout << "Resultado: Victoria" << "\n";
            if(sala->getNumeroSala() == pow(2,5)) {
                cout << "¡Felicitaciones!" << "\n";
                cout << "Partida completada" << "\n";
            }
        }
        sala->setEstado(true);//sala recorrida

    }
    else if (sala->getTipo() == "Taberna"){
        cout << "Nivel: " << sala->getNivel() << "\n";
        cout << "Sala: " << sala->getNumeroSala() << "\n";
        cout << "Tipo sala: " << sala->getTipo() << "\n";

        if (incrementoStats() == 0){
            cout << "Armadura +3" << "\n";
            josephAlcalino.setArmadura(josephAlcalino.getArmadura() + 3);
            cout << "Armadura actual: " << josephAlcalino.getArmadura() << "\n";
        }
        else if (incrementoStats() == 1){
            cout << "Salud +5" << "\n";
            josephAlcalino.setSalud(josephAlcalino.getSalud() +5);
            cout << "Salud actual: " << josephAlcalino.getSalud() << "\n";
        }
        else if (incrementoStats() == 2){
            cout << "Ataque +8" << "\n";
            josephAlcalino.setAtaque(josephAlcalino.getAtaque() +8);
            cout << "Ataque actual: " << josephAlcalino.getAtaque() << "\n";
        }
        sala->setEstado(true); //sala recorrida
    }

    //todo tanto si es caverna como taberna, regresar al nodo padre (crear puntero que apunte al padre) y luego ir al hermano, si ambos tienen estado recorridas, pasamos al sigueinte nivel
}

int MusiPRO::cantEnemigos() {
    int cantidadEnemigos;

    random_device rd;
    mt19937 generador(rd());
    discrete_distribution<> distribucion({10,60,25,5});

    switch (distribucion(generador)) {

        case 0: cantidadEnemigos = 3;
            break;
        case 1: cantidadEnemigos = 2;
            break;
        case 2: cantidadEnemigos = 1;
            break;
        case 4: cantidadEnemigos = 400;
            break;
    }
    return cantidadEnemigos;
}

int MusiPRO::incrementoStats() {

    int incrementoStats; // flag 0 si se incrementa armadura +3, flag 1 si se incrementa salud+5 y flag 2 si se incrementa ataque +8

    random_device rd;
    mt19937 generador(rd());
    discrete_distribution<> distribucion({80,15,5});

    switch (distribucion(generador)) {

        case 0:
            incrementoStats = 0;
            break;
        case 1:
            incrementoStats = 1;
            break;
        case 2:
            incrementoStats = 2;
            break;
    }
    return incrementoStats;
}

void MusiPRO::informaciones(JosephAlcalino josephAlcalino) {
    cout << "Informacion del personaje: " << "\n";
    cout << "Salud: " << josephAlcalino.getSalud() << "\n";
    cout << "Armadura: " << josephAlcalino.getArmadura() << "\n";
    cout << "Ataque: " << josephAlcalino.getAtaque() << "\n";
    cout << "Nivel: " << josephAlcalino.getNivel() << "\n";


    cout << "\n" << "Salas recorridas: " << "\n";
    //todo salas recorridas por joseph imprimir arbol de programacion ATS y ver si podemos personalizarlo con lineas y cambiar la orientacion a vertical

}

#pragma endregion Metodos privados

