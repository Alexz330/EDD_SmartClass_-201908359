#include <iostream>
#include <string>
#include <regex>

using namespace std;



class Estudiante
{
public:
    Estudiante();
    Estudiante(string, string, string, string, string, string, string, string);
    string No_Carnet;
    string Dpi;
    string nombre;
    string carrera;
    string Correo;
    string Password;
    string Creditos;
    string Edad;
    bool TamanoDPI();
    bool TamanoCarnet();
    bool validacionCorreo();
};

Estudiante::Estudiante()
{
    
}
Estudiante::Estudiante(string _No_Carnet, string _Dpi, string _nombre, string _carrera, string _Password, string _Creditos, string _Edad, string _Correo)
{
    this->No_Carnet = _No_Carnet;
    this->Dpi = _Dpi;
    this->nombre = _nombre;
    this->carrera = _carrera;
    this->Password = _Password;
    this->Creditos = _Creditos;
    this->Edad = _Edad;
    this->Correo = _Correo;
    
};

bool Estudiante::TamanoCarnet(){
        if(this->No_Carnet.length() == 9)
        {
            return true;
        }else{
            return false;
        };
};


bool Estudiante::TamanoDPI(){
        if(this->Dpi.length() == 13){
            return true;
        }else{
            return false;
        };
};


bool Estudiante::validacionCorreo(){
    string correo  = this->Correo;
    const regex  expresionCorreo("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(correo, expresionCorreo);
}


class nodo
{
public:
    
    nodo(Estudiante);
    Estudiante estudiante;
    nodo *Siguiente;
    nodo *Anterior;
};

nodo::nodo(Estudiante _estudiante)
{
    this->estudiante = _estudiante;
    this->Siguiente = NULL;
    this->Anterior = NULL;
};

class ListaCircularDoble
{
public:
    nodo *cabeza;
    nodo *cola;
    int size = 0;

    void insertarInicio(Estudiante estudiante);
    void insertarFinal(Estudiante estudiante);
    void actualizar(Estudiante estudiElim);
    Estudiante Buscar(string);
    void imprimir();
    void Reporte();
    void reporteGrafica();
    void Eliminar(string);
    bool busquedaCarnet(string );
    string archivoSalida();
};


bool ListaCircularDoble::busquedaCarnet(string carnet){

    nodo *aux = this->cabeza;
    int contador = 1;
  
  

    while (aux->estudiante.No_Carnet != carnet && contador != this->size)
    {
        aux = aux->Siguiente;
        contador++;
    };

    if(aux->estudiante.No_Carnet == carnet){
        cout << aux->estudiante.No_Carnet << " fue encontrado exitosamente" << endl;
        return true;
    }else{
        cout << "No se encontro el estudiante "<<endl;
        return false;
    };



};

void ListaCircularDoble::insertarInicio(Estudiante estudiante)
{
    nodo *newNodo = new nodo(estudiante);

    if (cabeza == NULL)
    {
        cabeza = newNodo;
        cola = newNodo;
        size++;
    }
    else if (cabeza != NULL && cola != NULL)
    {
        cabeza->Anterior = newNodo;
        newNodo->Siguiente = cabeza;
        newNodo->Anterior = cola;
        cola->Siguiente = newNodo;
        cabeza = newNodo;
        size++;
    }
};

void ListaCircularDoble::insertarFinal(Estudiante estudiante)
{
    nodo *newNodo = new nodo(estudiante);

    if (this->cabeza == NULL)
    {
        this->cabeza = newNodo;
        this->cola = newNodo;
        this->size++;
    }
    else if (this->cabeza != NULL && this->cabeza != NULL)
    {
        nodo *aux = this->cola;

        aux->Siguiente = newNodo;
        newNodo->Anterior = aux;
        newNodo->Siguiente = this->cabeza;
        this->cabeza->Anterior = newNodo;
        this->cola = newNodo;
        this->size++;
    };
};

void ListaCircularDoble::imprimir()
{
    nodo *aux = this->cabeza;

    while (aux != this->cola)
    {
        cout << "Mi edad es de   : " << aux->estudiante.Edad << endl;
        cout << "Mi mi nombre es  : " << aux->estudiante.nombre << endl;
        aux = aux->Siguiente;
    }

    if (aux == this->cola)
    {
        cout << "Mi edad es de   : " << aux->estudiante.Edad << endl;
        cout << "Mi mi nombre es  : " << aux->estudiante.nombre << endl;
    };
};

void ListaCircularDoble::Reporte()
{
    nodo *aux = this->cabeza;
    cout << "------------USUARIOS REGISTRADOS-----------" << endl;
    while (aux != this->cola)
    {

        cout << "nombre : " << aux->estudiante.nombre << endl;
        aux = aux->Siguiente;
    }

    if (aux == this->cola)
    {

        cout << "nombre : " << aux->estudiante.nombre << endl;
    };
};

Estudiante ListaCircularDoble::Buscar(string DPI){
     nodo *aux = this->cabeza;
    int contador = 1;
  
  

    while (aux->estudiante.Dpi != DPI && contador != this->size)
    {
        aux = aux->Siguiente;
        contador++;
    };

    if(aux->estudiante.Dpi == DPI){
        cout << aux->estudiante.Dpi << " fue encontrado exitosamente" << endl;
        return aux->estudiante;
    }else{
        cout << "No se encontro el estudiante ";
    };

    return Estudiante();

};

void ListaCircularDoble::actualizar(Estudiante estudiElim)
{
    nodo *aux = this->cabeza;
    int contador = 1;
    int opcion;
    string valorModificar;

    while (aux->estudiante.nombre != estudiElim.nombre && contador != this->size)
    {
        aux = aux->Siguiente;
        contador++;
    };

    if (aux->estudiante.Dpi == estudiElim.Dpi)
    {
       

        cout << "Quue valor quieres modificar: " << endl;

        cout << "1. Carnet: " << endl;
        cout << "2. DPI: " << endl;
        cout << "3. Nombre: " << endl;
        cout << "4. Carrera: " << endl;
        cout << "5. Correo: " << endl;
        cout << "6. Password: " << endl;
        cout << "7. Creditos: " << endl;
        cout << "8. Edad: " << endl;

        cin >> opcion;
        
        switch (opcion)
        {
        case 1:

            cout << "Modificar Carnet:" ;
            cin >> valorModificar;

            aux->estudiante.No_Carnet = valorModificar;

            cout << estudiElim.No_Carnet << " fue cambiado exitosamente a " << aux->estudiante.No_Carnet << endl;
            break;
        case 2:
            
            cout << "Modificar DPI:" ;
            cin >> valorModificar;
            aux->estudiante.Dpi = valorModificar;

            cout << estudiElim.Dpi << " fue cambiado exitosamente a " << aux->estudiante.Dpi << endl;
            break;
        case 3:

            cout << "Modificar NOMBRE:" ;
            cin >> valorModificar;
            aux->estudiante.nombre = valorModificar;

            cout << estudiElim.nombre << " fue cambiado exitosamente a " << aux->estudiante.nombre << endl;

            break;
        case 4:
            
            cout << "Modificar carrera:" ;
            cin >> valorModificar;
            aux->estudiante.carrera = valorModificar;

            cout << estudiElim.carrera << " fue cambiado exitosamente a " << aux->estudiante.carrera << endl;
            break;
        case 5:

            cout << "Modificar Correo:" ;
            cin >> valorModificar;

            aux->estudiante.Correo = valorModificar;

            cout << estudiElim.Correo << " fue cambiado exitosamente a " << aux->estudiante.Correo << endl;
            break;
        case 6:
        cout << "Modificar Password:" ;
            cin >> valorModificar;
            aux->estudiante.Password = valorModificar;

            cout << estudiElim.Password << " fue cambiado exitosamente a "<<aux->estudiante.Password<<endl;
            break;
        case 7:

            cout << "Modificar Creditos:" ;
            cin >> valorModificar;
            aux->estudiante.Creditos = valorModificar;

            cout << estudiElim.Creditos << " fue cambiado exitosamente a "<<aux->estudiante.Creditos<<endl;
            break;
        case 8:
            cout << "Modificar edad:" ;
            cin >> valorModificar;
        
            aux->estudiante.Edad = valorModificar;

            cout << estudiElim.Edad << " fue cambiado exitosamente a "<<aux->estudiante.Edad<<endl;
            break;
        };

       
    };
};

void ListaCircularDoble :: Eliminar(string DPI){

    nodo *aux = this->cabeza;
    int contador = 1;

    while(aux->estudiante.Dpi != DPI && contador != this->size){
       aux= aux->Siguiente;
        contador++;
    };



        if(aux->estudiante.Dpi == DPI && aux != this->cabeza){
            //Dato eliminado en Nodo no cabeza
            aux->Anterior->Siguiente = aux->Siguiente;
            aux->Siguiente->Anterior = aux->Anterior;
            aux->Siguiente = NULL;
            aux->Anterior = NULL;
            cout << aux->estudiante.nombre << " fue eliminado con exito"<< endl;
        }else if(aux->estudiante.Dpi == DPI && aux == this->cabeza){
            //Dato eliminado en Nodo Cabeza
            nodo *tmp = aux->Siguiente;
            aux->Anterior->Siguiente = aux->Siguiente;
            aux->Siguiente->Anterior = aux->Anterior;
            aux->Siguiente = NULL;
            aux->Anterior = NULL;
            this->cabeza = tmp;
            cout << aux->estudiante.nombre << " fue eliminado con exito"<< endl;
        }
        if (contador == this->size){
            //Dato no encontrado
            cout << "No se encontro el dato a eliminar"<< endl;
        }


};


void ListaCircularDoble::reporteGrafica(){
    nodo *aux = this->cabeza;
    string node_data = "";
    string edge_data = "";
    string graph = "digraph List {\nrankdir=LR;\nnode [shape = record, color=yellow , style=filled, fillcolor=red];\n";
    int counter = 0;
    while(aux != this->cola){
        cout<<aux->estudiante.nombre<<endl;
        node_data += "Node" + to_string(counter) + "[label=\"" + aux->estudiante.nombre+ "\"];\n";
        if(aux->Anterior!=this->cola){
            edge_data += "Node" + to_string(counter-1) + "->Node" + to_string(counter) + ";\n";
            edge_data += "Node" + to_string(counter) + "->Node" + to_string(counter-1) + ";\n";
        }
        counter++;
        aux = aux->Siguiente;

    }
    
    graph += node_data;
    graph += "Node0-> Node"+to_string(counter-1)+ ";\n"; 
    graph += edge_data;
    graph += "Node"+to_string(counter-1)+"->Node0;\n"; 
    graph += "\n}";
   
    try{
       
        string path = "Path_a_graficar";

        ofstream file;
        file.open(path + "Estudiantes.dot",std::ios::out);

        if(file.fail()){
            exit(1);
        }
        file<<graph;
        file.close();
        string command = "dot -Tpng " + path + "Estudiantes.dot -o  " + path + "Estudiantes.png";
        system(command.c_str());
    }catch(exception e){
        cout<<"se murio"<<endl;
    }
    //-------------------------------------

    delete aux;
}

string ListaCircularDoble::archivoSalida(){
    
    string contenido = "";
    string tipoAbierto = "\t??element type='user'?\n";
    string tipoCerrado  = "\t??$element?\n";
    nodo *aux = this->cabeza;
    while(aux != this->cola){
       
        string carnet = "\t\t??item Carnet='"+aux->estudiante.No_Carnet+"'?\n"; 
        string dpi = "\t\t??item DPI='"+aux->estudiante.Dpi+"'?\n"; 
        string nombre = "\t\t??item Nombre ='"+aux->estudiante.nombre+"'?\n";
        string carrera = "\t\t??item Carrera='"+aux->estudiante.carrera+"'?\n";
        string Password = "\t\t??item Password='"+aux->estudiante.Password+"'?\n";
        string creditos = "\t\t??item Creditos='"+aux->estudiante.Creditos+"'?\n";
        string edad = "\t\t??item Edad='"+aux->estudiante.Edad+"'?\n";
        
        contenido += tipoAbierto+carnet+dpi+nombre+carrera+Password+creditos+edad+tipoCerrado;  

       
        aux = aux->Siguiente;
    }

      if (aux == this->cola)
    {
        string carnet = "\t\t??item Carnet='"+aux->estudiante.No_Carnet+"'?\n"; 
        string dpi = "\t\t??item DPI='"+aux->estudiante.Dpi+"'?\n"; 
        string nombre = "\t\t??item Nombre ='"+aux->estudiante.nombre+"'?\n";
        string carrera = "\t\t??item Carrera='"+aux->estudiante.carrera+"'?\n";
        string Password = "\t\t??item Password='"+aux->estudiante.Password+"'?\n";
        string creditos = "\t\t??item Creditos='"+aux->estudiante.Creditos+"'?\n";
        string edad = "\t\t??item Edad='"+aux->estudiante.Edad+"'?\n";
        
        contenido += tipoAbierto+carnet+dpi+nombre+carrera+Password+creditos+edad+tipoCerrado;  
    };



    return contenido;
}



   