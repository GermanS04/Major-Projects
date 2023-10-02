#ifndef REGISTRO_H
#define REGISTRO_H

#include "Date.h"

class Registro{
private:
    Date fecha;
    string ip;
    string msj;

public:
    // Constructores
    Registro(){
        fecha = Date("Jan", 1, "00:00:00");
        ip = "0";
        msj = "NO";
    }
    Registro(Date _fecha, string _ip, string _msj){
        fecha = _fecha;
        ip = _ip;
        msj = _msj;
    }

    // Getters
    Date getFecha(){
        return fecha;
    }

    // Regresa los datos de la fecha en un string
    string datos(){
        return fecha.datos() + ip + msj;
    }

    // Muestra los datos del registro
    void mostrarDatos(){
        fecha.mostrarFecha();
        cout << ip + " " + msj << endl;
    }
};


#endif