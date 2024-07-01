#include "pch.h"
#include "iostream"
#include "cmath"

using namespace System;
using namespace std;

struct PuntEsp
{
    double x, y, z;
};

void IngresoDatos(PuntEsp& p1, PuntEsp& p2)
{
    cout << "Ingrese datos del punto 1: " << endl;
    cout << "x: "; cin >> p1.x;
    cout << "y: "; cin >> p1.y;
    cout << "z: "; cin >> p1.z;

    cout << endl << "Ingrese datos del punto 2: " << endl;
    cout << "x: "; cin >> p2.x;
    cout << "y: "; cin >> p2.y;
    cout << "z: "; cin >> p2.z;
}

double DistanciaEntreDosPuntos(PuntEsp& p1, PuntEsp& p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

void ImprimirDistancia(PuntEsp& p1, PuntEsp& p2)
{
    cout << endl << "La distancia entre los puntos es: " << DistanciaEntreDosPuntos(p1, p2);
}

int main()
{
    PuntEsp p1;
    PuntEsp p2;

    IngresoDatos(p1, p2);
    ImprimirDistancia(p1, p2);

    system("pause>0");
    return 0;
}