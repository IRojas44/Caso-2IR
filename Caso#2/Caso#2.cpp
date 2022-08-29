#include <string>
#include <iostream>
#include <vector>
#include "dispositivo/Dispositivo.h"
#include "lista/ListD.h"

using namespace std;

struct habitacion{
    string nombre;
    int numeroRelacionado;
    List<Dispositivo>* dispositivosAsociados = new List<Dispositivo>();
};

struct procedimiento{
    string disName;
    vector<accion> listaAcciones;
};

struct tarea{
    string tarName;
    List<procedimiento>* procedimientos = new List<procedimiento>();
};

int main(){

    //Creacion de un dispositivos con acciones (Bombillo)
    vector<parametro> parametrosBom1;
    vector<accion> accionesBom1;
    parametro colorBomCoOff; colorBomCoOff.llave="color"; colorBomCoOff.valor="negro";                    //Parametros del Bombillo en diferentes acciones
    parametro intensidadBomCoOff; intensidadBomCoOff.llave="intensidad"; intensidadBomCoOff.valor="0";
    accion apagarBomCo; apagarBomCo.accName="Apagar Bombillo"; apagarBomCo.modificaciones.push_back(colorBomCoOff); apagarBomCo.modificaciones.push_back(intensidadBomCoOff); 
    
    parametro colorBomCoOn; colorBomCoOn.llave="color"; colorBomCoOn.valor="blanco";
    parametro intensidadBomCoOn; intensidadBomCoOn.llave="intensidad"; intensidadBomCoOn.valor="3";
    accion encenderBomCo; encenderBomCo.accName="Encender Bombillo"; encenderBomCo.modificaciones.push_back(colorBomCoOn); encenderBomCo.modificaciones.push_back(intensidadBomCoOn); 
 
    parametrosBom1.push_back(colorBomCoOff); parametrosBom1.push_back(intensidadBomCoOff); parametrosBom1.push_back(colorBomCoOn); parametrosBom1.push_back(intensidadBomCoOn); 
    accionesBom1.push_back(apagarBomCo); accionesBom1.push_back(encenderBomCo);
    Dispositivo *dis1 = new Dispositivo("Bombillo de la cocina","Bombillo",1,parametrosBom1,accionesBom1);
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //Creacion de un dispositivos con acciones (Bombillo)
    vector<parametro> parametrosBom;
    vector<accion> accionesBom;
    parametro colorBomOff; colorBomOff.llave="color"; colorBomOff.valor="negro";                    //Parametros del Bombillo en diferentes acciones
    parametro intensidadBomOff; intensidadBomOff.llave="intensidad"; intensidadBomOff.valor="0";
    accion apagarBom; apagarBom.accName="Apagar Bombillo"; apagarBom.modificaciones.push_back(colorBomOff); apagarBom.modificaciones.push_back(intensidadBomOff); 
    
    parametro colorBomOn; colorBomOn.llave="color"; colorBomOn.valor="blanco";
    parametro intensidadBomOn; intensidadBomOn.llave="intensidad"; intensidadBomOn.valor="3";
    accion encenderBom; encenderBom.accName="Encender Bombillo"; encenderBom.modificaciones.push_back(colorBomOn); encenderBom.modificaciones.push_back(intensidadBomOn); 
 
    parametrosBom.push_back(colorBomOff); parametrosBom.push_back(intensidadBomOff); parametrosBom.push_back(colorBomOn); parametrosBom.push_back(intensidadBomOn); 
    accionesBom.push_back(apagarBom); accionesBom.push_back(encenderBom);
    Dispositivo *dis3 = new Dispositivo("Bombillo del estudio","Bombillo",2,parametrosBom,accionesBom);
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //Creacion de un dispositivos con acciones (Coffee Maker)
    vector<parametro> parametrosCf;
    vector<accion> accionesCf;
    parametro cfOff; cfOff.llave="estado"; cfOff.valor="false";                    
    accion apagarCf; apagarCf.accName="Apagar Coffee Maker"; apagarCf.modificaciones.push_back(cfOff);
    
    parametro cfOn; cfOn.llave="estado"; cfOn.valor="true";
    accion encenderCf; encenderCf.accName="Encender Coffee Maker"; encenderCf.modificaciones.push_back(cfOn);  

    parametro intensidadCfSuave; intensidadCfSuave.llave="intensidad del sabor"; intensidadCfSuave.valor="suave";
    accion intensidadCf; intensidadCf.accName="Modificar la intensidad del sabor"; intensidadCf.modificaciones.push_back(intensidadCfSuave); 
 
    parametrosCf.push_back(cfOff); parametrosCf.push_back(cfOn); parametrosCf.push_back(intensidadCfSuave); 
    accionesCf.push_back(apagarCf); accionesCf.push_back(encenderCf); accionesCf.push_back(intensidadCf);
    Dispositivo *dis2 = new Dispositivo("Coffee Maker","Electrodomestico",1,parametrosCf,accionesCf);
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //Creacion de un dispositivos con acciones (Toma corriente)
    vector<parametro> parametrosToma;
    vector<accion> accionesToma;

    parametro voltajeTomaOff; voltajeTomaOff.llave="voltaje"; voltajeTomaOff.valor="0 v";
    accion apagarToma; apagarToma.accName="Apagar Tomacorriente"; apagarToma.modificaciones.push_back(voltajeTomaOff);  
    
    parametro voltajeTomaOn; voltajeTomaOn.llave="voltaje"; voltajeTomaOn.valor="110 v";
    accion encenderToma; encenderToma.accName="Encender Tomacorriente"; encenderToma.modificaciones.push_back(voltajeTomaOn); 
 
    parametrosToma.push_back(voltajeTomaOff); parametrosToma.push_back(voltajeTomaOn); 
    accionesToma.push_back(apagarToma); accionesToma.push_back(encenderToma);
    Dispositivo *dis4 = new Dispositivo("Tomacorriente de la computadora y monitor","Tomacorriente",2,parametrosToma,accionesToma);
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    //Crear una lista de habitaciones ademas de asociarles dispositivos
    List<habitacion>* habitaciones = new List<habitacion>();
    habitacion hab1; hab1.nombre="Cocina"; hab1.numeroRelacionado=1; habitaciones->add(new habitacion(hab1)); 
    hab1.dispositivosAsociados->add(dis1); //Agregar un dispositivo a una habitacion
    hab1.dispositivosAsociados->add(dis2); //Agregar un dispositivo a una habitacion
    habitacion hab2; hab2.nombre="Estudio"; hab2.numeroRelacionado=2; habitaciones->add(new habitacion(hab2)); 
    hab2.dispositivosAsociados->add(dis3); //Agregar un dispositivo a una habitacion
    hab2.dispositivosAsociados->add(dis4); //Agregar un dispositivo a una habitacion
    habitacion hab3; hab3.nombre="Cuarto"; hab3.numeroRelacionado=3; habitaciones->add(new habitacion(hab3)); 
    habitacion hab4; hab4.nombre="Baño"; hab4.numeroRelacionado=4; habitaciones->add(new habitacion(hab4)); 

    List<tarea>* listaTareas = new List<tarea>();
    //Creacion de una tarea (Buenos Dias)
    procedimiento buenosDiasProce1; buenosDiasProce1.disName=dis1->getName(); 
    buenosDiasProce1.listaAcciones.push_back(dis1->getAccion(1)); 
    procedimiento buenosDiasProce2; buenosDiasProce2.disName=dis2->getName(); 
    buenosDiasProce2.listaAcciones.push_back(dis2->getAccion(1));
    buenosDiasProce2.listaAcciones.push_back(dis2->getAccion(2));
    tarea tarea1; tarea1.tarName="Buenos Dias"; 
    tarea1.procedimientos->add(new procedimiento(buenosDiasProce1));
    tarea1.procedimientos->add(new procedimiento(buenosDiasProce2));

    //Creacion de una tarea (Trabajar)
    procedimiento trabajarProce1; trabajarProce1.disName=dis3->getName(); 
    trabajarProce1.listaAcciones.push_back(dis3->getAccion(1)); 
    procedimiento trabajarProce2; trabajarProce2.disName=dis4->getName(); 
    trabajarProce2.listaAcciones.push_back(dis4->getAccion(1)); 
    tarea tarea2; tarea2.tarName="Trabajar"; 
    tarea2.procedimientos->add(new procedimiento(trabajarProce1));
    tarea2.procedimientos->add(new procedimiento(trabajarProce2));

    listaTareas->add(new tarea(tarea1));
    listaTareas->add(new tarea(tarea2));


    return 0;
}
