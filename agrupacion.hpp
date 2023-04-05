/* 
 * File:	agrupacion.hpp
 * Date:	march 2023
 * Comms:	Fichero agrupacion.hpp correspondiente a la práctica 2 de la asignatura
 *          	de Estructuras de Datos y Algoritmos.
 */
#ifndef AGRUPACION_HPP
#define AGRUPACION_HPP

// PREDECLARACIÓN DEL TAD GENÉRICO agrupacion

const int MAX = 40;

/* COMPLETAR CON LA ESPECIFICACIÓN DEL DOMINIO DE VALORES DEL TAD agrupacion
   Y CON LAS CONDICIONES QUE SE LE EXIGEN AL PARÁMETRO DE TIPO T.
*/
template<typename T> struct agrupacion;


/* COMPLETAR LA ESPECIFICACIÓN DE CADA OPERACIÓN DEL TAD
*/
template<typename T> void iniciar(agrupacion<T>& a);

/* ...
*/
template<typename T> bool anyadir(agrupacion<T>& a, const T& e);

/* ...
*/
template<typename T> bool vacia(const agrupacion<T>& a);

/* ...
*/
template<typename T> bool borrarUltimo(agrupacion<T>& a);

/* ...
*/
template<typename T> bool esta(const agrupacion<T>& a, const T& e);

//COMPLETAR OPERACIONES ITERADOR
template<typename T> void iniciarIterador(agrupacion<T>& a);
template<typename T> bool existeSiguiente(const agrupacion<T>& a);
template<typename T> bool siguiente(agrupacion<T>& a, T& e);


// DECLARACIÓN DEL TAD GENÉRICO agrupacion

template<typename T>
struct agrupacion{
    friend void iniciar<T>(agrupacion<T>& a);
    friend bool anyadir<T>(agrupacion<T>& a, const T& e);
    friend bool vacia<T>(const agrupacion<T>& a);
    friend bool borrarUltimo<T>(agrupacion<T>& a);
    friend bool esta<T>(const agrupacion<T>& a, const T& e);
    //COMPLETAR OPERACIONES ITERADOR
    friend void iniciarIterador<T>(agrupacion<T>& a);
	friend bool existeSiguiente<T>(const agrupacion<T>& a);
	friend bool siguiente<T>(agrupacion<T>& a, T& e);
private: 
    //campos
	T datos[MAX];
	int total;
	int iter;
};


// IMPLEMENTACIÓN DE LAS OPERACIONES DEL TAD GENÉRICO agrupacion

template<typename T>
void iniciar(agrupacion<T>& a) {
	a.total = 0;
}

template<typename T>
bool anyadir(agrupacion<T>& a, const T& e) {
    bool llena = (a.total == MAX);
	if (!llena) {
		a.datos[a.total] = e;
		a.total++;
	}
	return !llena;
}

template<typename T>
bool vacia(const agrupacion<T>& a) {
    return a.total == 0;
}
	
template<typename T>
bool borrarUltimo(agrupacion<T>& a) {
	bool estaVacia = !vacia(a);
	if(estaVacia) {
		a.total--;
	}
	return estaVacia;
}

template<typename T>
bool esta(const agrupacion<T>& a, const T& e) {
	bool encontrado = false;
	unsigned int i = 0;
	while(i < a.total && !encontrado){
		encontrado = (a.datos[i] == e);
		i++;
	}
	return encontrado;
}

//COMPLETAR IMPLEMENTACION OPERACIONES ITERADOR
template<typename T> 
void iniciarIterador(agrupacion<T>& a){
	a.iter = 0;
}

template<typename T>
bool existeSiguiente(const agrupacion<T>& a){
	return a.iter < a.total;
}

template<typename T>
bool siguiente(agrupacion<T>& a, T& e){
	bool noExiste = !existeSiguiente(a);
	if(noExiste){
		e = a.datos[a.iter];
		a.iter++;
	}
	return noExiste;
}

#endif //fin de agrupacion.hpp
