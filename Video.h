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

class Video : public Material {
private:
	string duracion;
	string formato;
public:
	Video(char tm, int c, int ct, string t, string a, string pC, string s, string d, string f);
	virtual ~Video();

	//Acceso
	string getDuracion();
	string getFormato();

	//Setteo
	void setDuracion(string d);
	void setFormato(string f);

	//toString
	string toString() const override;
};

