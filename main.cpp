/* 
 * File:	main.cpp
 * Date:	march 2023
 * Comms:	Fichero main.cpp correspondiente a la práctica 2 de la asignatura
 *          	de Estructuras de Datos y Algoritmos.
 */
#include <iostream>
#include "agenda.hpp"
#include "contacto.hpp"
using namespace std;

/*
 * Pre:     
 * Post:
 */
void datosAgenda(string& n1, string& n2, string& n3, string& d1, string& d2, string& d3, int& t1, int& t2, int& t3){
    n1 = "Nerea";
    n2 = "Javi";
    n3 = "Lucía";

    d1 = "NSL";
    d2 = "JSL";
    d3 = "LPS";

    t1 = 123456789;
    t2 = 123456788;
    t3 = 123456787;
}

void iterador(agenda& a) {
    contacto cparcial;
    iniciarIterador(a);

    while(!siguiente(a,cparcial)){
        cout << "Nombre: " << nombre(cparcial) << endl;
        cout << "Dirección: " << direccion(cparcial) << endl;
        cout << "Teléfono: " << telefono(cparcial) << endl;
    }
}

int main() {
    string n1,n2,n3,d1,d2,d3;
    int t1,t2,t3;

    datosAgenda(n1,n2,n3,d1,d2,d3,t1,t2,t3);
    contacto c1,c2,c3;

    //creamos los contactos tipo contacto
    crear(n1,d1,t1,c1);
    crear(n2,d2,t2,c2);
    crear(n3,d3,t3,c3);

    agenda a;
    iniciar(a);
    cout << "Agenda iniciada correctamente." << endl;

    //añado los contactos creados a la agenda
    if(anyadir(a,c1) && anyadir(a,c2) && anyadir(a,c3)){
        cout << "añadidos c1,c2 y c3 correctamente." << endl;
    }
    else{
        cout << "Los contactos c1, c2 y c3 no se han podido añadir correctamente." << endl;
    }

    iterador(a);
    if(!vacia(a)){
        cout << "No está vacía." << endl;
    }
    else {
        cout << "Está vacía." << endl;
    }

    if(borrarUltimo(a)){
        cout << "Borrado el último correctamente." << endl;
    }
    else{
        cout << "El último contacto no se ha borrado correctamente." << endl;
    }

    if(esta(a,c2)){
        cout << "El contacto c2 está." << endl;
    }
    else{
        cout << "El contacto c2 no está." << endl;
    }

    iterador(a);
    if(anyadir(a,c3)){
        cout << "Añadido c3." << endl;
    }
    else{
        cout << "El contacto c3 no se ha añadido correctamente." << endl;
    }
}
