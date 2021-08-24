
#include <iostream>
#include <string>
#include <regex>


using namespace std;

class Tareas {
    public:
        Tareas();
        Tareas(int, string,string,string,string,string,string,string);
        int id;
        string carnet;
        string nombreTarea;
        string descripcion;
        string materia;
        string fecha;
        string hora;
        string estado;
        bool validarHora();
        
     


};
Tareas::Tareas(){

};

Tareas::Tareas(int _id,string _carnet,string _nombreTarea,string _descripcion, string _materia, string _fecha,string _hora,string _estado){
    this->id = _id;
    this->carnet = _carnet;
    this->nombreTarea =_nombreTarea;
    this->descripcion = _descripcion;
    this->materia = _materia;
    this->fecha = _fecha;
    this->hora = _hora;
    this->estado = _estado;
    
    
}


bool Tareas::validarHora(){
    string hora  = this->hora;
    const regex  expresionCorreo("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(hora, expresionCorreo);
}


class NodoDoble
{
public:

    NodoDoble(Tareas);
    void getGraph();
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
        string archivoSalida();
        void getGraph();
   
};


string LIstaDobleEnlazada::archivoSalida(){
    
    string contenido = "";
    string tipoAbierto = "\t¿element type='task'?\n";
    string tipoCerrado  = "\t¿$element?\n";
    NodoDoble *temporal = this->primero;
    while(temporal != NULL){
        cout <<"Nombre de Tarea: "<< temporal->tareas.nombreTarea << endl;
        string carnet = "\t\t¿item Carnet='"+temporal->tareas.carnet+"'?\n"; 
        string nombre = "\t\t¿item Nombre ='"+temporal->tareas.nombreTarea+"'?\n";
        string descripcion = "\t\t¿item Descripcion='"+temporal->tareas.descripcion+"'?\n";
        string materia = "\t\t¿item Materia='"+temporal->tareas.materia+"'?\n";
        string fecha = "\t\t¿item Fecha='"+temporal->tareas.fecha+"'?\n";
        string hora = "\t\t¿item Hora='"+temporal->tareas.hora+"'?\n";
        string estado = "\t\t¿item Estado='"+temporal->tareas.estado+"'?\n";
        contenido += tipoAbierto+carnet+descripcion+materia+fecha+hora+estado+tipoCerrado;  

       
        temporal = temporal->Siguiente;
    }

    return contenido;
}


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
        nodito->Anterior = temporal;

    }
}


void LIstaDobleEnlazada::eliminar(int id){

    if(this->primero ==NULL){
        cout << "Mi loco no hay nada en la lista" <<endl;
    }else{
        NodoDoble *tmp = this->primero;
        while(tmp != NULL){
            if(tmp->tareas.id == id){
                tmp = tmp->Siguiente;
            }else{
                if(tmp->Siguiente != NULL){
                    if(tmp->Siguiente->tareas.id == id){
                        NodoDoble *siguienteT = tmp->Siguiente;
                        tmp->Siguiente = siguienteT->Siguiente;
                        tmp->Siguiente->Anterior = tmp;
                        siguienteT->Siguiente = NULL;
                    }
                }
            }
            tmp = tmp->Siguiente;
        }
    }
    
}

void LIstaDobleEnlazada::imprimir(){

    NodoDoble *temporal = this->primero;
    while(temporal != NULL){
        cout <<"Nombre de Tarea: "<< temporal->tareas.nombreTarea << endl;
        temporal = temporal->Siguiente;
    }
}


void LIstaDobleEnlazada::getGraph(){
    NodoDoble *aux = this->primero;
    string node_data = "";
    string edge_data = "";
    string graph = "digraph List {\nrankdir=LR;\nnode [shape = record, color=blue , style=filled, fillcolor=skyblue];\n";
    int counter = 0;
    while(aux != NULL){
        cout<<aux->tareas.nombreTarea<<endl;
        node_data += "Node" + to_string(counter) + "[label=\"" + aux->tareas.nombreTarea+ "\"];\n";
        if(aux->Anterior!=NULL){
            edge_data += "Node" + to_string(counter-1) + "->Node" + to_string(counter) + ";\n";
            edge_data += "Node" + to_string(counter) + "->Node" + to_string(counter-1) + ";\n";
        }
        counter++;
        aux = aux->Siguiente;
    }
    graph += node_data;
    graph += edge_data;
    graph += "\n}";
    //-------------------------------------
    try{
        //Esta variable debe ser modificada para agregar su path de creacion de la Grafica
        string path = "Path_a_graficar";

        ofstream file;
        file.open(path + "Graph.dot",std::ios::out);

        if(file.fail()){
            exit(1);
        }
        file<<graph;
        file.close();
        string command = "dot -Tpng " + path + "Graph.dot -o  " + path + "Graph.png";
        system(command.c_str());
    }catch(exception e){
        cout<<"Fallo detectado"<<endl;
    }
    //-------------------------------------

    delete aux;
}