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
#include "Includes.h"//.h con las bibliotecas utilizadas...
using namespace std;

class Material {
protected:
	int numeroClasificacion;
	int numeroCatalogo;
	string titulo;
	string autor;
	string palabrasClave;
	char tipoMaterial;
	string estado;
	//int tiempoPrestado;
public:
	Material(char tm, int c, int ct, string t, string a, string pC, string s);
	virtual ~Material();
	
	//Acceso
	int getNumClasificacion();
	int getNumCatalogo();
	string getTitulo();
	string getAutor();
	string getPalabrasClave();
	char getTipoMaterial();
	string getEstado();

	//Setteo
	void setNumClasificacion(int c);
	void setNumCatalogo(int ct);
	void setTitulo(string t);
	void setAutor(string a);
	void setPalabrasClave(string pC);
	void setTipoMaterial(char tm);
	void setEstado(string s);

	//toString
	virtual string toString() const;

};

