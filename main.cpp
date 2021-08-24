#include <iostream>
#include <sstream>
#include <fstream>
#include "Estructuras/ListaCircularDoble.cpp"
#include "Estructuras/LIstaDobleEnlazada.cpp"
#include "Estructuras/NodoMatriz.cpp"
#include "Estructuras/Cola.cpp"

#define ruta_Estudiantes "Estudiantes.csv"
#define ruta_Tareas "Tareas.csv"




using namespace std;



int GetIndiceMes(string _mesesito){
    switch (stoi(_mesesito))
    {
    case 7:   
        return 0;
    
    case 8:
        return 1;
    case 9:
        return 2;
    case 10:
        return 3;
    case 11:
        return 4;
    default: 
        return -1;
    }
}


int GetIndiceHora(string _dia){
    switch (stoi(_dia))
    {
    case 8:   
        return 0;
    
    case 9:
        return 1;
    case 10:
        return 2;
    case 11:
        return 3;
    case 12:
        return 4;
    case 13:
        return 5;
    case 14:
        return 6;
    case 15:
        return 7;
    case 16:
        return 8;
    default: 
        return -1;
    }
}


void menu()
{
    cout << "\n\t MENU \n\n";
    cout << " 1. Cargar Usuarios                              " << endl;
    cout << " 2. Cargar Tareas                            " << endl;
    cout << " 3. Ingreso manual                          " << endl;
    cout << " 4. Reportes                           " << endl;
    cout << " 5. Modificar Estudiante" << endl;
    cout << " 7. Salir                           " << endl;
    cout << "\n INGRESE OPCION: ";
}

void menuManual()
{
    cout << "\n\t SELECCIONE OBJETO A INGRESAR \n\n";
    cout << " 1. Usuarios                             " << endl;
    cout << " 2. Tareas                           " << endl;
    cout << " 3. salir                          " << endl;

    cout << "\n INGRESE OPCION: ";
}



void reportes()
{
    cout << "\n\t SELECCIONE OBJETO A INGRESAR \n\n";
    cout << " 1. Estudiantes                             " << endl;
    cout << " 2. Tareas                           " << endl;
    cout << " 3. salir                          " << endl;

    cout << "\n INGRESE OPCION: ";
}

int main()
{
    //variable para la opciones del menu principal
    int op;
    int opIngreso;

    // Variables de entrada por el usuario
    string Usu_Carnet, Usu_DPI, Usu_Nombre, Usu_Carrera, Usu_Password, Usu_Creditos, Usu_Edad, Usu_Correo;
    Estudiante estudianteIngresado;

    // Variable de entra para Tareas ingresadas por el usuario

    string T_carnet, T_nombre, T_descripcion, T_materia, T_fecha, T_hora, T_estado;
    Tareas tareasIngresadas;

    //variable para buscar mediante el DPI del estudiante;
    string DPI;
    Estudiante estidanteBuscado;

    
    //variable para buscar mediante el DPI del estudiante;
    string indice_tarea;
   

    //varaibles para carga masiva de usuarios
    ifstream archivo(ruta_Estudiantes);
    string linea;
    char delimitador = ',';

    //varaibles para carga masiva de tareas
    string Mes_Tarea, Dia_Tarea, Hora_Tarea, Carnet_Tarea, Nombre_Tarea, Descripcion_Tarea, Materia_Tarea, Fecha_Tarea,Estado_tarea; 

    int id_tarea = 0;

    ifstream archivo_tareas(ruta_Tareas);
    string linea_Tareas;

    //lista circular
    ListaCircularDoble listita = ListaCircularDoble();

    //lista doble enlazada
    LIstaDobleEnlazada listitaDoble = LIstaDobleEnlazada();

    // Cola de erroes 
    Cola colita =  Cola();


    //matriz 

    NodoMatriz *matricita[5][30][9];

    // opcion reportes

    int opcionReporte;

    for(int i =0; i<5; i++){
        for(int j = 0; j<30; j++){
            for(int k = 0; k<9; k++){
                matricita[i][j][k] = NULL;
            }   
        }
    };


    do
    {
        menu();
        cin >> op;

        switch (op)
        {
        case 1:

            getline(archivo, linea);

            while (getline(archivo, linea))
            {

                stringstream stream(linea);
                string Carnet, DPI, Nombre, Carrera, Password, Creditos, Edad, Correo;
                

                getline(stream, Carnet, delimitador);
                getline(stream, DPI, delimitador);
                getline(stream, Nombre, delimitador);
                getline(stream, Carrera, delimitador);
                getline(stream, Password, delimitador);
                getline(stream, Creditos, delimitador);
                getline(stream, Edad, delimitador);
                getline(stream, Correo, delimitador);


                Estudiante estudiante = Estudiante(Carnet, DPI, Nombre, Carrera, Password, Creditos, Edad, Correo);
                
                if(estudiante.TamanoCarnet() && estudiante.TamanoDPI() && estudiante.validacionCorreo() ){
                     listita.insertarFinal(estudiante);

                }else if(!estudiante.TamanoCarnet()){

                    cout << "Error, tamano de carnet invalido"<<endl;
                    Error erroristo = Error("Estudiante","tamano de carnet invalido");
                    colita.encolar(erroristo);
                }else if(!estudiante.TamanoDPI()){

                    cout << "Error,tamano de dpi invalido"<<endl;
                    Error erroristo = Error("Estudiante","tamano de dpi invalido");
                    colita.encolar(erroristo);
                
                }else if(!estudiante.validacionCorreo() ){

                    cout << "Error, formato de correo invalido"<<endl;
                    Error erroristo = Error("Estudiante","formato de correo invalido");
                    colita.encolar(erroristo);
                    
                }


                
            }
            listita.Reporte();

            archivo.close();
            break;

        case 2:

            getline(archivo_tareas,linea_Tareas);

           
            while (getline(archivo_tareas,linea_Tareas))
            {
                stringstream stream(linea_Tareas);
                

                getline(stream, Mes_Tarea, delimitador);
                getline(stream, Dia_Tarea, delimitador);
                getline(stream, Hora_Tarea, delimitador);
                getline(stream, Carnet_Tarea, delimitador);
                getline(stream, Nombre_Tarea, delimitador);
                getline(stream, Descripcion_Tarea, delimitador);
                getline(stream, Materia_Tarea, delimitador);
                getline(stream, Fecha_Tarea, delimitador);
                getline(stream, Estado_tarea, delimitador);

                TareaMatriz tareita =  TareaMatriz(Mes_Tarea, Dia_Tarea, Hora_Tarea, Carnet_Tarea, Nombre_Tarea, Descripcion_Tarea, Materia_Tarea, Fecha_Tarea, Estado_tarea);  

                matricita[GetIndiceMes(Mes_Tarea)][stoi(Dia_Tarea)-1][GetIndiceHora(Hora_Tarea)] = new NodoMatriz(tareita); 

            }



                
                
                for(int i =0; i<5; i++){
                    for(int j = 0; j<9; j++){
                        for(int k = 0; k<30; k++){
                            if(matricita[i][k][j] != NULL){

                                int indice = j+30*(k+9*i);
                                
                                Tareas tareaMasiva = Tareas(indice,matricita[i][k][j]->tarea.carnet,matricita[i][k][j]->tarea.Nombre,matricita[i][k][j]->tarea.descripcion,matricita[i][k][j]->tarea.materia,matricita[i][k][j]->tarea.fecha,matricita[i][k][j]->tarea.hora,matricita[i][k][j]->tarea.estado);
                                 if(listita.busquedaCarnet(matricita[i][k][j]->tarea.carnet) ){
                                    listitaDoble.agregarInicio(tareaMasiva);
                                }

                                
                            }
                        }   
                    }
                    
                };
                cout <<"linealizacion ready"<<endl;
               listitaDoble.imprimir();
               
            
            break;

        case 3:
            menuManual();

            cin >> opIngreso;

            switch (opIngreso)
            {
            case 1:
                cout << "Intruduce un No.Carnet: " << endl;
                cin >> Usu_Carnet;
                
                cout << "Intruduce el  No.Dpi: " << endl;
                cin >> Usu_DPI;

                cout << "Intruduce un Nombre: " << endl;
                cin.ignore();
                getline(cin, Usu_Nombre);

                cout << "Intruduce una Carrera: " << endl;
                cin.ignore();
                getline(cin, Usu_Carrera);

                cout << "Intruduce un Correo: " << endl;
                cin >> Usu_Correo;

                cout << "Intruduce una Password: " << endl;
                cin >> Usu_Password;

                cout << "Intruduce cantidad de Creditos: " << endl;
                cin >> Usu_Creditos;

                cout << "Intruduce la Edad: " << endl;
                cin >> Usu_Edad;

                estudianteIngresado = Estudiante(Usu_Carnet, Usu_DPI, Usu_Nombre, Usu_Carrera, Usu_Correo, Usu_Password, Usu_Creditos, Usu_Edad);

                  if(estudianteIngresado.TamanoCarnet() && estudianteIngresado.TamanoDPI() && estudianteIngresado.validacionCorreo() ){
                     listita.insertarFinal(estudianteIngresado);
                }else if(!estudianteIngresado.TamanoCarnet()){
                    cout << "Error, tamano de carnet invalido"<<endl;
                    Error erroristo = Error("Estudiante","tamano de carnet invalido");
                    colita.encolar(erroristo);
                }else if(!estudianteIngresado.TamanoDPI()){
                    cout << "Error,tamano de dpi invalido"<<endl;
                    Error erroristo = Error("Estudiante","tamano de dpi invalido");
                    colita.encolar(erroristo);
                }else if(!estudianteIngresado.validacionCorreo() ){
                    cout << "Error, formato de correo invalido"<<endl;
                    Error erroristo = Error("Estudiante","formato de correo invalido");
                    colita.encolar(erroristo);
                }
               

                
                system("pause");
                break;
            case 2:
                cout << "Intruduce un No.Carnet: " << endl;
                cin >> T_carnet;
                getline(cin, T_carnet);

                cout << "Intruduce el Nombre de la tarea : " << endl;
                getline(cin, T_nombre);

                cout << "Intruduce descripcion: " << endl;
                getline(cin, T_descripcion);

                cout << "Intruduce la materia: " << endl;
                getline(cin, T_materia);

                cout << "Intruduce la fecha: " << endl;
                getline(cin, T_fecha);

                cout << "Intruduce la hora : " << endl;
                getline(cin, T_hora);

                cout << "Intruduce el estado de la materia: " << endl;
                getline(cin, T_estado);

                tareasIngresadas = Tareas(0, T_carnet, T_nombre, T_descripcion, T_materia, T_fecha, T_hora, T_estado);

                if (listita.busquedaCarnet(T_carnet))
                {
                    listitaDoble.agregarInicio(tareasIngresadas);
                }
                else
                {   
                    string tipo = "Tarea";
                    Error errorsito = Error(tipo,T_descripcion );
                    colita.encolar(errorsito);
                }

                listita.insertarFinal(estudianteIngresado);

                listita.imprimir();

                break;
            }

            break;

        case 4:
                reportes();
                cin >> opcionReporte;
                switch (opcionReporte)
                {
                case 1:
                    listita.getGraph();
                    break;
                
                case 2:
                    listitaDoble.getGraph();
                    break;
                case 3:
                    colita.getGraph();
                    break;
                }  
            
            break;
        case 5:
            cout << "ingrese el numero del DPI para modificar" << endl;

            cin >> DPI;

            estidanteBuscado = listita.Buscar(DPI);

            listita.actualizar(estidanteBuscado);
            system("pause");
            break;

        case 6:

            cout << "ingrese el numero de indice para modificar la tarea";
            cin >> indice_tarea;

            break;
        
        }

        cout << endl
             << endl;

    } while (op != 7);

    return 0;
}