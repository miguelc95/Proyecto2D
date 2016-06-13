//Autores: Jose Carmelo Ramirez Beltran A01175987 y Miguel Cuellar A01280736
//Fecha: 20/04/2016
//Programa: Proyecto 2E - Brackets
//Clase: Algoritmos


#include <iostream>
#include <string>
using namespace std;

long long iMat[10000][10000], iNumCombinaciones=0;
int iBalanceString=0, minBalance = 32000;
const unsigned int modulo = 1000000007;

//Funcion que inicializa la matriz, segun el tamaño dado, en 0s
void inicializarMatriz(int iTam)
{
    for(int i=0; i<=iTam; i++)
    {
        for(int j=0; j<=iTam;j++)
        {
            iMat[i][j] = 0;
        }
    }
}

//Creamos la matriz de las combinaciones posibles dependiendo un balance. Sera usado para el calculo
void matrizCombinaciones(int iCantCar, int iCantDada)
{
    int iDif;
    //Brackets por agregar al string
    iDif = iCantCar - iCantDada;
    
    //Inicializamos la matriz
    inicializarMatriz(iCantCar);
    
    iMat[0][0] = 1;
    
    //Llenamos la matriz de combinaciones
    for(int i=1; i<=iDif; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(i == 0)
                iMat[i][j] = iMat[i-1][j+1];
            else
            {
                iMat[i][j]= iMat[i-1][j-1] + iMat[i-1][j+1];
            }
        }
    }
}

//Funcion para calcular el balance de un string de brackets dado
void calcularBalance(string sString)
{
    
    for(int i=0; i<sString.length(); i++)
    {
        //Si es abierto + 1
        if(sString[i] == '[')
            iBalanceString++;
        else
            //si es cerrado -1
            iBalanceString--;
        minBalance =  min(iBalanceString, minBalance);
    }
}
//Funcion para calcular el resultado final de combinaciones dado un string de brackets
void solucionCombinaciones(int iCantCar, int iCantDada)
{
    int iDif;
    //Brackets faltantes por agregar
    iDif = iCantCar - iCantDada;
    
    for(int i=0; i<=iDif; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j+iBalanceString>= iBalanceString && j>=-minBalance)
            {
                {
                    iNumCombinaciones += (iMat[i][j] * iMat[iDif-i][j+iBalanceString]);
                    iNumCombinaciones%=modulo;
                }
            }
        }
    }
}

int main() {
    string sStringBrackets;
    int iCantCar, iCantDada;
    
    cin>>iCantCar>>iCantDada;
    cin>>sStringBrackets;
    //Hacemos la matriz de combinaciones
    matrizCombinaciones(iCantCar, iCantDada);
    //Calculamos el balance del string de brackets dado
    calcularBalance(sStringBrackets);
    //Calculamos las combinaciones totales
    solucionCombinaciones(iCantCar, iCantDada);
    //Imprimimos el resultado
    cout<<iNumCombinaciones<<endl;
    return 0;
}