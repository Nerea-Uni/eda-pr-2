/* 
 * File:	producto.hpp
 * Date:	april 2023
 * Comms:	Fichero producto.hpp correspondiente a la práctica 2 de la asignatura
 *          	de Estructuras de Datos y Algoritmos.
 */
#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP
#include <iostream>
using namespace std;

// Interfaz del TAD producto. Pre-declaraciones:
struct producto;
void crear (string nom, int can, producto& p);
string nombre (const producto& p);
int cantidad (const producto& p);
bool operator== (const producto& p1, const producto& p2);

//Declaración:
struct producto {
public:
    friend void crear (string nom, int can, producto& p);
    friend string nombre (const producto& p);
    friend int cantidad (const producto& p);
    friend bool operator== (const producto& p1, const producto& p2);
private:
    string nombre;
    int cantidad;
};

#endif
