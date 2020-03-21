//
// Created by yasmi on 21/03/2020.
//
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include <fstream>

#ifndef PREOYECTO1_LISTASIMPLEORDENADA_H
#define PREOYECTO1_LISTASIMPLEORDENADA_H
using namespace::std;

class ListaSimpleOrdenada{

    bool esVacia = true;
    int contanodos = 0;
    class Nodo
    {
    public:
        int puntaje;
        int correlativo;
        Nodo *siguiente;
    } * ultimo,*primero, *actual, *nuevo, *auxiliar;

    bool isVacia() const;

    void insertar(int puntaje);
    void mostrarLista();
    string generarGraphviz();
    void ordenar();
};

bool ListaSimpleOrdenada::isVacia() const {
    return this->esVacia;
}

void ListaSimpleOrdenada::insertar(int puntaje) {
    if (!primero)
    {
        esVacia = false;
        primero = new (Nodo);
        ultimo = new (Nodo);

        primero->siguiente = NULL;
        primero->puntaje = puntaje;
        primero->correlativo = contanodos;
        contanodos++;

        // si son los mismos porque primero y ultimo son
        // punteros, NO NODOS alv
        ultimo = primero;
        return;
    }

    nuevo = new (Nodo);

    nuevo->puntaje = puntaje;
    nuevo->correlativo = contanodos;
    contanodos++;

    ultimo->siguiente = nuevo;
    ultimo = nuevo;
    return;
}

void ListaSimpleOrdenada::mostrarLista() {
    cout<<endl;
    cout<<endl;
    if (esVacia)
    {
        cout << "La lista esta vacia :C" << endl;
        return;

    }
    actual = primero;

    do
    {
        cout << "\t\t"<<actual->correlativo << " " << actual->puntaje << endl;

        actual = actual->siguiente;

    } while (actual != ultimo->siguiente);

    cout<<endl;
    cout<<endl;
    cout << "La lista ha finalizado" << endl;
}

string ListaSimpleOrdenada::generarGraphviz() {
    string lista;

    actual = primero;
    int contador = 0;

    while(actual != ultimo->siguiente){

        string u;
        string numero = to_string(contador);

        if(actual == ultimo){
            lista = lista + numero + ";\n";}
        else {
            lista = lista + numero + "->";
        }

        contador++;
        actual = actual->siguiente;
    }

    actual = primero;
    contador = 0;
    while(actual != ultimo->siguiente){
        string u;
        string numero = to_string(contador);
        string puntaje = to_string(actual->puntaje);

        lista = lista + numero + " [label = \"" + puntaje + " pts\"];\n";
        contador++;
        actual = actual->siguiente;
    }

    return lista;
}

void ListaSimpleOrdenada::ordenar() {
    actual = primero;

    while(actual != NULL){

        auxiliar = actual->siguiente;

        while(auxiliar != NULL){

            if(actual->puntaje < auxiliar->puntaje){

                int aux = auxiliar->puntaje;
                auxiliar->puntaje = actual->puntaje;

                actual->puntaje = aux;

            }

            auxiliar = auxiliar->siguiente;
        }

        actual = actual->siguiente;
    }

}


#endif //PREOYECTO1_LISTASIMPLEORDENADA_H