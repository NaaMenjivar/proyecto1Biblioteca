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
#include "ListaMateriales.h"
#include "ListaUsuarios.h"
#include "GestorPrestamos.h"
#include "Reportes.h"
class Biblioteca
{
private:
	ListaMateriales* materiales;
	ListaUsuarios* usuarios;
	GestorPrestamos* prestamos;
	Reportes* reportes;
public:
	Biblioteca();
	virtual ~Biblioteca();

	// Ingresos...
	bool ingresarMateriales(Material& m);
	bool ingresarUsuarios(Usuario& u);
	bool ingresarPrestamos(Prestamo& p);


	// Busquedas...
	Material* getMaterial(char tipMat);
	Usuario* getUsuarios(string idUs);
	Prestamo* getPrestamo(int numPe);

	// Reportes... 
	string reporteInvtMariales();
	string reporteMatEspecifico(char);
	string reporteUsuarios();
	string reportePrestamos();
	string reportePrestamosxMat(char);
	string reportePrestamosxUsr(string);
	
	//Eliminaciones...
	void eliminacionMaterial(int numCat);
	void eliminacionUsuario(string idUsr);
	bool devolucionMaterial(int numPre);
	
	// Guardar y cargar...
	void guardarMateriales();
	void cargarMateriales();
	void guardarUsuarios();
	void cargarUsuarios();
	void guardarPrestamos();
	void cargarPrestamos();
};

