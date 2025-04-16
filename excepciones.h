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
#include <exception>
#include <iostream>
using namespace std;

class Excepciones : public exception {
public:
	virtual const char* what() const throw() {
		return "Excepcion general.";
	}
};

class ExcepcionRango : public Excepciones {
public:
	virtual const char* what() const throw() {
		return "Excepcion de rango.";
	}
};

class ExcepcionRangoInferior : public ExcepcionRango {
public:
	virtual const char* what() const throw() {
		return "Excepcion de rango inferior.";
	}
};

class ExcepcionRangoSuperior : public ExcepcionRango {
public:
	virtual const char* what() const throw() {
		return "Excepcion de rango superior.";
	}
};

class ExcepcionCaracteres : public Excepciones {
public:
	virtual const char* what() const throw() {
		return "Caracteres no validos.";
	}
};

class ExcepcionEspacios : public ExcepcionCaracteres {
public:
	virtual const char* what() const throw() {
		return "Espacios no autorizados.";
	}
};

class ExcepcionCampoVacio : public ExcepcionCaracteres {
public:
	virtual const char* what() const throw() {
		return "Campo ingresado vacio.";
	}
};

