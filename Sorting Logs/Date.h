#ifndef DATE_H
#define DATE_H

#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

/*
La funcion es para transformar el formato de horas:minutos:segundos en 
puros segundos.

Precodicion: Tiene que estar en formato horas:minutos:segundos

Postcondicion: Se regresa el tiempo en segundos
*/

int time_to_seconds(string tiempo){
    stringstream st(tiempo);
    string segmento;
    vector <int> palabras;

    while(getline(st, segmento, ':')){
        palabras.push_back(stoi(segmento));
    }

    int horas = palabras[0], minutos = palabras[1], segundos = palabras[2];

    segundos += horas * 60 * 60 + minutos * 60;

    return segundos;
}

class Date{
    private:
        string month;
        int intMonth;
        int day;
        string time;
        int seconds;

        // Mapa para convertir el mes de string a int
        unordered_map <string, int> mapaMeses{
        {"Jan", 1},
        {"Feb", 2},
        {"Mar", 3},
        {"Apr", 4},
        {"May", 5},
        {"Jun", 6},
        {"Jul", 7},
        {"Aug", 8},
        {"Sep", 9},
        {"Oct", 10},
        {"Nov", 11},
        {"Dec", 12},
        };

    public:
        // Constructores
        Date(){
            month = "";
            intMonth = 0;
            day = 0;
            seconds = 0;
        }

        Date(string _month, int _day, string _time){
            month = _month;
            intMonth = mapaMeses[_month];
            day = _day;
            time = _time;
            seconds = time_to_seconds(_time);
        }

        // Getters
        string getMonth(){
            return month;
        }

        int getDay(){
            return day;
        }
        
        // Sobrecarga de operador para comparar fechas 
        bool operator > (const Date& b) {
            if(this -> intMonth != b.intMonth){ // Si el mes es diferente
                if(this -> intMonth > b.intMonth){ // Si el mes es mayor
                    return true;
                } else if (this -> intMonth < b.intMonth){ // Si el mes es menor
                    return false;
                }

            } else if (this -> day != b.day){ // Si el mes es igual pero el dia es diferente
                if(this -> day > b.day){ // Si el dia es mayor
                    return true;
                } else if (this -> day < b.day){ // Si el dia es menor
                    return false;
                }

            } else { // Si el mes y el dia son iguales
                if(this -> seconds > b.seconds){ // Si el tiempo es mayor
                    return true;
                } else if (this -> seconds < b.seconds){ // Si el tiempo es menor
                    return false;
                }
            }

            return false;
        }

        // Regresa los datos de la fecha en un string
        string datos(){
            return month + " " + to_string(day) + " " + time + " ";
        }

        // Muestra la fecha en consola
        void mostrarFecha(){
            cout << month + " " << day << " " << time + " ";
        }
};

#endif