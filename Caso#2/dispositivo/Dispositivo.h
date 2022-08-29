#include<iostream>
#include<vector>
using namespace std;

#ifndef DISPOSITIVO

#define DISPOSITIVO 1

struct parametro
{
    string llave;
    string valor;
};

struct accion
{
    string accName;
    vector<parametro> modificaciones;
};


class Dispositivo{
    private:                    
        string nombre;                   // nombre de un dispositivo
        string tipo;                    // tipo del dispositivo
        int habitacion;                // numero de habitacion en el que se ubica
        vector<parametro> parametros; // vector que contiene parametros editables del dispositivo propio  
        vector<accion> acciones;     // vector que contiene las diferentes acciones que realiza con sus respectivos parametros
        
    public:
        Dispositivo(string pNombre, string pTipo, int pHabitacion, vector<parametro> &pParametros, vector<accion> &pAcciones){
            nombre=pNombre;
            tipo=pTipo;
            habitacion=pHabitacion;
            parametros.swap(pParametros);
            acciones.swap(pAcciones);
        }

        string getName(){
            return nombre;
        }

        accion getAccion(int index){
            return acciones[index];
        }

};

#endif