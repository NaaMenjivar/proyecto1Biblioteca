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

class Revista : public Material {
private:
	int numero;
	int volumen;
	string ubicacionFisica;
public:
	Revista(char tm, int c, int ct, string t, string a, string pC, string s, int nm, int vl, string uF);
	virtual ~Revista();

	//Acceso
	int getNumero();
	int getVolumen();
	string getUbicacionFisica();

	//Setteo
	void setNumero(int nm);
	void setVolumen(int vl);
	void setUbicacionFisica(string uF);

	//toString
	string toString() const override;
};

