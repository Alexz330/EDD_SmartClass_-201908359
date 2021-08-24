

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
};



class Cola{
    public:
        int lenght;
        Error errorsito;
        
        NodeCola * adelante;
        NodeCola *atras;
        
        void encolar(Error);
    
        void desencolar();
        void imprimir();
        void getGraph();
};


void Cola::encolar(Error _errorsito){
    NodeCola *newNodo = new NodeCola( _errorsito);

      if(lenght == 0){
        adelante = newNodo;
        atras = newNodo;
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


void Cola::getGraph(){
    NodeCola *aux = this->adelante;
    string node_data = "";
    string edge_data = "";
    string graph = "digraph List {\nrankdir=LR;\nnode [shape = record, color=yellow , style=filled, fillcolor=red];\n";
    int counter = 0;
    int contador  = 0;
    while(contador != this->lenght){
        cout<<aux->error.tipo<<endl;
        node_data += "Node" + to_string(counter) + "[label=\"" + aux->error.tipo+ "\"];\n";
      
            cout<<"hola perro"<<endl;
            edge_data += "Node" + to_string(counter-1) + "->Node" + to_string(counter) + ";\n";
            edge_data += "Node" + to_string(counter) + "->Node" + to_string(counter-1) + ";\n";
            contador++;
        
        counter++;
        aux = aux->Next;

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