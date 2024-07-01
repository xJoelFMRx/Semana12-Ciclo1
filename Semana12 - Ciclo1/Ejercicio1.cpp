#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int ValidarN()
{
    int N;
    do
    {
        cout << "Ingrese numero de personas encuestadas: "; cin >> N;
    } while (N < 1 || N > 100);
    return N;
}

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

struct Encuestado
{
    int nivelaprobacion;
    int edad;
    char nivelsocioeconomico;
};

char Pnivelsocioeconomico[4] = { 'A','B','C','D' };

void GenerarDatos(Encuestado* encuestados, int N)
{
    for (int i = 0; i < N; i++)
    {
        encuestados[i].nivelaprobacion = RandInt(1, 5);
        encuestados[i].edad = RandInt(18, 100);
        encuestados[i].nivelsocioeconomico = Pnivelsocioeconomico[RandInt(0, 3)];
    }
}

void MostrarDatos(Encuestado* encuestados, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << endl << "Persona " << i + 1 << ": " << endl;
        cout << "Nivel de aprovacion: " << encuestados[i].nivelaprobacion << endl;
        cout << "Edad: " << encuestados[i].edad << endl;
        cout << "Nivel Socioeconomico: " << encuestados[i].nivelsocioeconomico << endl;
    }
}

void NivelAprobacionMayorVotacion(Encuestado* encuestados, int N)
{
    int cntSizeNivelAprob = 6;
    int* cnts = new int[cntSizeNivelAprob];
    for (int i = 0; i < cntSizeNivelAprob; i++)
    {
        cnts[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        cnts[encuestados[i].nivelaprobacion]++;
    }

    int posMayor = 0;
    for (int i = 1; i < cntSizeNivelAprob; i++)
    {
        if (cnts[i] > cnts[posMayor]) {
            posMayor = i;
        }
    }
    cout << endl << "El nivel de aprobacion que tuvo la mayor votacion es " << posMayor << " con " << cnts[posMayor] << " votos" << endl;
    delete[] cnts;
}

void CantNivelSocioEconomicoA(Encuestado* encuestados, int N)
{
    int contNivSocioEcA = 0;
    for (int i = 0; i < N; i++)
    {
        if (encuestados[i].nivelsocioeconomico == 'A')
        {
            contNivSocioEcA++;
        }
    }
    cout << "Participaron " << contNivSocioEcA << " persona(s) del nivel socioeconomico A en la encuesta" << endl;
}

void EdadPersonaMasJovenEnc(Encuestado* encuestados, int N)
{
    int edadmasjoven = encuestados[0].edad;
    for (int i = 1; i < N; i++)
    {
        if (edadmasjoven > encuestados[i].edad)
        {
            edadmasjoven = encuestados[i].edad;
        }
    }
    cout << "La edad de la persona mas joven encuestada es: " << edadmasjoven << endl;
}

int main()
{
    srand(time(nullptr));
    int N = ValidarN();
    Encuestado* encuestados = new Encuestado[N];

    GenerarDatos(encuestados, N);
    MostrarDatos(encuestados, N);
    NivelAprobacionMayorVotacion(encuestados, N);
    CantNivelSocioEconomicoA(encuestados, N);
    EdadPersonaMasJovenEnc(encuestados, N);

    delete[] encuestados;

    system("pause>0");
    return 0;
}