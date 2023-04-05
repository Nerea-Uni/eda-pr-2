/* 
 * File:	agenda.cpp
 * Date:	march 2023
 * Comms:	Fichero agenda.cpp correspondiente a la práctica 1 de la asignatura
 *        	de Estructuras de Datos y Algoritmos.
 */
#include "agenda.hpp"


/*
 * Devuelve una agenda vacía en a, sin contactos.
 */
void iniciar(agenda& a){
	a.total = 0;
}

/*
 * Si la agenda a no está llena (numero de contactos almacenados menor que MAX),
 * la función devuelve verdad y añade el contacto c a la agenda a.
 * Si la agenda está llena, la función devuelve falso y la agenda a no se modifica.
 */
bool anyadir(agenda& a, const contacto& c){
	bool sePuede = a.total < MAX;
	if(sePuede){
		a.datos[a.total] = c;
		a.total++;
	}
	return sePuede;
}

/*
 * Devuelve verdad si y sólo si la agenda a está vacía. 
 */
bool vacia(const agenda& a){
	return a.total == 0;
}

/*
 * Si a no está vacía, la función devuelve verdad y de la agenda a se elimina
 * el último contacto añadido a ella. Si a está vacía, la función devuelve 
 * falso y la agenda no se modifica.
 */
bool borrarUltimo(agenda& a){
	if(!vacia(a)){
		a.total--;
		return true;
	}
	else {
		return false;
	}
}

/*
 * Dada una agenda a y un contacto c, devuelve verdad si y sólo si en 
 * a hay algún contacto igual a c (en el sentido de la función == del TAD contacto), 
 * falso en caso contrario.
 */
bool esta(const agenda& a, const contacto& c){
	bool encontrado = false;
	int i = 0;
	while (i < a.total && !encontrado){
		encontrado = operator==(a.datos[i],c);
		i++;
	}
	return encontrado;
}

/*
 * Acciones del iterador
 */
void iniciarIterador(agenda& a){
	a.iter = 0;
}


bool existeSiguiente(agenda& a){
	return a.iter < a.total;
}


bool siguiente(agenda& a, contacto& c){
	if(existeSiguiente(a)){
		c = a.datos[a.iter];
		a.iter++;
		return true;
	}
	else {
		return true;
	}
}
