#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

struct Empleado
{
    char nombre[50];
    char sexo;
    double sueldo;
};

int ValidarN()
{
    int N;
    do
    {
        cout << "Ingresa el valor de N: "; cin >> N;
    } while (N < 1);
    return N;
}

void IngresarDatos(Empleado* empleados, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << endl << "Empleado " << i + 1 << ": " << endl;
        cout << "Nombre: "; cin >> empleados[i].nombre;
        cout << "Sexo: "; cin >> empleados[i].sexo;
        cout << "Sueldo: "; cin >> empleados[i].sueldo;
    }
}

void MostrarDatosEmpleadosPedidos(Empleado e)
{
    cout << "Nombre: " << e.nombre << endl;
    cout << "Sexo: " << e.sexo << endl;
    cout << "Sueldo: " << e.sueldo << endl;
    cout << endl;
}

void EmpleadosMayoryMenosSalario(Empleado* empleados, int N)
{
    int posmayorSalario = 0;
    int posmenorSalario = 0;
    for (int i = 1; i < N; i++)
    {
        if (empleados[posmayorSalario].sueldo < empleados[i].sueldo)
        {
            posmayorSalario = i;
        }
        if (empleados[posmenorSalario].sueldo > empleados[i].sueldo)
        {
            posmenorSalario = i;
        }
    }
    cout << endl << "Los datos del empleado con mayor sueldo: " << endl;
    MostrarDatosEmpleadosPedidos(empleados[posmayorSalario]);
    cout << "Los datos del empleado con menor sueldo: " << endl;
    MostrarDatosEmpleadosPedidos(empleados[posmenorSalario]);
}

int main()
{
    srand(time(nullptr));
    int N = ValidarN();
    Empleado* empleados = new Empleado[N];

    IngresarDatos(empleados, N);
    EmpleadosMayoryMenosSalario(empleados, N);

    delete[] empleados;

    system("pause>0");
    return 0;
}