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

class Material {
protected:
	int numeroClasificacion;
	int numeroCatalogo;
	string titulo;
	string autor;
	string palabrasClave;
	string tipoMaterial;
	string estado;
	//int tiempoPrestado;
public:
	Material(int c, int ct, string t, string a, string pC, string ty, string s);
	virtual ~Material();
	
	//Acceso
	int getNumClasificacion();
	int getNumCatalogo();
	string getTitulo();
	string getAutor();
	string getPalabrasClave();
	string getTipoMaterial();
	string getEstado();

	//Setteo
	void setNumClasificacion(int c);
	void setNumCatalogo(int ct);
	void setTitulo(string t);
	void setAutor(string a);
	void setPalabrasClave(string pC);
	void setTipoMaterial(string ty);
	void setEstado(string s);

	//toString
	virtual string toString() const;

};

