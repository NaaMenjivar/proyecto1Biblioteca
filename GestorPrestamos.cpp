#include "GestorPrestamos.h"

/*--------------------NODO--------------------*/
NodoPrestamo::NodoPrestamo(Prestamo* d, NodoPrestamo* s) : dato(d), sig(s) {}
NodoPrestamo::~NodoPrestamo() {}

// Acceso
Prestamo* NodoPrestamo::getDato() { return dato; }
NodoPrestamo* NodoPrestamo::getSiguiente() { return sig; }

// Setteo
void NodoPrestamo::setDato(Prestamo* d) { dato = d; }
void NodoPrestamo::setSiguiente(NodoPrestamo* s) { sig = s; }

// toString
string NodoPrestamo::toString() const {
    return dato->toString();
}

/*--------------------LISTA / GESTOR--------------------*/
GestorPrestamos::GestorPrestamos() : primero(nullptr), actual(nullptr) {}
GestorPrestamos::~GestorPrestamos() {
    if (primero != nullptr) {
        vaciarLista();
    }
}

// Agregar préstamo
bool GestorPrestamos::agregarPrestamo(Prestamo& nuevoPrestamo) {
    if (buscarPrestamo(nuevoPrestamo.getNumeroPrestamo())) {
        return false;
    }
    primero = new NodoPrestamo(&nuevoPrestamo, primero);
        return true;
}

// Buscar préstamo
bool GestorPrestamos::buscarPrestamo(int numeroPrestamo) {
    actual = primero;
    while (actual != nullptr) {
        if (actual->getDato()->getNumeroPrestamo() == numeroPrestamo) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

//Obtener Prestamo
Prestamo* GestorPrestamos::obtenerPrestamo(int numPrestamo)
{
    actual = primero;
    while (actual != nullptr) {
        if (actual->getDato()->getNumeroPrestamo() == numPrestamo) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

// Eliminar préstamo
void GestorPrestamos::eliminarPrestamo(int numeroPrestamo) {
    actual = primero;
    if (buscarPrestamo(numeroPrestamo)) {
        if (actual->getDato()->getNumeroPrestamo() == numeroPrestamo) {
            primero = primero->getSiguiente();
            delete actual;
        }
        else {
            while (actual->getSiguiente()->getDato()->getNumeroPrestamo() != numeroPrestamo) {
                actual = actual->getSiguiente();
            }
            NodoPrestamo* nodo = actual->getSiguiente();
            actual->setSiguiente(actual->getSiguiente()->getSiguiente());
            delete nodo;
        }
    }
}

// Vaciar lista
void GestorPrestamos::vaciarLista() {
    while (primero != nullptr) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual->getDato();
        delete actual;
    }
}

// toString
string GestorPrestamos::toString() {
    stringstream s;
    int t = 1;
    if (primero == nullptr) {
        s << "No hay informacion que mostrar, la lista esta vacia." << endl;
    }
    else {
        actual = primero;
        while (actual != nullptr) {
            s << "------------- " << t << " -------------" << endl;
            s << actual->toString();
            t++;
            actual = actual->getSiguiente();
        }
    }
    return s.str();
}
