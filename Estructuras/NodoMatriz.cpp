#include <string>

using namespace std;
 

class TareaMatriz{
    public:
        TareaMatriz();
        TareaMatriz(string, string, string, string, string,string ,string, string, string);
        int posi;
        string mes;
        string dia;
        string hora;
        string carnet;
        string Nombre;
        string descripcion;
        string materia;
        string fecha;
        string estado;
};

TareaMatriz::TareaMatriz(){};

TareaMatriz::TareaMatriz(string _mes, string _dia, string _hora, string _carnet,string _nombre, string _descripcion, string _materia, string _fecha, string _estado){
    this->mes = _mes;
    this->dia = _dia;
    this->hora = _hora;
    this->carnet = _carnet;
    this->Nombre = _nombre;
    this->descripcion = _descripcion;
    this->materia = _materia;
    this->fecha = _fecha;
    this->estado = _estado;
};

class NodoMatriz{ 

        public:
            NodoMatriz(TareaMatriz);
            TareaMatriz tarea; 

};

NodoMatriz::NodoMatriz(TareaMatriz _tareaMatriz){
    this->tarea = _tareaMatriz;
}