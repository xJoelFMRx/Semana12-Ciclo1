#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

//Si deseara montos flotantes
//float RandFloat(float min, float max)
//{
//    return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (max - min);
//}

int ValidarN()
{
    int N;
    do
    {
        cout << "Ingrese el valor de N: "; cin >> N;
    } while (N < 1 || N > 200);
    return N;
}

struct Encuestados
{
    double monto;
    char genero;
    int edad;
};

char GeneroPersona[2] = { 'F', 'M' };

void GenerarDatos(Encuestados* encuestado, int N)
{
    for (int i = 0; i < N; i++)
    {
        encuestado[i].genero = GeneroPersona[RandInt(0, 1)];
        encuestado[i].edad = RandInt(15, 50);
        encuestado[i].monto = RandInt(25, 500);
    }
}

void MostrarDatos(Encuestados* encuestado, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << endl << "Encuestado " << i + 1 << ": " << endl;
        cout << "Monto: " << encuestado[i].monto << endl;
        cout << "Edad: " << encuestado[i].edad << endl;
        cout << "Genero: " << encuestado[i].genero << endl;
    }
}

bool Comparar(Encuestados encuestado1, Encuestados encuestado2)
{
    if (encuestado1.genero > encuestado2.genero)
    {
        return true;
    }
    else if (encuestado1.genero == encuestado2.genero)
    {
        if (encuestado1.monto > encuestado2.monto)
        {
            return true;
        }
    }
    return false;
}


void OrdenadoAscendentementeGeneroyMonto(Encuestados* encuestado, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (Comparar(encuestado[i], encuestado[j]))
            {
                Encuestados temp = encuestado[i];
                encuestado[i] = encuestado[j];
                encuestado[j] = temp;
            }
        }
    }
}

void PromedioGastoGenero(Encuestados* encuestado, int N)
{
    int ContMasculinos = 0;
    int ContFemeninos = 0;
    int SumaMontosMasculino = 0;
    int SumaMontosFemenino = 0;
    double PromedioMontoMasc = 0;
    double PromedioMontoFeme = 0;

    for (int i = 0; i < N; i++)
    {
        if (encuestado[i].genero == 'M')
        {
            ContMasculinos++;
            SumaMontosMasculino += encuestado[i].monto;
        }
        if (encuestado[i].genero == 'F')
        {
            ContFemeninos++;
            SumaMontosFemenino += encuestado[i].monto;
        }
    }
    if (ContMasculinos > 0)
    {
        PromedioMontoMasc = (SumaMontosMasculino * 1.0) / ContMasculinos;
    }
    if (ContFemeninos > 0)
    {
        PromedioMontoFeme = (SumaMontosFemenino * 1.0) / ContFemeninos;
    }
    cout << endl << "El promedio de gastos segun genero Masculino: " << PromedioMontoMasc;
    cout << endl << "El promedio de gastos segun genero Femenino: " << PromedioMontoFeme << endl;
}

void PromedioGastoEdad(Encuestados* encuestado, int N)
{
    int SumaGastoEdad[51] = { 0 };
    int ContGastoEdad[51] = { 0 };
    double PromedioGastoEdad = 0;

    for (int i = 0; i < N; i++)
    {
        int edad = encuestado[i].edad;
        SumaGastoEdad[edad] += encuestado[i].monto;
        ContGastoEdad[edad]++;
    }
    for (int i = 15; i <= 50; i++)
    {
        if (ContGastoEdad[i] > 0)
        {
            PromedioGastoEdad = (SumaGastoEdad[i] * 1.0) / ContGastoEdad[i];
            cout << endl << "El promedio de gasto segun la edad " << i << ": " << PromedioGastoEdad;
        }
    }
}

int main()
{
    srand(time(nullptr));
    int N = ValidarN();
    Encuestados* encuestado = new Encuestados[N];

    GenerarDatos(encuestado, N);
    MostrarDatos(encuestado, N);
    cout << endl << "Listado ordenado ascendentemente segun genero y monto: " << endl;
    OrdenadoAscendentementeGeneroyMonto(encuestado, N);
    MostrarDatos(encuestado, N);
    PromedioGastoGenero(encuestado, N);
    PromedioGastoEdad(encuestado, N);

    delete[] encuestado;

    system("pause>0");
    return 0;
}