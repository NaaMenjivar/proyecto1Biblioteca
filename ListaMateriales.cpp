#include "ListaMateriales.h"

/*--------------------NODO--------------------*/
NodoMaterial::NodoMaterial(Material* d, NodoMaterial* s) : dato(d), sig(s) {}
NodoMaterial::~NodoMaterial() { delete dato; }

//Acceso
Material* NodoMaterial::getDato() { return dato; }
NodoMaterial* NodoMaterial::getSiguiente() { return sig; }

//Setteo
void NodoMaterial::setMaterial(Material* d) { dato = d; }
void NodoMaterial::setSiguiente(NodoMaterial* s) { sig = s; }

//toString
string NodoMaterial::toString() const {
    return dato->toString();
}

/*--------------------LISTA--------------------*/
ListaMateriales::ListaMateriales() : primero(nullptr), actual(nullptr) {}
ListaMateriales::~ListaMateriales() {
    if (primero != nullptr) {
        vaciarLista();
    }
}
//Agregar materiales
bool ListaMateriales::agregarMateriales(Material* nuevoMaterial) {
    if (buscarMaterial(nuevoMaterial->getNumCatalogo())) {
        return false;
    }
    primero = new NodoMaterial(nuevoMaterial, primero);
        return true;
}

//Buscar materiales
bool ListaMateriales::buscarMaterial(int numCatalogo) {
    if (primero == nullptr) {
        return false;
    }
    actual = primero;
    while (actual != nullptr) {
        if (actual->getDato()->getNumCatalogo() == numCatalogo) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

//Eliminar material
void ListaMateriales::eliminarMaterial(int numCatalogo) {
    actual = primero;
    if (buscarMaterial(numCatalogo)) {
        if (actual->getDato()->getNumCatalogo() == numCatalogo) {
            primero = primero->getSiguiente();
            delete actual;
        }
        else {
            while (actual->getSiguiente()->getDato()->getNumCatalogo() != numCatalogo) {
                actual = actual->getSiguiente();
            }
            NodoMaterial* nodo = actual->getSiguiente();
            actual->setSiguiente(actual->getSiguiente()->getSiguiente());
            delete nodo;
        }
    }
}

//Vaciar lista
void ListaMateriales::vaciarLista() {
    while (primero != nullptr) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual;
    }
}

//toString
string ListaMateriales::toString() {
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
