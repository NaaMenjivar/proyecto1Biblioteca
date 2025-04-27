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
#include "ListaUsuarios.h"
#include "ListaMateriales.h"
#include "GestorPrestamos.h"
class Reportes
{
public:
	Reportes();
	virtual ~Reportes();
	
	//Metodos de los reportes
	string repInventarioMaterial(ListaMateriales&);
	string repMaterialEspecif(ListaMateriales&, char);
	string repUsuarios(ListaUsuarios&);
	string repPrestamos(GestorPrestamos&);
	string repPresxMat(GestorPrestamos&, char);
	string repPresxUsr(GestorPrestamos&, string);
};

