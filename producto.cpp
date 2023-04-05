/* 
 * File:	producto.cpp
 * Date:	april 2023
 * Comms:	Fichero producto.cpp correspondiente a la práctica 2 de la asignatura
 *          	de Estructuras de Datos y Algoritmos.
 */
#include <iostream>
#include "producto.hpp"
using namespace std;

void crear (string nom, int can, producto& p){
    p.nombre = nom;
    p.cantidad = can;
}


string nombre (const producto& p){
    return p.nombre;
}


int cantidad (const producto& p){
    return p.cantidad;
}


bool operator== (const producto& p1, const producto& p2){
    return p1.nombre == p2.nombre;
}
