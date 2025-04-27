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


class PersistenciaLibros;
class ofstream;
class ifstream;

class Libro : public Material {
private:
	string ubicacionFisica;
	PersistenciaLibros* persistencia;
public:
	Libro(char tm, int c, int ct, string t, string a, string pC, string s, string uF);
	virtual ~Libro();

	//Acceso
	string getUbicacionFisica();

	//Setteo
	void setUbicacionFisica(string uF);

	//toString
	string toString() const override;

	//persistencia de datos
	void guardar(std::ofstream&);
	static Libro* cargar(std::ifstream&);
};

