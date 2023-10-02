/*
Este programa esta hecho para recibir los datos de un archivo de texto donde
hay registros de acceso a una cuenta junto a fechas y horas. El programa ordena
los registros por fecha y hora y luego busca los registros que se encuentran entre
dos fechas dadas por el usuario.

Se crean dos archivos de texto, uno con los registros ordenados y otro con los
registros que se encuentran entre las fechas dadas por el usuario.
*/

// German Salas Martinez A01178095
// Isaac Francisco Sánchez Veloquio A01198327
// Jorge Betanzo Carriles A01198676
// 10 Septiembre 2023

#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>

// Headers de las clases
#include "Date.h"
#include "Registro.h"

using namespace std;

/*
La funcion es para leer el archivo y guardar los datos en un vector de registros

Precodicion: El archivo debe de existir y tener el formato correcto

Postcondicion: El vector de registros estara lleno con los datos del archivo

Complejidad computacional: O(n), debido a que pasa por cada linea del archivo
*/
void leerArchivo(string path, vector<Registro> &registros){
    ifstream file; // Para leer el archivo como input

    Date fecha;
    int dia;
    string mes, hora, ip, mensaje;
    
    file.open(path);
 
    string line;

    // Loop para leer cada linea del archivo
    while(getline(file, line)){
        istringstream linea(line); // Para separar los datos de la linea

        linea >> mes >> dia >> hora >> ip;

        getline(linea, mensaje); // Para leer el mensaje restante del string

        registros.push_back(Registro(Date(mes, dia, hora), ip, mensaje));
    }

    file.close();
}

/*
Las funciones es un metodo de ordenamiento en donde de un vector de registros
se divide en dos vectores en una recursiva hasta que el tamaño del vector sea 1. Para
luego pasarlo a otra funcion en donde se comparan los dos lados para saber cual es menor
y acomodarlo.

Precondicion: Vector con N registros

Postcondicion: El vector con registros estara ordenado por fecha

Complejidad Computacional: O(nlog(n)), debido a que divide el vector en dos pero se
tiene una complejidad lineal a la hora de unir los dos lados.
*/

void merge(vector<Registro> &lista, int inicio, int mitad, int fin){
    int tamanoIzquierda = mitad - inicio + 1;
    int tamanoDerecha = fin - mitad;

    vector<Registro> left(tamanoIzquierda);
    vector<Registro> right(tamanoDerecha);

    // Llenar los vectores derecha e izquierda al dividir el vector original en dos
    for(int i = 0; i < tamanoIzquierda; i++){
        left[i] = lista[inicio + i];
    }

    for(int j = 0; j < tamanoDerecha; j++){
        right[j] = lista[mitad + 1 + j];
    }


    int i = 0, j = 0, k = inicio;

    // Comparaciones para saber que valor es menor entre los dos vectores 
    // y colocarlo en el vector original en orden ascendente
    while(i < tamanoIzquierda && j < tamanoDerecha){
        if(right[j].getFecha() > left[i].getFecha()){
            lista[k] = left[i];
            i++;
        } else {
            lista[k] = right[j];
            j++;
        }
        k++;
    }

    // Copiar el resto del vector que queda
    while (i < tamanoIzquierda) {
        lista[k] = left[i];
        i++;
        k++;
    }

    while (j < tamanoDerecha) {
        lista[k] = right[j];
        j++;
        k++;
    }

}

void ordenaMerge(vector<Registro> &lista, int inicio, int fin){
    if(inicio < fin){
        int mitad = (inicio + fin) / 2;

        // Se divide la lista en dos
        ordenaMerge(lista, inicio, mitad);
        ordenaMerge(lista, mitad + 1, fin);

        merge(lista, inicio, mitad, fin);
    }
}

/*
La función es un metodo de busqueda en donde se recorre todo el vector y hace 
comparacion con cada uno de sus valores para saber si es igual al valor que 
se desea encontrar. 

Precondicion: Vector con N registros ordenados por fecha

Postcondicion: Ninguna

Complejidad Computacional: O(n) debido a que recorre la lista una sola vez para
hacer comparaciones.
*/

int busqSecuencial(string mes, int dia, vector<Registro> lista, int tipo){
    int tamano = lista.size();
    if(tipo){
        // Si se quiere encontrar la primera aparicion de la fecha
        for(int indice = 0; indice < tamano; indice++){
            // Si el mes y el dia son iguales regresar el indice
            if(lista[indice].getFecha().getMonth() == mes && lista[indice].getFecha().getDay() == dia){
                return indice;
            }
        }
    } else {
        // Si se quiere encontrar la ultima aparicion de la fecha
        for(int indice = tamano-1; indice >= 0; indice--){
            // Si el mes y el dia son iguales regresar el indice
            if(lista[indice].getFecha().getMonth() == mes && lista[indice].getFecha().getDay() == dia){
                return indice;
            }
        }
    }

    return -1;
}

int main(){
    ofstream ordenadoFile, busqFile; // Para escribir en un archivo como output

    ordenadoFile.open("ordenado.txt");
    busqFile.open("busqueda.txt");

    vector<Registro> registro;

    cout << "Leyendo archivo..." << endl;
    leerArchivo("bitacora.txt", registro); // Leer el archivo y guardar los datos en un vector

    cout << "Ordenando registros..." << endl;
    ordenaMerge(registro, 0, registro.size()-1); // Ordenar el vector por fecha

    // Escribir el registro ordenado en un archivo
    for(auto i:registro){
        ordenadoFile<<i.datos()<<"\n";
    }
    cout << "Registros ordenados y escritos en \"ordenado.txt\"" << endl << endl;
    ordenadoFile.close();

    sleep(2); // Para que el usuario pueda leer el mensaje anterior

    string inicioMes, finMes;
    int inicioDia, finDia;

    // Pedir a usuario desde que fecha quiere buscar
    cout << "Ingrese la fecha desde la que quiere buscar: \n";
    cout << "Minimo: " + registro[0].getFecha().datos() << endl;
    cout << "Maximo: " + registro[registro.size()-1].getFecha().datos() + "\n\n";

    cout << "Formato: Jun 1" << endl;
    cout << "Ingrese el mes y dia: " << endl;
    cin >> inicioMes >> inicioDia;

    // Pedir a usuario hasta que fecha quiere buscar
    cout << endl<<"Ingrese la fecha hasta la que quiere buscar: \n";
    cout << "Maximo: " + registro[registro.size()-1].getFecha().datos() + "\n\n";

    cout << "Formato: Jun 1" << endl;
    cout << "Ingrese el mes y dia: " << endl;
    cin >> finMes >> finDia;


    // Buscar en el vector ordenado el indice de la fecha desde la que se desea
    int primerIndice = busqSecuencial(inicioMes, inicioDia, registro, 1);

    // Buscar en el vector ordenado el indice de la fecha hasta la que se desea
    int ultimoIndice = busqSecuencial(finMes, finDia, registro, 0);
    
    // Escribir en un archivo las fechas que se encuentran entre las fechas dadas
    for(int i = primerIndice; i <= ultimoIndice; i++){
        busqFile<<registro[i].datos()<<endl;
    }

    cout << "Registros encontrados y escritos en \"busqueda.txt\"" << endl;

    busqFile.close();
    return 0;
}