#include "Sala.h"
#include <queue>
#include <iostream>
using  namespace std;

class Mazmorra {
private:
    Sala* raiz;
    queue<Sala*> qMazmorra;

public:
    Mazmorra();
    ~Mazmorra();
    void agregarRecursivo(Sala* sala,queue<Sala*>& q,bool& estado);
    void eliminarRecursivo();
    void eliminar(int dato);
    void recorrerRecursivo(Sala* sala);
    void recorridoPorOrden(Sala* raiz);
    Sala* crearSalaYDefinirTipo();
    Sala* crearRaizInicial();
    void destruirArbol(Sala* sala);
    queue<Sala*>& getQueue();

};
