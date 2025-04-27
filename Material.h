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

class Material {
protected:
	int numeroClasificacion;
	int numeroCatalogo;
	string titulo;
	string autor;
	string palabrasClave;
	char tipoMaterial;
	string estado;
public:
	Material(char tm, int c, int ct, string t, string a, string pC, string s);
	virtual ~Material();
	
	//Acceso
	virtual int getNumClasificacion();
	virtual int getNumCatalogo();
	virtual string getTitulo();
	virtual string getAutor();
	virtual string getPalabrasClave();
	virtual char getTipoMaterial();
	virtual string getEstado();

	//Setteo
	virtual void setNumClasificacion(int c);
	virtual void setNumCatalogo(int ct);
	virtual void setTitulo(string t);
	virtual void setAutor(string a);
	virtual void setPalabrasClave(string pC);
	virtual void setTipoMaterial(char tm);
	virtual void setEstado(string s);

	//toString
	virtual string toString() const = 0;
	friend ostream& operator<<(ostream& os, const Material& m);
};

