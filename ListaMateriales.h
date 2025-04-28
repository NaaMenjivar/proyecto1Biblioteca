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
#ifndef LISTAMATERIALES_H  
#define LISTAMATERIALES_H 
#include "Material.h"
#include "Libro.h"
#include "Revista.h"
#include "Articulo.h"
#include "MaterialDigital.h"
#include "Video.h"

class NodoMaterial {
private:
	Material* dato;
	NodoMaterial* sig;
public:
	NodoMaterial(Material* d, NodoMaterial* s);
	virtual ~NodoMaterial();

	//Acceso
	Material* getDato();
	NodoMaterial* getSiguiente();

	//Setteo
	void setMaterial(Material* d);
	void setSiguiente(NodoMaterial* s);

	//toString
	string toString() const;
};

class ListaMateriales {
private:
	NodoMaterial* primero;
	NodoMaterial* actual;
public:
	ListaMateriales();
	virtual ~ListaMateriales();

	//Agregar materiales
	bool agregarMateriales(Material& nuevoMaterial);

	//Buscar y obtener materiales
	bool buscarxTipMaterial(char tipMaterial);
	bool buscarxNumCatalago(int numCatalago);
	Material* obtenerMaterial(int numCatalago);
	NodoMaterial* getPrimero();

	//Eliminar material
	void eliminarMaterial(int numCatalogo);

	//Vaciar lista
	void vaciarLista();

	//toString
	string toString();
	string toStringxMaterial(char tip);

	//Persistencia
	void guardar(std::ofstream&);
};

#endif 