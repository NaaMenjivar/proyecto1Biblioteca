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

class Libro;
class Revista;
class Articulo;
class MaterialDigital;
class Video;

class Archivos //Delegacion de persistencia solo para las clases derivadas de Material
{
public:
	Archivos();
	virtual void guardarMaterial(Material*, std::ofstream&) = 0;//Solo archivos maneja de manera VP el guardar para tipo de material
	virtual ~Archivos();
};

class PersistenciaLibros :public Archivos {
public:
	virtual void guardarMaterial(Material*, std::ofstream&);
	Libro* cargarLibro(std::ifstream&);//Cada material maneja su cargar
};

class PersistenciaArticulos :public Archivos {
public:
	virtual void guardarMaterial(Material*, std::ofstream&);
	Articulo* cargarArticulo(std::ifstream&);//Cada material maneja su cargar
};

class PersistenciaResvistas :public Archivos {
public:
	virtual void guardarMaterial(Material*, std::ofstream&);
	Revista* cargarRevista(std::ifstream&);//Cada material maneja su cargar
};

class PersistenciaMatDigitales :public Archivos {
public:
	virtual void guardarMaterial(Material*, std::ofstream&);
	MaterialDigital* cargarMaterialDigital(std::ifstream&);//Cada material maneja su cargar
};

class PersistenciaVideo :public Archivos {
public:
	virtual void guardarMaterial(Material*, std::ofstream&);
	Video* cargarVideo(std::ifstream&);//Cada material maneja su cargar
};