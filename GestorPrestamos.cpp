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
bool GestorPrestamos::eliminarPrestamo(int numeroPrestamo) {
    actual = primero;
    if (buscarPrestamo(numeroPrestamo)) {
        if (actual->getDato()->getNumeroPrestamo() == numeroPrestamo) {
            primero = primero->getSiguiente();
            delete actual;
            return true;
        }
        else {
            while (actual->getSiguiente()->getDato()->getNumeroPrestamo() != numeroPrestamo) {
                actual = actual->getSiguiente();
            }
            NodoPrestamo* nodo = actual->getSiguiente();
            actual->setSiguiente(actual->getSiguiente()->getSiguiente());
            delete nodo;
            return true;
        }
    }
    return false;
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

int GestorPrestamos::tamanno()
{
    int cant = 0;
    actual = primero;
    while (actual) {
        actual = actual->getSiguiente();
        cant++;
    }
    return cant;
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

string GestorPrestamos::toStringxMaterial(char tip)
{
    stringstream s;
    actual = primero; 
    bool encontrado = false;

    while (actual) {
        if (toupper(actual->getDato()->getTipoMaterial()) == toupper(tip)) { 
            s << actual->getDato()->toString() << endl; 
            encontrado = true;
        }
        actual = actual->getSiguiente(); 
    }

    if (!encontrado)
        return "";

    return s.str();
}

string GestorPrestamos::toStringxUsuario(string id)
{
    stringstream s;
    actual = primero;
    if (primero) {
        while (actual) {
            if (actual->getDato()->getIdUsuario() == id) {
                s << actual->getDato()->toString() << "\n";
            }
            actual = actual->getSiguiente();
        }
    }
    return s.str();
}

void GestorPrestamos::guardar(std::ofstream& file)
{
    actual = primero;
    while (actual) {
        actual->getDato()->guardar(file);
        actual = actual->getSiguiente();
    }
}
