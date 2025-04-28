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
#ifndef USUARIO_H  
#define USUARIO_H 
#include "Includes.h"
#include "ConvDatosyFunc.h"

class Usuario {
private:
	string id;
	string nombre;
	bool activo;
public:
	Usuario(string i, string n, bool a);
	virtual ~Usuario();

	//Acceso
	string getId();
	string getNombre();
	bool getActivo();

	//Setteo
	void setId(string i);
	void setNombre(string n);
	void setActivo(bool a);

	//toString
	string toString() const;

	//Guardar y cargar
	void guardar(std::ofstream&);
	static Usuario* cargar(std::ifstream&);
};

#endif