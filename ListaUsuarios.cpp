#include "ListaUsuarios.h"

/*--------------------NODO--------------------*/
NodoUsuario::NodoUsuario(Usuario* d, NodoUsuario* s) : dato(d), sig(s) {}
NodoUsuario::~NodoUsuario() { delete dato; }

//Acceso
Usuario* NodoUsuario::getDato() { return dato; }
NodoUsuario* NodoUsuario::getSiguiente() { return sig; }

//Setteo
void NodoUsuario::setDato(Usuario* d) { dato = d; }
void NodoUsuario::setSiguiente(NodoUsuario* s) { sig = s; }

//toString
string NodoUsuario::toString() const {
    return dato->toString();
}

/*--------------------LISTA--------------------*/
ListaUsuarios::ListaUsuarios() : primero(nullptr), actual(nullptr) {}
ListaUsuarios::~ListaUsuarios() {
    if (primero != nullptr) {
        vaciarLista();
    }
}

//Agregar usuarios
bool ListaUsuarios::agregarUsuarios(Usuario* nuevoUsuario) {
    if (buscarUsuarios(nuevoUsuario->getId())) {
        return false;
    }
    primero = new NodoUsuario(nuevoUsuario, primero);
    return true;
}

//Buscar usuarios
bool ListaUsuarios::buscarUsuarios(string id) {
    if (primero == nullptr) {
        return false;
    }
    actual = primero;
    while (actual != nullptr) {
        if (actual->getDato()->getId() == id) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

//Eliminar usuario
void ListaUsuarios::eliminarUsuario(string id) {
    actual = primero;
    if (buscarUsuarios(id)) {
        if (actual->getDato()->getId() == id) {
            primero = primero->getSiguiente();
            delete actual;
        }
        else {
            while (actual->getSiguiente()->getDato()->getId() != id) {
                actual = actual->getSiguiente();
            }
            NodoUsuario* nodo = actual->getSiguiente();
            actual->setSiguiente(actual->getSiguiente()->getSiguiente());
            delete nodo;
        }
    }
}

//Vaciar lista
void ListaUsuarios::vaciarLista() {
    while (primero != nullptr) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}

//toString
string ListaUsuarios::toString() {
    stringstream s;
    int t = 1;
    if (primero == nullptr) {
        s << "No hay informacion que mostrar, la lista esta vacia." << endl;
    }
    else {
        actual = primero;
        while (actual != nullptr) {
            s << "---------------- " << t << " ----------------" << endl;
            s << actual->toString();
            t++;
            actual = actual->getSiguiente();
        }
    }
    return s.str();
}
