#include "Interfaz.h"

int Interfaz::menuPrincipal()
{
	int op;
	system("cls");
	cout << "==========MENU PRINCIPAL==========" << endl;
	cout << "1.Submenu de Ingresos & Modificacion" << endl;//crear e ingresar datos
	cout << "2.Submenu de Prestamos & Devoluciones." << endl;
	cout << "3.Submenu de reportes." << endl;//listas de informacion
	cout << "4.Guardar datos." << endl;
	cout << "5.Salir." << endl;
	cout << "Ingrese su respuesta: "; cin >> op;

	return op;
}

int Interfaz::menuIngresosModificaciones()
{
	int op;
	system("cls");
	cout << "==========SUBMENU INGRESOS & MODIFICACION==========" << endl;
	cout << "1.Ingresar Material" << endl;
	cout << "2.Ingresar Usuario." << endl;
	cout << "3.Modificar Material." << endl;
	cout << "4.Modificar Usuario." << endl;
	cout << "5.Regresar al menu Principal." << endl;
	cout << "Ingrese su respuesta: "; cin >> op;

	return op;
}

int Interfaz::menuPrestamos()
{
	int op;
	system("cls");
	cout << "==========SUBMENU PRESTAMOS Y DEVOLUCIONES==========" << endl;
	cout << "1.Registrar Pretamo" << endl;
	cout << "2.Registrar Devolucion." << endl;
	cout << "3.Regresar al menu Principal." << endl;
	cout << "Ingrese su respuesta: "; cin >> op;

	return op;
}

int Interfaz::menuReportes()
{
	int op;
	system("cls");
	cout << "==========SUBMENU REPORTES==========" << endl;
	cout << "1.Reporte inventario materiales." << endl;
	cout << "2.Reporte usuarios." << endl;
	cout << "3.Reporte general materiales prestados." << endl;
	cout << "4.Reporte por material prestado." << endl;
	cout << "5 Reporte prestamos por usuario." << endl;
	cout << "6.Regresar al menu Principal." << endl;
	cout << "Ingrese su respuesta: "; cin >> op;

	return op;
}

Material* Interfaz::crearMaterial()
{
	system("cls");
	//Variables para la construccion de obj Material
	int numClasi, numCata, numRev, volumen, accLinea; 
	string titulo, autor, palbClav, estado, ubiFisica, duracion, formato, tipo, publicacion, fechaPubli;
	char tipMaterial;

	cout << "==========CREACION DE UN MATERIAL=============" << endl;
	cout << "Ingrese el Numero de Clasificacion: ";
	cin >> numClasi;
	cout << "Ingrese el Numero de Catalago: ";
	cin >> numCata;
	cin.ignore(); // Ignorar el salto de línea después de leer numCata

	cout << "Ingrese el Titulo: ";
	getline(cin, titulo);
	cout << "Ingrese el autor: ";
	getline(cin, autor);
	cout << "Ingrese la Palabra Claves: ";
	getline(cin, palbClav);
	cout << "Ingrese el estado del Material(Bueno|Regular|Malo): ";
	getline(cin, estado);

	cout << "Ingrese el Tipo de Material: " << endl;
	cout << "('L'=Libro|'R'=Revistas|'A'=Articulo|'V'=Video|'D'=Material Digital): ";
	cin >> tipMaterial;

	switch (toupper(tipMaterial)) 
	{
	case 'L'://Realiza la creacion de un obj Libro
		cin.ignore(); 
		cout << "Ingrese la Ubicacion Fisica: ";
		getline(cin, ubiFisica); 
		return new Libro(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, ubiFisica);
	case 'R'://Realiza la creacion de una objt Revista
		cout << "Ingrese el Numero de Revista: "; cin >> numRev; 
		cout << "Ingrese el Volumen: "; cin >> volumen; 
		cin.ignore(); 
		cout << "Ingrese la Ubicacion Fisica: ";
		getline(cin, ubiFisica);
		return new Revista(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, numRev, volumen, ubiFisica);
	case 'V'://Realiza la creacion de un obj Video
		cin.ignore(); 
		cout << "Ingrese la Duracion del video: ";
		getline(cin, duracion);
		cout << "Ingrese la Formato del video(MP4, MPG, MOV): ";
		getline(cin, formato);
		return new Video(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, duracion, formato);
	case 'D'://Realiza la creacion de un obj MaterialDigital
		cin.ignore();
		cout << "Ingrese la Formato (CD, DVD, BluRay): ";
		getline(cin, formato);
		cout << "Ingrese el tipo(Fisico|Linea): ";
		getline(cin, tipo);
		cout << "Indique su acceso en Linea(1=True/Activo, 0=Flase/No Activo): "; cin >> accLinea;
		return new MaterialDigital(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, formato, tipo, accLinea);
	case 'A'://Realiza la creacion de un obj Articulo
		cin.ignore();
		cout << "Ingrese la Publicacion del Articulo: ";
		getline(cin, publicacion);
		cout << "Ingrese la Fecha Publicacion del Articulo: ";
		getline(cin, fechaPubli);
		return new Articulo(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, publicacion, fechaPubli);
	default:
		break;
	}

	return nullptr;
}

Usuario* Interfaz::crearUsuario()
{
	system("cls");

	string id, nomb;
	int actv;
	cout << "==========CREACION DE USUARIO=============" << endl;
	cout << "Ingrese si es Activo(1=True/Activo, 0=Flase/No Activo): "; cin >> actv;
	cin.ignore();
	cout << "Ingrese el Id: "; getline(cin, id);
	cout << "Ingrese el Nombre: "; getline(cin, nomb);

	return new Usuario(id, nomb, actv);
}

bool Interfaz::modicarUsuario(Biblioteca& b)
{
	system("cls");

	cout << "==========Modificacion DE USUARIO=============" << endl;
	return false;
}

void Interfaz::mensajeIngresoExitoso()
{
	cout << "Proceso realizado exitosamente\n" << endl;
	cout << "Toque \"enter\" para volver al menu\n" << endl;
	system("pause");
}

void Interfaz::mensajeErrorIngreso()
{
	cout << "Ha ocurrido un error en el proceso\n";
	cout << "Toque \"enter\" para volver al menu\n" << endl;
	system("pause");
}
