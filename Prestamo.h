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
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Prestamo {
private:
	int numeroPrestamo;
	string idUsuario;
	int numeroCatalogoMaterial;
	string fechaInicio;
	string fechaFin;
public:
	Prestamo(int n, string i, int nCm, string fI, string fF);
	virtual ~Prestamo();

	//Acceso
	int getNumeroPrestamo();
	string getIdUsuario();
	int getNumeroCatalogoMaterial();
	string getFechaInicio();
	string getFechaFin();

	//Setteo
	void setNumeroPrestamo(int n);
	void setIdUsuario(string i);
	void setNumeroCatalogoMaterial(int nCm);
	void setFechaInicio(string fI);
	void setFechaFin(string fF);

	//toString
	string toString() const;
};

