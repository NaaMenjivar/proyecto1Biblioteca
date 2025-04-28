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
#include "Interfaz.h"
class Controladora
{
private:
	Biblioteca* biblioteca;
public:
	Controladora();
	~Controladora();

	void control0();
	int menuPrincipal();

	void controlMenuIngresos();
	int menuIngresos();
	void ingresarMaterial();
	void ingresarUsuario();
	void modificarMaterial();
	void modificarUsuario();

	void controlMenuPrestamosyDevoluciones();
	int menuPyD();
	void ingresarPrestamo();
	void devolucionPres();

	void controlMenuReportes(); 
	int menuReportes();
	void repMateriales();
	void repUsuarios();
	void repPrestamos();
	void repPrestamosporMat();
	void repPrestamosporUsr();

	void controlMenuGuardar();
	void guardarArchivos();
	void cargarArchivos();
};

