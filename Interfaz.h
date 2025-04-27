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
#include "Biblioteca.h"
#include "Libro.h"
#include "Articulo.h"
#include "Revista.h"
#include "Video.h"
#include "MaterialDigital.h"

class Interfaz
{
public:
	//Menus
	static int menuPrincipal();
	static int menuIngresosModificaciones();
	static int menuPrestamos();
	static int menuReportes();
	static bool menuOpModificacionMaterial(Biblioteca&, Material*, char);//menu que modifica e ingresa al Material modificado
	static bool menuOpModificacionUsr(Biblioteca&, Usuario*);//menu que modifica e ingresa al Usuario modificado
	//Metodos de creacion
	static Material* crearMaterial();
	static Usuario* crearUsuario();
	//Metodos de modificacion
	static bool modificarMaterial(Biblioteca&); 
	static bool modicarUsuario(Biblioteca&); 
	//Metodos reportes
	static void reporteInvMaterial(Biblioteca&);
	static void reportdeUsuarios(Biblioteca&);
	//Mensajes
	static void mensajeIngresoExitoso();
	static void mensajeErrorIngreso();
};

