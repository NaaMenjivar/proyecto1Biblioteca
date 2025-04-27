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
#include "Usuario.h"

class NodoUsuario {
private:
	Usuario* dato;
	NodoUsuario* sig;
public:
	NodoUsuario(Usuario* d, NodoUsuario* s);
	virtual ~NodoUsuario();

	//Acceso
	Usuario* getDato();
	NodoUsuario* getSiguiente();

	//Setteo
	void setDato(Usuario* d);
	void setSiguiente(NodoUsuario* s);

	//toString
	string toString() const;
};

class ListaUsuarios {
private:
	NodoUsuario* primero;
	NodoUsuario* actual;
public:
	ListaUsuarios();
	virtual ~ListaUsuarios();

	//Agregar usuarios
	bool agregarUsuarios(Usuario& nuevoUsuario);

	//Buscar y obtener usuarios 
	bool buscarUsuarios(string id);
	Usuario* obtenerUsuario(string id);

	//Eliminar material
	void eliminarUsuario(string id);

	//Vaciar lista
	void vaciarLista();

	//toString
	string toString();

	//Guardar
	void guardar(std::ofstream&);
};


