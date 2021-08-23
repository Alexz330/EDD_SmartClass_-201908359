

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
    id++;
};



class NodeCola {
    public:
        Error  error; 
        NodeCola *Next;
        NodeCola(Error);

};


NodeCola::NodeCola(Error _error){
    
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
       NodeCola *aux;

        aux = adelante;

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