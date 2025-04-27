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
	cout << "=>Ingrese su respuesta: ";
	op = Interfaz::ingresarInt(1, 5);

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
	cout << "=>Ingrese su respuesta: ";
	op = Interfaz::ingresarInt(1, 5);

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
	cout << "=>ngrese su respuesta: ";
	op = Interfaz::ingresarInt(1, 3);

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
	cout << "=>Ingrese su respuesta: ";
	op = Interfaz::ingresarInt(1, 6);

	return op;
}

bool Interfaz::menuOpModificacionMaterial(Biblioteca& b, Material* m, char tip)
{
	Material* nuevoMaterial = nullptr;
	int numClasi, numCata, numRev, volumen, accLinea, op;
	string titulo, autor, palbClav, estado, ubiFisica, duracion, formato, tipo, publicacion, fechaPubli; 

	cout << "==========OPCIONES DE MODIFICACION==========" << endl;
	cout << "1.Todos los atributos." << endl;
	cout << "2.Su atributo propio (Clase derivada)." << endl;
	cout << "=>Ingresa la opcion: "; cin >> op;

	if ((tip == 'L' || tip == 'l') && dynamic_cast<Libro*>(m)) {
		Libro* libro = dynamic_cast<Libro*>(m);
		switch (op)
		{
		case 1:
			cout << "=>Ingrese el Numero de Clasificacion: ";
			numClasi = Interfaz::ingresarInt(1);

			cout << "=>Ingrese el Numero de Catalago: ";
			cin >> numCata;
			cin.ignore(); // Ignorar el salto de línea después de leer numCata
			cout << "=>Ingrese el Titulo: ";
			getline(cin, titulo);
			cout << "=>Ingrese el autor: ";
			getline(cin, autor);
			cout << "=>Ingrese la Palabra Claves: ";
			getline(cin, palbClav);
			cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
			getline(cin, estado);
			cout << "=>Ingrese la Ubicacion Fisica: ";
			getline(cin, ubiFisica);
			libro->setGeneral(numClasi, numCata, titulo, autor, palbClav, estado);
			libro->setUbicacionFisica(ubiFisica);
			nuevoMaterial = libro;
			return b.ingresarMateriales(*nuevoMaterial);
		case 2:
			cin.ignore();
			cout << "=>Ingrese la Ubicacion Fisica: ";
			getline(cin, ubiFisica);
			libro->setUbicacionFisica(ubiFisica);
			nuevoMaterial = libro;
			return b.ingresarMateriales(*nuevoMaterial);
		default:
			return false;
		}
	}
	if ((tip == 'A' || tip == 'a') && dynamic_cast<Articulo*>(m)) {
		Articulo* articulo = dynamic_cast<Articulo*>(m);
		switch (op) 
		{
		case 1:
			cout << "=>Ingrese el Numero de Clasificacion: ";
			cin >> numClasi;
			cout << "=>Ingrese el Numero de Catalago: ";
			cin >> numCata;
			cin.ignore(); // Ignorar el salto de línea después de leer numCata
			cout << "=>Ingrese el Titulo: ";
			getline(cin, titulo);
			cout << "=>Ingrese el autor: ";
			getline(cin, autor);
			cout << "=>Ingrese la Palabra Claves: ";
			getline(cin, palbClav);
			cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
			getline(cin, estado);
			cout << "=>Ingrese la Publicacion del Articulo: ";
			getline(cin, publicacion);
			cout << "=>Ingrese la Fecha Publicacion del Articulo: ";
			getline(cin, fechaPubli);
			articulo->setGeneral(numClasi, numCata, titulo, autor, palbClav, estado);
			articulo->setRevistaPublicacion(publicacion);
			articulo->setFechaPublicacion(fechaPubli);
			nuevoMaterial = articulo;
			return b.ingresarMateriales(*nuevoMaterial);
		case 2:
			cin.ignore(); 
			cout << "=>Ingrese la Publicacion del Articulo: ";
			getline(cin, publicacion);
			cout << "=>Ingrese la Fecha Publicacion del Articulo: ";
			getline(cin, fechaPubli);
			articulo->setRevistaPublicacion(publicacion);
			articulo->setFechaPublicacion(fechaPubli);
			nuevoMaterial = articulo;
			return b.ingresarMateriales(*nuevoMaterial);
		default:
			return false;
		}
	}
	if ((tip == 'R' || tip == 'r') && dynamic_cast<Revista*>(m)) {
		Revista* revista = dynamic_cast<Revista*>(m); 
		switch (op)
		{
		case 1:
			cout << "=>Ingrese el Numero de Clasificacion: ";
			cin >> numClasi;
			cout << "=>Ingrese el Numero de Catalago: ";
			cin >> numCata;
			cin.ignore(); // Ignorar el salto de línea después de leer numCata
			cout << "=>Ingrese el Titulo: ";
			getline(cin, titulo);
			cout << "=>Ingrese el autor: ";
			getline(cin, autor);
			cout << "=>Ingrese la Palabra Claves: ";
			getline(cin, palbClav);
			cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
			getline(cin, estado);
			cout << "=>Ingrese el Numero de Revista: "; cin >> numRev;
			cout << "=>Ingrese el Volumen: "; cin >> volumen;
			cin.ignore();
			cout << "=>Ingrese la Ubicacion Fisica: ";
			getline(cin, ubiFisica);
			revista->setGeneral(numClasi, numCata, titulo, autor, palbClav, estado);
			revista->setNumero(numRev);
			revista->setVolumen(volumen);
			revista->setUbicacionFisica(ubiFisica);
			nuevoMaterial = revista; 
			return b.ingresarMateriales(*nuevoMaterial);
		case 2:
			cout << "=>Ingrese el Numero de Revista: "; cin >> numRev;
			cout << "=>Ingrese el Volumen: "; cin >> volumen;
			cin.ignore();
			cout << "=>Ingrese la Ubicacion Fisica: ";
			getline(cin, ubiFisica);
			revista->setNumero(numRev);
			revista->setVolumen(volumen);
			revista->setUbicacionFisica(ubiFisica);
			nuevoMaterial = revista;
			return b.ingresarMateriales(*nuevoMaterial);
		default:
			return false;
		}
	}
	if ((tip == 'V' || tip == 'v') && dynamic_cast<Video*>(m)) {
		Video* video = dynamic_cast<Video*>(m);
		switch (op)
		{
		case 1:
			cout << "=>Ingrese el Numero de Clasificacion: ";
			cin >> numClasi;
			cout << "=>Ingrese el Numero de Catalago: ";
			cin >> numCata;
			cin.ignore(); // Ignorar el salto de línea después de leer numCata
			cout << "=>Ingrese el Titulo: ";
			getline(cin, titulo);
			cout << "=>Ingrese el autor: ";
			getline(cin, autor);
			cout << "=>Ingrese la Palabra Claves: ";
			getline(cin, palbClav);
			cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
			getline(cin, estado);
			cout << "=>Ingrese la Duracion del video: ";
			getline(cin, duracion);
			cout << "=>Ingrese la Formato del video(MP4, MPG, MOV): ";
			getline(cin, formato);
			video->setGeneral(numClasi, numCata, titulo, autor, palbClav, estado);
			video->setDuracion(duracion);
			video->setFormato(formato);
			nuevoMaterial = video; 
			return b.ingresarMateriales(*nuevoMaterial);
		case 2:
			cin.ignore();
			cout << "=>Ingrese la Duracion del video: ";
			getline(cin, duracion);
			cout << "=>Ingrese la Formato del video(MP4, MPG, MOV): ";
			getline(cin, formato);
			video->setDuracion(duracion); 
			video->setFormato(formato); 
			nuevoMaterial = video;
			return b.ingresarMateriales(*nuevoMaterial);
		default:
			return false;
		}
	}
	if ((tip == 'D' || tip == 'd') && dynamic_cast<MaterialDigital*>(m)) {
		MaterialDigital* mDigital = dynamic_cast<MaterialDigital*>(m); 
		switch (op)
		{
		case 1:
			cout << "=>Ingrese el Numero de Clasificacion: ";
			cin >> numClasi;
			cout << "=>Ingrese el Numero de Catalago: ";
			cin >> numCata;
			cin.ignore(); // Ignorar el salto de línea después de leer numCata
			cout << "=>Ingrese el Titulo: ";
			getline(cin, titulo); 
			cout << "=>Ingrese el autor: ";
			getline(cin, autor); 
			cout << "=>Ingrese la Palabra Claves: ";
			getline(cin, palbClav); 
			cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
			getline(cin, estado);
			cout << "=>Ingrese la Formato (CD, DVD, BluRay): "; 
			getline(cin, formato); 
			cout << "=>Ingrese el tipo(Fisico|Linea): ";
			getline(cin, tipo); 
			cout << "=>Indique su acceso en Linea(1=True/Activo, 0=Flase/No Activo): "; cin >> accLinea; 
			mDigital->setGeneral(numClasi, numCata, titulo, autor, palbClav, estado);
			mDigital->setFormato(formato);
			mDigital->setTipo(tipo);
			mDigital->setAccesoEnLinea(accLinea);
			nuevoMaterial = mDigital;  
			return b.ingresarMateriales(*nuevoMaterial);
		case 2:
			cin.ignore(); 
			cout << "=>Ingrese la Formato (CD, DVD, BluRay): ";
			getline(cin, formato); 
			cout << "=>Ingrese el tipo(Fisico|Linea): ";
			getline(cin, tipo); 
			cout << "=>Indique su acceso en Linea(1=True/Activo, 0=Flase/No Activo): "; cin >> accLinea;
			mDigital->setFormato(formato);
			mDigital->setTipo(tipo);
			mDigital->setAccesoEnLinea(accLinea);
			nuevoMaterial = mDigital; 
			return b.ingresarMateriales(*nuevoMaterial);
		default:
			return false;
		}
	}
	return false;
}

bool Interfaz::menuOpModificacionUsr(Biblioteca& b, Usuario* u)
{
	int op, act;
	string id, nom;
	
	cout << "==========OPCIONES DE MODIFICACION==========" << endl;
	cout << "1.Todos los atributos." << endl;
	cout << "2.Estado de usuario." << endl;
	cout << "3.ID de usuario." << endl;
	cout << "4.Nombre de usuario." << endl;
	cout << "Ingresa la opcion: "; cin >> op;
	cin.ignore(); 

	switch (op) 
	{
	case 1:
		cout << "=>Ingrese si es Activo(1=True/Activo, 0=Flase/No Activo): "; cin >> act;
		cin.ignore();
		cout << "=>Ingrese el Id: "; getline(cin, id);
		cout << "=> el Nombre: "; getline(cin, nom);
		u->setActivo(act);
		u->setId(id);
		u->setNombre(nom);
		return b.ingresarUsuarios(*u);
	case 2:
		cout << "=>Ingrese si es Activo(1=True/Activo, 0=Flase/No Activo): "; cin >> act; 
		cin.ignore();
		u->setActivo(act); 
		return b.ingresarUsuarios(*u); 
	case 3:
		cout << "=>Ingrese el Id: "; getline(cin, id);
		u->setId(id);
		return b.ingresarUsuarios(*u);
	case 4:
		cout << "=>Ingrese el Nombre: "; getline(cin, nom);
		u->setNombre(nom); 
		return b.ingresarUsuarios(*u); 
	default:
		return false; 
	}
}

Material* Interfaz::crearMaterial()
{
	system("cls");
	//Variables para la construccion de obj Material
	int numClasi, numCata, numRev, volumen, accLinea; 
	string titulo, autor, palbClav, estado, ubiFisica, duracion, formato, tipo, publicacion, fechaPubli;
	char tipMaterial;

	cout << "==========CREACION DE UN MATERIAL==========" << endl;
	cout << "=>Ingrese el Numero de Clasificacion: ";
	cin >> numClasi;
	cout << "Ingrese el Numero de Catalago: ";
	cin >> numCata;
	cin.ignore(); // Ignorar el salto de l�nea despu�s de leer numCata

	cout << "=>Ingrese el autor: ";
	getline(cin, autor);
	cout << "=>Ingrese la Palabra Claves: ";
	getline(cin, palbClav);
	cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
	getline(cin, estado);
	cout << "=>Ingrese el Tipo de Material: " << endl;
	cout << "('L'=Libro|'R'=Revistas|'A'=Articulo|'V'=Video|'D'=Material Digital): ";
	cin >> tipMaterial;

	switch (toupper(tipMaterial)) 
	{
	case 'L'://Realiza la creacion de un obj Libro
		cin.ignore(); 
		cout << "=>Ingrese la Ubicacion Fisica: ";
		getline(cin, ubiFisica); 
		return new Libro(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, ubiFisica);
	case 'R'://Realiza la creacion de una objt Revista
		cout << "=>Ingrese el Numero de Revista: "; cin >> numRev; 
		cout << "=>Ingrese el Volumen: "; cin >> volumen; 
		cin.ignore(); 
		cout << "=>Ingrese la Ubicacion Fisica: ";
		getline(cin, ubiFisica);
		return new Revista(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, numRev, volumen, ubiFisica);
	case 'V'://Realiza la creacion de un obj Video
		cin.ignore(); 
		cout << "=>Ingrese la Duracion del video: ";
		getline(cin, duracion);
		cout << "=>Ingrese la Formato del video(MP4, MPG, MOV): ";
		getline(cin, formato);
		return new Video(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, duracion, formato);
	case 'D'://Realiza la creacion de un obj MaterialDigital
		cin.ignore();
		cout << "=>Ingrese la Formato (CD, DVD, BluRay): ";
		getline(cin, formato);
		cout << "=>Ingrese el tipo(Fisico|Linea): ";
		getline(cin, tipo);
		return new MaterialDigital(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, formato, tipo);
	case 'A'://Realiza la creacion de un obj Articulo
		cin.ignore();
		cout << "=>Ingrese la Publicacion del Articulo: ";
		getline(cin, publicacion);
		cout << "=>Ingrese la Fecha Publicacion del Articulo: ";
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
	cout << "=>Ingrese si es Activo(1=True/Activo, 0=Flase/No Activo): "; cin >> actv;
	cin.ignore();
	cout << "=>Ingrese el Id: "; getline(cin, id);
	cout << "=>Ingrese el Nombre: "; getline(cin, nomb);

	return new Usuario(id, nomb, actv);
}

bool Interfaz::modicarUsuario(Biblioteca& b)
{
	system("cls");

	string idUsr;
	Usuario* newUsr = nullptr;
	cout << "==========MODIFICACION DE USUARIO==========" << endl;
	string reporte = b.reporteUsuarios();
	if (reporte.empty()) {
		cout << "Aun no hay usuarios ingresados." << endl;
		cout << "Presione enter para volver." << endl;
		system("pause");
	return false;
}

void Interfaz::reporteInvMaterial(Biblioteca& b)
{
	system("cls");
	cout << "Materiales ingresados:\n";
	if (b.reporteInvtMariales() == "") {
		cout << "Aun no se pueden visualizar los materiales, no hay registrados." << endl;
		cout << "Toque \"enter\" para volver el Submenu Reportes" << endl;
		system("pause");
		return;
	}
	cout << b.reporteInvtMariales() << endl;
	system("pause");
}

void Interfaz::reportdeUsuarios(Biblioteca& b)
{
	system("cls");
	cout << "Usuarios registrados:\n";
	if (b.reporteUsuarios().empty()) {
		cout << "Aun no se pueden visualizar los usuarios, no hay registrados." << endl;
		cout << "Toque \"enter\" para volver el Submenu Reportes" << endl;
		system("pause");
		return;
	}
	cout << b.reporteUsuarios() << endl;
	system("pause");
}

void Interfaz::reportedePrestamos(Biblioteca& b)
{
	system("cls");
	cout << "Prestamos registrados:\n";
	if (b.reportePrestamos().empty()) {
		cout << "Aun no se pueden visualizar los pretamos, no hay registrados." << endl;
		cout << "Toque \"enter\" para volver el Submenu Reportes" << endl;
		system("pause");
		return;
	}
	cout << b.reportePrestamos() << endl;
	system("pause");
}

void Interfaz::reportedePrestamosxMat(Biblioteca& b)
{
	system("cls");
	char tipo;
	cout << "=====REPORTE PRESTAMOS POR TIPO DE MATERIAL=====\n";
	cout << "Indique el tipo de material" << endl;;
	cout << "('L'=Libro|'R'=Revistas|'A'=Articulo|'V'=Video|'D'=Material Digital): ";
	cin >> tipo;
	if (b.reportePrestamosxMat(tipo).empty()) { 
		cout << "No hay prestamos creados con el tipo de material selecionado\n";
		cout << "Toque \"enter\" para volver el Submenu Busquedas y Listados" << endl;
		system("pause");
		return;
	}
	cout << b.reportePrestamosxMat(tipo) << endl; 
	system("pause");
}

void Interfaz::reportedePrestamosxUsr(Biblioteca& b)
{
	system("cls");
	string id;
	cout << "=====REPORTE PRESTAMOS POR USUARIO=====\n";
	if (b.reporteUsuarios().empty()) {
		cout << "Aun no se pueden visualizar los prestamos, no hay registrados.\n";
		cout << "Toque \"enter\" para volver el Submenu Busquedas y Listados" << endl;
		system("pause");
		return;
	}
	cout << "Usuarios registrados:" << endl;
	cout << b.reporteUsuarios(); 
	cout << "Ingrese el id del Id del Usuario para ver sus prestamos: "; cin >> id;
	if (b.reportePrestamosxUsr(id).empty()) {
		cout << "No hay prestamos creados con el usuario selecionado\n";
		cout << "Toque \"enter\" para volver el Submenu Busquedas y Listados" << endl;
		system("pause");
		return;
	}
	cout << b.reportePrestamosxUsr(id) << endl; 
	system("pause");
}

void Interfaz::mensajeIngresoExitoso()
{
	cout << "Proceso realizado exitosamente\n";
	cout << "Toque \"enter\" para volver al menu\n" << endl;
	system("pause");
}

void Interfaz::mensajeErrorIngreso()
{
	cout << "Ha ocurrido un error en el proceso\n";
	cout << "Toque \"enter\" para volver al menu\n" << endl;
	system("pause");
}

void Interfaz::msjDevolucionExitoso()
{
	cout << "Se ha realizo la devolucion exitosamente\n";
	cout << "Toque \"enter\" para volver al menu\n" << endl;
	system("pause");
}

void Interfaz::msjErrorDevolucion()
{
	cout << "Ha ocurrido un error en la devolucion\n";
	cout << "Toque \"enter\" para volver al menu\n" << endl;
	system("pause");
}

void Interfaz::msjGuardado()
{
	cout << "Datos guardados..." << endl;
	cout << "Toque \"enter\" para volver al menu\n" << endl;
	system("pause"); 
}
