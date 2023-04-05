/* 
 * File:	main3.cpp
 * Date:	march 2023
 * Comms:	Fichero main3.cpp correspondiente a la práctica 2 de la asignatura
 *          	de Estructuras de Datos y Algoritmos.
 */
#include <iostream>
#include "agrupacion.hpp"
#include "contacto.hpp"
#include "producto.hpp"
using namespace std;

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

void datosCompra (string& pro1, string& pro2, string& pro3, int& cant1, int& cant2, int& cant3){
    pro1 = "Manzanas";
    pro2 = "Pan";
    pro3 = "Queso";

    cant1 = 6;
    cant2 = 2;
    cant3 = 10;
}

template<typename T>
void iterador(agrupacion<T>& a) {
    contacto cparcial;
    iniciarIterador(a);
    while(!siguiente(a,cparcial)){
        cout << "Nombre: " << nombre(cparcial) << endl;
        cout << "Dirección: " << direccion(cparcial) << endl;
        cout << "Teléfono: " << telefono(cparcial) << endl;
    }

    iniciarIterador(a);
    bool correcto;
    while(existeSiguiente(a)){
        correcto = siguiente(a,cparcial);
        cout << "Nombre: " << nombre(cparcial) << endl;
        cout << "Dirección: " << direccion(cparcial) << endl;
        cout << "Teléfono: " << telefono(cparcial) << endl;
        cout << endl;
    }
}

template<typename T>
void iterador2(agrupacion<T>& p) {
    producto prodParcial;
    iniciarIterador(p);
    while(!siguiente(p,prodParcial)){
        cout << "Nombre: " << nombre(prodParcial) << endl;
        cout << "Cantidad: " << cantidad(prodParcial) << endl;
    }

    iniciarIterador(p);
    bool correcto1;
    while(existeSiguiente(a)){
        correcto1 = siguiente(a,cparcial);
        cout << "Nombre: " << nombre(prodParcial) << endl;
        cout << "Cantidad: " << cantidad(prodParcial) << endl;
        cout << endl;
    }
}

int main() {
    agrupacion<contacto> a;
    agrupacion<producto> p;
    string n1,n2,n3,d1,d2,d3,pro1,pro2,pro3;
    int t1,t2,t3,cant1,cant2,cant3;

    datosAgenda(n1,n2,n3,d1,d2,d3,t1,t2,t3);
    datosCompra(pro1,pro2,pro3,cant1,cant2,cant3);
    contacto c1,c2,c3;
    producto p1,p2,p3;

    //creamos los contactos tipo contacto
    crear(n1,d1,t1,c1);
    crear(n2,d2,t2,c2);
    crear(n3,d3,t3,c3);
    //creamos los contactos tipo producto
    crear(pro1,cant1,p1);
    crear(pro2,cant2,p2);
    crear(pro3,cant3,p3);

    iniciar(a);
    iniciar(p);
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

    /*******************************************************************/
    if(anyadir(p,p1) && anyadir(p,p2) && anyadir(p,p3)){
        cout << "Añadidos manzanas, pan y queso correctamente." << endl;
    }
    else{
        cout << "Los productos manzanas, pan y queso no se han podido añadir correctamente." << endl;
    }

    iterador2(p);
    if(!vacia(p)){
        cout << "No está vacía." << endl;
    }
    else {
        cout << "Está vacía." << endl;
    }

    if(borrarUltimo(p)){
        cout << "Borrado el último correctamente." << endl;
    }
    else{
        cout << "El último producto no se ha borrado correctamente." << endl;
    }

    if(esta(p,p2)){
        cout << "El producto pan está." << endl;
    }
    else{
        cout << "El producto pan no está." << endl;
    }

    iterador2(p);
    if(anyadir(p,p3)){
        cout << "Añadido queso." << endl;
    }
    else{
        cout << "El producto queso no se ha añadido correctamente." << endl;
    }
}
