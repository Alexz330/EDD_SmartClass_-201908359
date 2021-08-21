#include <iostream>
#include <sstream>
#include <fstream>
#include "ListaCircularDoble.cpp"
#include "ListaDobleEnlazada.cpp"
#define NOMBRE_ARCHIVO "Estudiantes.csv"
using namespace std;

void menu()
{
    cout << "\n\t MENU \n\n";
    cout << " 1. Cargar Usuarios                              " << endl;
    cout << " 2. Cargar Tareas                            " << endl;
    cout << " 3. Ingreso manual                          " << endl;
    cout << " 4. Reportes                           " << endl;
    cout << " 5. Modificar Estudiante" << endl;
    cout << " 6. Salir                           " << endl;
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

    //varaibles para carga masiva de usuarios
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ',';

    ListaCircularDoble listita = ListaCircularDoble();
    LIstaDobleEnlazada listitaDoble = LIstaDobleEnlazada();

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


                Estudiante estudiante = Estudiante(Carnet, DPI, Nombre, Carrera, Correo, Password, Creditos, Edad);

                if(estudiante.TamanoCarnet() && estudiante.TamanoDPI() && estudiante.validacionCorreo()){
                     listita.insertarFinal(estudiante);
                }else{
                    cout << "correo invalido"<<endl;
                }

                
            }
            listita.Reporte();

            archivo.close();
            break;

        case 2:

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

                if(estudianteIngresado.TamanoCarnet() && estudianteIngresado.TamanoDPI() && estudianteIngresado.validacionCorreo()){
                     listita.insertarFinal(estudianteIngresado);
                }else{
                    cout << "error al ingresar usuario"<<endl;
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

                tareasIngresadas = Tareas(T_carnet, T_nombre, T_descripcion, T_materia, T_fecha, T_hora, T_estado);

                if (listita.busquedaCarnet(T_carnet))
                {
                    listitaDoble.agregarInicio(tareasIngresadas);
                }
                else
                {
                    cout << "No se pudo agregar la tarea";
                }

                listita.insertarFinal(estudianteIngresado);

                listita.imprimir();

                break;
            }

            break;

        case 4:
            listita.Reporte();
            break;
        case 5:
            cout << "ingrese el numero del DPI para modificar" << endl;

            cin >> DPI;

            estidanteBuscado = listita.Buscar(DPI);

            listita.actualizar(estidanteBuscado);
            system("pause");
            break;

        case 6:
            break;
        }

        cout << endl
             << endl;

    } while (op != 6);

    return 0;
}