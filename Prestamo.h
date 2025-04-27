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
#include "Includes.h"
#include "Usuario.h"
#include "Material.h"

class Prestamo {
private:
	int numeroPrestamo;
	Usuario* usuario;
	Material* material;
	string fechaInicio;
	string fechaFin;
public:
	Prestamo(int n, Usuario& u, Material& m, string fI);
	virtual ~Prestamo();

	//Acceso
	int getNumeroPrestamo();
	Usuario* getUsuario();
	Material* getMaterial();
	string getFechaInicio();
	string getFechaFin();

	//Setteo
	void setNumeroPrestamo(int n);
	void setUsuario(Usuario* u);
	void setMaterial(Material* m);
	void setFechaInicio(string fI);
	void setFechaFin(string fF);

	//toString
	string toString() const;
};

