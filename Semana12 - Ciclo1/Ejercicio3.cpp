#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int ValidarMedallas()
{
    int nmedallas;
    do
    {
        cout << "Ingrese la cantidad de medallas del atleta: "; cin >> nmedallas;
        cin.ignore();
        cout << endl;
    } while (nmedallas < 0);
    return nmedallas;
}

struct datos
{
    char nombre[40];
    char pais[25];
};

struct atleta
{
    char deporte[30];
    datos pers;
    int nmedallas;
};

void IngresarNom(char* nombre)
{
    cout << "Ingrese nombre: ";
    cin.getline(nombre, 40);
}

void IngresarPais(char* pais)
{
    cout << "Ingresar pais: ";
    cin.getline(pais, 25);
}

void IngresarDeporte(char* deporte)
{
    cout << "Ingrese deporte: ";
    cin.getline(deporte, 30);
}

void GenerarAtletas(atleta* ats)
{
    for (int i = 0; i < 30; i++)
    {
        cout << "Atleta: " << i + 1 << ": " << endl;
        IngresarNom(ats[i].pers.nombre);
        IngresarPais(ats[i].pers.pais);
        IngresarDeporte(ats[i].deporte);
        ats[i].nmedallas = ValidarMedallas();
    }
}

void MostrarAtletaMayorNumMedallas(atleta* ats)
{
    atleta mayor = ats[0];
    for (int i = 1; i < 30; i++)
    {
        if (mayor.nmedallas < ats[i].nmedallas)
        {
            mayor.pers = ats[i].pers;
            mayor.nmedallas = ats[i].nmedallas;
            strcpy(mayor.deporte, ats[i].deporte);
        }
    }
    cout << "\tDATOS DEL ATLETA CON MAS MEDALLAS\n";
    cout << "=====================================================\n";
    cout << "Nombre: " << mayor.pers.nombre << endl;
    cout << "Pais: " << mayor.pers.pais << endl;
    cout << "Deporte: " << mayor.deporte << endl;
    cout << "Medallas: " << mayor.nmedallas << endl;
}

int main()
{
    atleta* ats = new atleta[30];

    GenerarAtletas(ats);
    MostrarAtletaMayorNumMedallas(ats);

    delete[] ats;

    system("pause>0");
    return 0;
}