// -------------------------------------------------------------------+ 
//                                                                    | 
// (c) 2025                                                           | 
// EIF204 - Programación 2                                            | 
// 1er ciclo 2025                                                     | 
// NRC 41371 – Grupo 06                                               | 
// Proyecto 1                                                         | 
//                                                                    | 
// 1-1977-0346; Menjívar Ramírez, Naara                               | 
// 1-1905-0975; Chaves Salazar, Sebastián                             | 
//                                                                    | 
// versión 1.0.0 2025-04-01                                           | 
//                                                                    | 
// -------------------------------------------------------------------+
#pragma once
#include "Prestamo.h"

class NodoPrestamo {
private:
	Prestamo* dato;
	NodoPrestamo* sig;
public:
	NodoPrestamo(Prestamo* d, NodoPrestamo* s);
	virtual ~NodoPrestamo();

	//Acceso
	Prestamo* getDato();
	NodoPrestamo* getSiguiente();

	//Setteo
	void setDato(Prestamo* d);
	void setSiguiente(NodoPrestamo* s);

	//toString
	string toString() const;
};

class GestorPrestamos {
private:
	NodoPrestamo* primero;
	NodoPrestamo* actual;
public:
    GestorPrestamos();
    virtual ~GestorPrestamos();

	//Agregar prestamo
    bool agregarPrestamo(Prestamo& nuevoPrestamo);

	//Buscar y obtener prestamo
    bool buscarPrestamo(int numeroPrestamo);
	Prestamo* obtenerPrestamo(int numPrestamo);

	//Eliminar prestamo
    bool eliminarPrestamo(int numeroPrestamo);

	//Vaciar lista
    void vaciarLista();

	//tamanno lista
	int tamanno();
	//toString
    string toString();
	string toStringxMaterial(char);
	string toStringxUsuario(string);

	//Guardar
	void guardar(std::ofstream&);
};

