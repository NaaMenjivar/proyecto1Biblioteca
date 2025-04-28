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
#ifndef ARTICULO_H  
#define ARTICULO_H 
#include "Material.h"

class PersistenciaArticulos;
class ofstream;
class ifstream;

class Articulo : public Material {
private:
	string revistaPublicacion;
	string fechaPublicacion;
	PersistenciaArticulos* persistencia;
public:
	Articulo(char tm, int c, int ct, string t, string a, string pC, string s, string rP, string fP);
	virtual ~Articulo();

	//Acceso
	string getRevistaPublicacion();
	string getFechaPublicacion();

	//Setteo
	void setRevistaPublicacion(string rP);
	void setFechaPublicacion(string fP);

	//toString
	string toString() const override;
	
	//persistencia de datos
	void guardar(std::ofstream&);
	static Articulo* cargar(std::ifstream&);
};

#endif 