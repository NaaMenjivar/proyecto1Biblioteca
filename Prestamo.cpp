#include "Prestamo.h"

Prestamo::Prestamo(int n, string i, int nCm, string fI, string fF) 
    : numeroPrestamo(n), idUsuario(i), numeroCatalogoMaterial(nCm), fechaInicio(fI), fechaFin(fF) {}
Prestamo::~Prestamo() {}

//Acceso
int Prestamo::getNumeroPrestamo() { return numeroPrestamo; }
string Prestamo::getIdUsuario() { return idUsuario; }
int Prestamo::getNumeroCatalogoMaterial() { return numeroCatalogoMaterial; }
string Prestamo::getFechaInicio() { return fechaInicio; }
string Prestamo::getFechaFin() { return fechaFin; }

//Setteo
void Prestamo::setNumeroPrestamo(int n) { numeroPrestamo = n; }
void Prestamo::setIdUsuario(string i) { idUsuario = i; }
void Prestamo::setNumeroCatalogoMaterial(int nCm) { numeroCatalogoMaterial = nCm; }
void Prestamo::setFechaInicio(string fI) { fechaInicio = fI; }
void Prestamo::setFechaFin(string fF) { fechaFin = fF; }

//toString
string Prestamo::toString() const {
    stringstream s;
    s << "Numero de prestamo: " << numeroPrestamo << endl;
    s << "ID de usuario: " << idUsuario << endl;
    s << "Numero de catalogo del material: " << numeroCatalogoMaterial << endl;
    s << "Fecha de inicio: " << fechaInicio << endl;
    s << "Fecha de finalizacion: " << fechaFin << endl;

    return s.str();
}
