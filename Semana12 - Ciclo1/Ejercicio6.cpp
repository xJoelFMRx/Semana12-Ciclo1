#include "pch.h"
#include "iostream"
#include "cmath"

using namespace System;
using namespace std;

struct cuadrado
{
    double lado;
};

struct triangulo
{
    double base, altura;
};

void IngresarDatos(triangulo& t, cuadrado& c)
{
    cout << "Ingrese los datos del cuadrado: " << endl;
    cout << "Lado: "; cin >> c.lado;
    cout << endl;
    cout << "Ingrese los datos del triangulo: " << endl;
    cout << "Base: "; cin >> t.base;
    cout << "Altura: "; cin >> t.altura;
}

double AreaCuadrado(cuadrado& c)
{
    return c.lado * c.lado;
}

double AreaTriangulo(triangulo& t)
{
    return (t.base * t.altura) / 2;
}

void ImprimirAreas(triangulo& t, cuadrado& c)
{
    cout << endl << "El area del cuadrado es: " << AreaCuadrado(c) << endl;
    cout << "El area del triangulo es: " << AreaTriangulo(t);
}

int main()
{
    cuadrado c;
    triangulo t;

    IngresarDatos(t, c);
    ImprimirAreas(t, c);

    system("pause>0");
    return 0;
}