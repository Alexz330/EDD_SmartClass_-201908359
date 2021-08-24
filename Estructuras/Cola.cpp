#include <iostream>
#include <string>
#include <fstream>

using namespace std;



class Error{
    public:
        int id = 0;
        string tipo;
        string descripcion;
        Error(string, string);
        Error();
        
};

Error::Error( ){
    
};

Error::Error(string _tipo, string _descripcion){
    this->tipo = _tipo;
    this->descripcion  = _descripcion;
    this->id++;
};



class NodeCola {
    public:
        Error  error; 
        NodeCola *Next;
        NodeCola(Error);

};


NodeCola::NodeCola(Error _error){
    this->error = _error;
    this->Next = NULL;
};



class Cola{
    public:
        int lenght;
        Error errorsito;
        
        NodeCola *adelante;
        NodeCola *atras;
        
        void encolar(Error);
    
        void desencolar();
        void imprimir();
        void reporteGrafica();
};


void Cola::encolar(Error _errorsito){
    NodeCola *newNodo = new NodeCola( _errorsito);

      if(lenght == 0){
        this->adelante = newNodo;
        this->atras = newNodo;
    }else{
        atras->Next =newNodo;
        atras = newNodo;
    }

    lenght++;
};  




void Cola::imprimir(){
       NodeCola *aux= this->adelante;

        

        while(aux != NULL){
            cout <<aux->error.id <<" Tipo de Error: "<< aux->error.tipo<<endl;
            
            
            aux = aux->Next;
        }
};



void Cola::desencolar(){
    if(!adelante){
        
    }
    if (adelante == atras){
        adelante = NULL;
    }
    adelante = adelante->Next;
    lenght--;
}


void Cola::reporteGrafica(){
    NodeCola *aux = this->adelante;
    string node_data = "";
    string edge_data = "";
    string titulo = "Cola de errores";
    string graph = "digraph List {\nrankdir=LR;\nnode [shape = record, color=yellow , style=filled, fillcolor=skyblue];\n";
    int counter = 0;
    
    while(aux != NULL){
        cout<<aux->error.tipo<<endl;
        node_data += "Node" + to_string(counter) + "[label=\"" + aux->error.tipo+ " " + aux->error.descripcion+"\"];\n";   
        
        counter++;
        aux = aux->Next;
       
    }   

    graph += node_data;
    counter=counter-1;
    while(counter!=0){
        
        edge_data += "Node" + to_string(counter) + "->Node" + to_string(counter-1) + ";\n";
        counter=counter-1;
    }

    graph += edge_data;
   
    graph += "\n}";
 
    try{
       
        string path = "Path_a_graficar";

        ofstream file;
        file.open(path + "Errores.dot",std::ios::out);

        if(file.fail()){
            exit(1);
        }
        file<<graph;
        file.close();
        string command = "dot -Tpng " + path + "Errores.dot -o  " + path + "Errores.png";
        system(command.c_str());
    }catch(exception e){
        cout<<"Se murio"<<endl;
    }
  

}