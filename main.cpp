#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

//Dylan
struct Usuario {
    string nombre, contrasena;
    double saldo;
};

int main() {
    int idioma, opcion, edad, menu, tipoCuentaOpc;
    srand(time(0));
    int numerosecreto = rand() % 100000000;
    float depositar, retirar;
    string nombre, encargado, ssn, tipoCuenta, password, nombreIngresado, contrasenaIngresada, linea;
    bool acceso = false;
   
    //Dylan
    vector<Usuario> usuarios = {
        {"Dylan", "1234", 500000.45},
        {"Yadiel", "abcd", 499999.89},
        {"Yaniel", "pass", 10.56}
    };
    //Yadiel
    cout<<"Seleccione un idioma / Select a language:\n";
    cout<<"1. Español\n2. English\n";
    cin>>idioma;
    cin.ignore();

    switch(idioma) {        
                    //Dylan
                    //ESPAÑOL
        case 1: {
            while(true) {
                cout<<"\n--- MENÚ PRINCIPAL ---\n";
                cout<<"1. Crear cuenta\n";
                cout<<"2. Iniciar sesión\n";
                cout<<"3. Salir\n";
                cin>>opcion;
                cin.ignore();

                switch(opcion) {
                    //Yadiel
                    //Crear Cuenta
                    case 1: {
                        cout<<"Has seleccionado CREAR CUENTA\n\n";
                        cout<<"Ingresa tu nombre completo:\n";
                        getline(cin, nombre);

                        cout<<"Ingresa tu edad:\n";
                        cin>>edad;
                        cin.ignore();

                        if(edad < 18) {
                            cout<<"Eres menor de edad. Ingresa la información del encargado:\n";
                            cout<<"Nombre completo del encargado:\n";
                            getline(cin, encargado);
                        } else {
                            encargado = "N/A";
                        }
                        //Yaniel
                        cout<<"Ingresa tu número de seguro social (9 dígitos):\n";
                        getline(cin, ssn);
                        if(ssn.length() != 9) {
                            cout<<"Debes ingresar solo 9 digitos\n";
                            return 1;
                        }

                        cout<<"Selecciona el tipo de cuenta:\n";
                        cout<<"1. Cheque\n";
                        cout<<"2. Ahorros\n";
                        cin>>tipoCuentaOpc;
                        cin.ignore();

                        switch(tipoCuentaOpc) {
                            case 1: tipoCuenta = "cheque"; break;
                            case 2: tipoCuenta = "ahorros"; break;
                            default:
                                cout<<"Opción inválida";
                                return 1;
                        }
                       
                        cout<<"Crea una contraseña:\n";
                        getline(cin, password);
                        //Yadiel
                        ofstream archivo("cuentas.txt", ios::app);
                        archivo << nombre << "|" << edad << "|" << encargado << "|"
                                << ssn << "|" << tipoCuenta << "|" << password << "\n";
                        archivo.close();

                        cout<<"\nCuenta creada y guardada exitosamente.\n";
                        break;
                    }
                        // LOGIN
                    case 2: {
                        //Dylan
                        acceso = false;

                        cout<<"Introduzca su nombre: ";
                        getline(cin,nombreIngresado);
                        cout<<"\nContrasena: ";
                        cin>>contrasenaIngresada;
                        cin.ignore();
                       
                        // BUSCAR EN VECTOR
                        for (auto& u: usuarios) {
                            if (u.nombre == nombreIngresado && u.contrasena == contrasenaIngresada) {
                                acceso = true;

                                cout<<"Perfecto, "<<nombreIngresado<<" que desea hacer?.\n";
                                cout<<"1. Ver balance\n2. Depositar\n3. Retirar\n";
                                cin>>menu;

                                if (menu == 1)
                                    cout<<"Su balance es de: "<<u.saldo<<"\n";

                                else if (menu == 2) {
                                    cout<<"Cuanto deseas depositar?\n";
                                    cin>>depositar;
                                    cout<<"Numero secreto: "<<numerosecreto<<"\n";
                                }

                                else if (menu == 3) {
                                    cout<<"Cuanto deseas retirar?\n";
                                    cin>>retirar;
                                    cout<<"Numero secreto: "<<numerosecreto<<"\n";
                                }

                                break;
                            }
                        }
                        //Yadiel
                        // BUSCAR EN ARCHIVO
                        if (!acceso) {
                            ifstream archivo("cuentas.txt");

                            while (getline(archivo, linea)) {
                                if (linea.empty()) continue;

                                stringstream ss(linea);
                                vector<string> infoCuentaNueva;
                                string temp;

                                while (getline(ss, temp, '|'))
                                    infoCuentaNueva.push_back(temp);

                                if (infoCuentaNueva.size() >= 6) {
                                    if (infoCuentaNueva[0] == nombreIngresado && infoCuentaNueva[5] == contrasenaIngresada) {
                                        acceso = true;

                                        cout<<"Bienvenido "<<nombreIngresado<<".\n";
                                        cout<<"1. Ver información\n2. Mostrar balance:\n";
                                        cin>>menu;

                                        if (menu == 1) {
                                            cout<<"Edad: "<<infoCuentaNueva[1]<<"\n";
                                            cout<<"Encargado: "<<infoCuentaNueva[2]<<"\n";
                                            cout<<"SSN: "<<infoCuentaNueva[3]<<"\n";
                                            cout<<"Tipo de cuenta: "<<infoCuentaNueva[4]<<"\n";
                                        }
                                        else if (menu == 2) {
                                            cout<<"Su balance es: 0\n";
                                        }

                                        break;
                                    }
                                }
                            }
                            archivo.close();
                        }

                        if (!acceso)
                            cout<<"Nombre o contraseña incorrectos.\n";

                        break;
                    }

                    case 3:
                        cout<<"Saliendo...\n";
                        return 0;

                    default:
                        cout<<"Opción inválida.\n";
                }
            }
        }
        break;

                 //ENGLISH
        case 2: {
            while(true) {
                cout<<"\n--- MAIN MENU ---\n";
                cout<<"1. Create account\n";
                cout<<"2. Log in\n";
                cout<<"3. Exit\n";
                cin>>opcion;
                cin.ignore();

                switch(opcion) {

                    //CREATE ACCOUNT
                    case 1: {
                        cout<<"You selected CREATE ACCOUNT\n\n";

                        cout<<"Enter full name:\n";
                        getline(cin, nombre);

                        cout<<"Enter age:\n";
                        cin>>edad;
                        cin.ignore();

                        if(edad < 18) {
                            cout<<"You are underage. Guardian full name:\n";
                            getline(cin, encargado);
                        } else {
                            encargado = "N/A";
                        }

                        cout<<"Enter SSN (9 digits):\n";
                        getline(cin, ssn);
                        if(ssn.length() != 9) {
                            cout<<"You have to input 9 digits\n";
                            return 1;
                        }
                        cout<<"Select account type:\n";
                        cout<<"1. Checking\n";
                        cout<<"2. Savings\n";
                        cin >>tipoCuentaOpc;
                        cin.ignore();

                        switch(tipoCuentaOpc) {
                            case 1: tipoCuenta = "checking"; break;
                            case 2: tipoCuenta = "savings"; break;
                            default:
                                cout<<"Invalid option";
                                return 1;
                        }

                        cout<<"Create password:\n";
                        getline(cin, password);

                        ofstream archivo("cuentas.txt", ios::app);
                        archivo << nombre << "|" << edad << "|" << encargado << "|"
                                << ssn << "|" << tipoCuenta << "|" << password << "\n";
                        archivo.close();

                        cout<<"\nAccount successfully created.\n";
                        break;
                    }

                    //login
                    case 2: {
                        acceso = false;

                        cout<<"Enter your name: ";
                        cin>>nombreIngresado;
                        cout<<"\nEnter password: ";
                        cin>>contrasenaIngresada;

                        //vector search 
                        for (auto& u: usuarios) {

                            if (u.nombre == nombreIngresado && u.contrasena == contrasenaIngresada) {
                                acceso = true;

                                cout<<"Welcome "<<nombreIngresado<<"!\n";
                                cout<<"1. Balance\n2. Deposit\n3. Withdraw\n";
                                cin>>menu;

                                if (menu == 1)
                                    cout<<"Your balance is: "<<u.saldo<<"\n";

                                else if (menu == 2) {
                                    cout<<"How much to deposit?\n";
                                    cin>>depositar;
                                    cout<<"Secret number: "<<numerosecreto<<"\n";
                                }

                                else if (menu == 3) {
                                    cout<<"How much to withdraw?\n";
                                    cin>>retirar;
                                    cout<<"Secret number: "<<numerosecreto<<"\n";
                                }

                                break;
                            }
                        }

                        // search in file
                        if (!acceso) {
                            ifstream archivo("cuentas.txt");

                            while (getline(archivo, linea)) {
                                if (linea.empty()) continue;

                                stringstream ss(linea);
                                vector<string> infoCuentaNueva;
                                string temp;

                                while (getline(ss, temp, '|'))
                                    infoCuentaNueva.push_back(temp);

                                if (infoCuentaNueva.size() >= 6) {
                                    if (infoCuentaNueva[0] == nombreIngresado && infoCuentaNueva[5] == contrasenaIngresada) {
                                        acceso = true;

                                        cout<<"Welcome "<<nombreIngresado<<"!\n";
                                        cout<<"1. View info\n2. Show account balance:\n";
                                        cin>>menu;

                                        if (menu == 1) {
                                            cout<<"Age: "<<infoCuentaNueva[1]<<"\n";
                                            cout<<"Guardian: "<<infoCuentaNueva[2]<<"\n";
                                            cout<<"SSN: "<<infoCuentaNueva[3]<<"\n";
                                            cout<<"Account type: "<<infoCuentaNueva[4]<<"\n";
                                        }
                                        else if (menu == 2) {
                                            cout<<"Your balance is: 0\n";
                                        }

                                        break;
                                    }
                                }
                            }
                            archivo.close();
                        }

                        if (!acceso)
                            cout<<"Incorrect name or password.\n";

                        break;
                    }

                    case 3:
                        cout<<"Exiting...\n";
                        return 0;

                    default:
                        cout<<"Invalid option.\n";
                }
            }
        }
        break;

        default:
            cout<<"Invalid option.\n";
    }

    return 0;
}
