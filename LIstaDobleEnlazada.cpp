#include <iostream>
#include <string>


using namespace std;

class Tareas {
    public:
        Tareas();
        Tareas(string,string,string,string,string,string,string);
        int id = 0;
        string carnet;
        string nombreTarea;
        string descripcion;
        string materia;
        string fecha;
        string hora;
        string estado;

        


};
Tareas::Tareas(){

};

Tareas::Tareas(string _carnet,string _nombreTarea,string _descripcion, string _materia, string _fecha,string _hora,string _estado){
    this->carnet = _carnet;
    this->nombreTarea =_nombreTarea;
    this->descripcion = _descripcion;
    this->materia = _materia;
    this->fecha = _fecha;
    this->hora = _hora;
    this->estado = _estado;
    
    id++;
}



class NodoDoble
{
public:

    NodoDoble(Tareas);
    Tareas tareas;
    NodoDoble *Siguiente;
    NodoDoble *Anterior;
};

NodoDoble::NodoDoble(Tareas _tareas)
{
    this->tareas = _tareas;
    this->Siguiente = NULL;
    this->Anterior = NULL;
};



class LIstaDobleEnlazada
{


    public:

        NodoDoble *primero = NULL;
        NodoDoble *ultimo = NULL;
        void agregarInicio(Tareas);
        void agregarFinal(Tareas);
        void eliminar(int _id);
        void imprimir();
   
};


void  LIstaDobleEnlazada::agregarInicio(Tareas tarea){
    NodoDoble *nodito =  new NodoDoble(tarea);

    NodoDoble *temporal =  this->primero;
    
    if (this->primero == NULL){
        this->primero = nodito;
    } else{
        nodito->Siguiente = this->primero;
        this->primero->Anterior = nodito;
        this->primero = nodito;
    }

};


void LIstaDobleEnlazada::agregarFinal(Tareas tarea){
    NodoDoble *temporal =  this->primero;

    NodoDoble *nodito =  new NodoDoble(tarea);

    if(this->primero == NULL){
        this->primero = nodito;
    }else{
        while(temporal->Siguiente!= NULL ){
            temporal = temporal->Siguiente;
        }

        temporal->Siguiente = nodito;
        nodito->Siguiente = temporal;

    }
}


void LIstaDobleEnlazada::eliminar(int id){

    // if(this->primero ==NULL){
    //     cout << "Mi loco no hay nada en la lista" <<endl;
    // }else{
    //     nodo *tmp = this->primero;
    //     while(tmp != NULL){
    //         if(tmp->tareas.id == id){
    //             tmp = tmp->Siguiente;
    //         }else{
    //             if(tmp->Siguiente != NULL){
    //                 if(tmp->Siguiente->tareas.id == id){
    //                     nodo *siguienteT = tmp->Siguiente;
    //                     tmp->Siguiente = siguienteT->Siguiente;
    //                     tmp->Siguiente->Anterior = tmp;
    //                     siguienteT->Siguiente = NULL;
    //                 }
    //             }
    //         }
    //         tmp = tmp->Siguiente;
    //     }
    // }
    
}

void LIstaDobleEnlazada::imprimir(){

    NodoDoble *temporal = this->primero;
    while(temporal != NULL){
        cout <<"Nombre de Tarea: "<< temporal->tareas.nombreTarea << endl;
        temporal = temporal->Siguiente;
    }
}