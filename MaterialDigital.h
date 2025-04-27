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
#include "Material.h"

class MaterialDigital : public Material {
private:
	string formato;
	string tipo;
	bool accesoEnLinea;
	PersistenciaMatDigitales* persistencia;
public:
	MaterialDigital(char tm, int c, int ct, string t, string a, string pC, string s, string f, string typ);
	virtual ~MaterialDigital();

	//Acceso
	string getFormato();
	string getTipo();
	bool getAccesoEnLinea();

	//Setteo
	void setFormato(string f);
	void setTipo(string typ);
	void setAccesoEnLinea(bool acEl);

	//toString
	string toString() const override;
};

