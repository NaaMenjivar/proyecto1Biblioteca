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
	cout << "=>Ingresa la opcion: ";
	op = Interfaz::ingresarInt(1, 2);

	if ((tip == 'L' || tip == 'l') && dynamic_cast<Libro*>(m)) {
		Libro* libro = dynamic_cast<Libro*>(m);
		switch (op)
		{
		case 1:
			cout << "=>Ingrese el Numero de Clasificacion: ";
			numClasi = Interfaz::ingresarInt(1);

			cout << "=>Ingrese el Numero de Catalago: ";
			numCata = Interfaz::ingresarInt(1);
			cin.ignore(); 

			cout << "=>Ingrese el Titulo: ";
			cin.ignore(1, '\n');
			getline(cin, titulo, '\n'); 

			cout << "=>Ingrese el autor: ";
			getline(cin, autor, '\n');

			cout << "=>Ingrese la Palabra Claves: ";
			getline(cin, palbClav, '\n');

			cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
			getline(cin, estado, '\n');

			cout << "=>Ingrese la Ubicacion Fisica: ";
			getline(cin, ubiFisica, '\n');

			libro->setGeneral(numClasi, numCata, titulo, autor, palbClav, estado);
			libro->setUbicacionFisica(ubiFisica);
			nuevoMaterial = libro;
			return b.ingresarMateriales(*nuevoMaterial);
		case 2:
			cin.ignore();
			cout << "=>Ingrese la Ubicacion Fisica: ";
			getline(cin, ubiFisica, '\n');

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
			numClasi = Interfaz::ingresarInt(1);

			cout << "=>Ingrese el Numero de Catalago: ";
			numCata = Interfaz::ingresarInt(1);
			cin.ignore();

			cout << "=>Ingrese el Titulo: ";
			cin.ignore(1, '\n');
			getline(cin, titulo, '\n');

			cout << "=>Ingrese el autor: ";
			getline(cin, autor, '\n');

			cout << "=>Ingrese la Palabra Claves: ";
			getline(cin, palbClav, '\n');

			cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
			getline(cin, estado, '\n');

			cout << "=>Ingrese la Publicacion del Articulo: ";
			getline(cin, publicacion, '\n');

			cout << "=>Ingrese la Fecha Publicacion del Articulo: ";
			getline(cin, fechaPubli, '\n');

			articulo->setGeneral(numClasi, numCata, titulo, autor, palbClav, estado);
			articulo->setRevistaPublicacion(publicacion);
			articulo->setFechaPublicacion(fechaPubli);
			nuevoMaterial = articulo;
			return b.ingresarMateriales(*nuevoMaterial);
		case 2:
			cin.ignore(); 
			cout << "=>Ingrese la Publicacion del Articulo: ";
			getline(cin, publicacion, '\n');

			cout << "=>Ingrese la Fecha Publicacion del Articulo: ";
			getline(cin, fechaPubli, '\n');

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
			numClasi = Interfaz::ingresarInt(1);

			cout << "=>Ingrese el Numero de Catalago: ";
			numCata = Interfaz::ingresarInt(1);
			cin.ignore();

			cout << "=>Ingrese el Titulo: ";
			cin.ignore(1, '\n');
			getline(cin, titulo, '\n');

			cout << "=>Ingrese el autor: ";
			getline(cin, autor, '\n');

			cout << "=>Ingrese la Palabra Claves: ";
			getline(cin, palbClav, '\n');

			cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
			getline(cin, estado, '\n');

			cout << "=>Ingrese el Numero de Revista: ";
			numRev = Interfaz::ingresarInt(1);

			cout << "=>Ingrese el Volumen: ";
			volumen = Interfaz::ingresarInt(1);
			cin.ignore();

			cout << "=>Ingrese la Ubicacion Fisica: ";
			getline(cin, ubiFisica, '\n');

			revista->setGeneral(numClasi, numCata, titulo, autor, palbClav, estado);
			revista->setNumero(numRev);
			revista->setVolumen(volumen);
			revista->setUbicacionFisica(ubiFisica);
			nuevoMaterial = revista; 
			return b.ingresarMateriales(*nuevoMaterial);
		case 2:
			cout << "=>Ingrese el Numero de Revista: ";
			numRev = Interfaz::ingresarInt(1); 

			cout << "=>Ingrese el Volumen: ";
			volumen = Interfaz::ingresarInt(1);
			cin.ignore();

			cout << "=>Ingrese la Ubicacion Fisica: ";
			getline(cin, ubiFisica, '\n'); 

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
			numClasi = Interfaz::ingresarInt(1);

			cout << "=>Ingrese el Numero de Catalago: ";
			numCata = Interfaz::ingresarInt(1);
			cin.ignore();

			cout << "=>Ingrese el Titulo: ";
			cin.ignore(1, '\n');
			getline(cin, titulo, '\n');

			cout << "=>Ingrese el autor: ";
			getline(cin, autor, '\n');

			cout << "=>Ingrese la Palabra Claves: ";
			getline(cin, palbClav, '\n');

			cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
			getline(cin, estado, '\n');

			cout << "=>Ingrese la Duracion del video: ";
			getline(cin, duracion, '\n');

			cout << "=>Ingrese la Formato del video(MP4, MPG, MOV): ";
			getline(cin, formato, '\n');

			video->setGeneral(numClasi, numCata, titulo, autor, palbClav, estado);
			video->setDuracion(duracion);
			video->setFormato(formato);
			nuevoMaterial = video; 
			return b.ingresarMateriales(*nuevoMaterial);
		case 2:
			cin.ignore();
			cout << "=>Ingrese la Duracion del video: ";
			getline(cin, duracion, '\n');

			cout << "=>Ingrese la Formato del video(MP4, MPG, MOV): ";
			getline(cin, formato, '\n');

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
			numClasi = Interfaz::ingresarInt(1); 

			cout << "=>Ingrese el Numero de Catalago: ";
			numCata = Interfaz::ingresarInt(1); 
			cin.ignore(); 

			cout << "=>Ingrese el Titulo: ";
			cin.ignore(1, '\n');
			getline(cin, titulo, '\n');

			cout << "=>Ingrese el autor: ";
			getline(cin, autor, '\n');

			cout << "=>Ingrese la Palabra Claves: ";
			getline(cin, palbClav, '\n');

			cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
			getline(cin, estado, '\n');

			cout << "=>Ingrese la Formato (CD, DVD, BluRay): "; 
			getline(cin, formato, '\n');

			cout << "=>Ingrese el tipo(Fisico|Linea): ";
			getline(cin, tipo, '\n');

			cout << "=>Indique su acceso en Linea(1=True/Activo, 0=Flase/No Activo): "; 
			accLinea = Interfaz::ingresarInt(1);

			mDigital->setGeneral(numClasi, numCata, titulo, autor, palbClav, estado);
			mDigital->setFormato(formato);
			mDigital->setTipo(tipo);
			mDigital->setAccesoEnLinea(accLinea);
			nuevoMaterial = mDigital;  
			return b.ingresarMateriales(*nuevoMaterial);
		case 2:
			cin.ignore(); 
			cout << "=>Ingrese la Formato (CD, DVD, BluRay): ";
			getline(cin, formato, '\n');

			cout << "=>Ingrese el tipo(Fisico|Linea): ";
			getline(cin, tipo, '\n');

			cout << "=>Indique su acceso en Linea(1=True/Activo, 0=Flase/No Activo): ";
			accLinea = Interfaz::ingresarInt(0, 1);

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
	cout << "Ingresa la opcion: ";
	op = Interfaz::ingresarInt(1, 4);
	cin.ignore(); 

	switch (op) 
	{
	case 1:
		cout << "=>Ingrese si es Activo(1=True/Activo, 0=Flase/No Activo): ";
		act = Interfaz::ingresarInt(0, 1);

		cin.ignore();
		cout << "=>Ingrese el Id: "; getline(cin, id, '\n');

		cout << "=> el Nombre: "; getline(cin, nom, '\n');

		u->setActivo(act);
		u->setId(id);
		u->setNombre(nom);
		return b.ingresarUsuarios(*u);
	case 2:
		cout << "=>Ingrese si es Activo(1=True/Activo, 0=Flase/No Activo): ";
		act = Interfaz::ingresarInt(0, 1); 

		cin.ignore();
		u->setActivo(act); 
		return b.ingresarUsuarios(*u); 
	case 3:
		cout << "=>Ingrese el Id: "; getline(cin, id, '\n');

		u->setId(id);
		return b.ingresarUsuarios(*u);
	case 4:
		cout << "=>Ingrese el Nombre: "; getline(cin, nom, '\n');

		u->setNombre(nom); 
		return b.ingresarUsuarios(*u); 
	default:
		return false; 
	}
}

int Interfaz::ingresarInt(int min)
{
	int x;
	bool valido = true;
	do {
		try {
			valido = true; 
			cin >> x;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				valido = false; 
				throw(ExcValInvalido());
			}
			if (x < min) {
				valido = false; 
				throw(ExcValInf(min, x));
			}
		}
		catch (Excepcion& e) {
			cerr << "Error:" << e.porque() << endl;
			cin.ignore(1, '\n');
		}
		catch (const char* e) {
			cerr << e << endl;
		}
		catch (...) {
			cerr << "Error inesperado." << endl;
		}
	} while (!valido);
	return x;
}

int Interfaz::ingresarInt(int min, int max)
{
	int x;
	bool valido = true;
	do {
		try {
			valido = true;
			cin >> x;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				valido = false; 
				throw(ExcValInvalido());
			}
			if (x < min) {
				valido = false; 
				throw(ExcValInf(min, max, x));
			}
			if (x > max) {
				valido = false; 
				throw(ExcValSup(min, max, x));
			}
		}
		catch (Excepcion& e) {
			cerr << "Error: " << e.porque() << endl;
		}
		catch (...) {
			cerr << "Error inesperado." << endl;
		}
	} while (!valido); 
	return x;
}

string Interfaz::ingresarString()
{ 
	string s;
	getline(cin, s, '\n');
	return s;
}

char Interfaz::ingresarChar()
{
	char x;
	bool valido = true;
	do {
		try {
			valido = true;
			cin >> x;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
				valido = false;
				throw(ExcValInvalido());
			}
			// Verificar si es uno de los caracteres permitidos para los tipos de materiales
			if (x != 'L' && x != 'l' && x != 'R' && x != 'r' &&
				x != 'A' && x != 'a' && x != 'V' && x != 'v' &&
				x != 'D' && x != 'd') {
				valido = false;
				throw(ExcCharInvalido(x, "L, l, R, r, A, a, V, v, D, d"));
			}
		}
		catch (Excepcion& e) {
			cerr << "Error: " << e.porque() << endl;
			cin.ignore(100, '\n');
		}
		catch (const char* e) {
			cerr << e << endl;
		}
		catch (...) {
			cerr << "Error inesperado." << endl;
		}
	} while (!valido);
	return x;
}

Material* Interfaz::crearMaterial()
{
	system("cls");
	//Variables para la construccion de obj Material
	int numClasi, numCata, numRev, volumen; 
	string titulo, autor, palbClav, estado, ubiFisica, duracion, formato, tipo, publicacion, fechaPubli;
	char tipMaterial;

	cout << "==========CREACION DE UN MATERIAL==========" << endl;
	cout << "=>Ingrese el Numero de Clasificacion: ";
	numClasi = Interfaz::ingresarInt(1);

	cout << "=>Ingrese el Numero de Catalago: ";
	numCata = Interfaz::ingresarInt(1);
	cin.ignore();

	cout << "=>Ingrese el Titulo: ";
	cin.ignore(1, '\n');
	getline(cin, titulo, '\n');

	cout << "=>Ingrese el autor: ";
	getline(cin, autor, '\n');

	cout << "=>Ingrese la Palabra Claves: ";
	getline(cin, palbClav, '\n');

	cout << "=>Ingrese el estado del Material(Bueno|Regular|Malo): ";
	getline(cin, estado, '\n');

	cout << "=>Ingrese el Tipo de Material: " << endl;
	cout << "('L'=Libro|'R'=Revistas|'A'=Articulo|'V'=Video|'D'=Material Digital): ";
	tipMaterial = Interfaz::ingresarChar(); 

	switch (toupper(tipMaterial)) 
	{
	case 'L'://Realiza la creacion de un obj Libro
		cin.ignore(); 
		cout << "=>Ingrese la Ubicacion Fisica: ";
		getline(cin, ubiFisica, '\n');

		return new Libro(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, ubiFisica);
	case 'R'://Realiza la creacion de una objt Revista
		cout << "=>Ingrese el Numero de Revista: ";
		numRev = Interfaz::ingresarInt(1);

		cout << "=>Ingrese el Volumen: "; 
		volumen = Interfaz::ingresarInt(1);
		cin.ignore(); 

		cout << "=>Ingrese la Ubicacion Fisica: ";
		getline(cin, ubiFisica, '\n'); 

		return new Revista(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, numRev, volumen, ubiFisica);
	case 'V'://Realiza la creacion de un obj Video
		cin.ignore(); 
		cout << "=>Ingrese la Duracion del video: ";
		getline(cin, duracion, '\n');

		cout << "=>Ingrese la Formato del video(MP4, MPG, MOV): ";
		getline(cin, formato, '\n');

		return new Video(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, duracion, formato);
	case 'D'://Realiza la creacion de un obj MaterialDigital
		cin.ignore();
		cout << "=>Ingrese la Formato (CD, DVD, BluRay): ";
		getline(cin, formato, '\n');

		cout << "=>Ingrese el tipo(Fisico|Linea): ";
		getline(cin, tipo, '\n'); 

		return new MaterialDigital(tipMaterial, numClasi, numCata, titulo, autor, palbClav, estado, formato, tipo);
	case 'A'://Realiza la creacion de un obj Articulo
		cin.ignore();
		cout << "=>Ingrese la Publicacion del Articulo: ";
		getline(cin, publicacion, '\n');

		cout << "=>Ingrese la Fecha Publicacion del Articulo: ";
		getline(cin, fechaPubli, '\n');

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
	cout << "=>Ingrese si es Activo(1=True/Activo, 0=Flase/No Activo): ";
	actv = Interfaz::ingresarInt(1);;
	cin.ignore();

	cout << "=>Ingrese el Id: "; getline(cin, id, '\n');

	cout << "=>Ingrese el Nombre: "; getline(cin, nomb, '\n'); 

	return new Usuario(id, nomb, actv);
}

Prestamo* Interfaz::crearPrestamo(Biblioteca& b)
{
	system("cls");

	int numPre, numMatCat;
	string fechI, id; 
	char tipMaterial;
	Usuario* usr = nullptr;
	Material* mat = nullptr;
	cout << "==========CREACION DE PRESTAMO=============" << endl;
	cout << "=>Indique el tipo de Material que desea." << endl;;
	cout << "('L'=Libro|'R'=Revistas|'D'=Material Digital): ";
	tipMaterial = Interfaz::ingresarChar(); 

	string reporteMateriales = b.reporteMatEspecifico(tipMaterial);
	string reporteUsuarios = b.reporteUsuarios();

	if (reporteMateriales.empty() || reporteUsuarios.empty()) {
		cout << "Aun no hay Materiales o Usuarios registrados." << endl;
		cout << "Presione enter para volver." << endl; 
		system("pause"); 
		return nullptr;
	}

	cout << reporteMateriales;  
	cout << "=>Indique el numero de catalago del material: ";
	numMatCat = Interfaz::ingresarInt(1);
	mat = b.getMaterial(numMatCat);
	if (tipMaterial == 'd') {
		MaterialDigital* matD = dynamic_cast<MaterialDigital*>(mat);
		matD->setAccesoEnLinea(0); 
	}
	cin.ignore();
	cout << reporteUsuarios;
	cout << "=>Indique el ID del Usuario que desea: "; getline(cin, id, '\n'); 
	usr = b.getUsuarios(id);

	if (!usr || !mat) {
		cout << "El Material o el Usuario seleccionado no existen.\n";
		cout << "Presione enter para volver." << endl;
		system("pause");
		return nullptr;
	}

	cout << "=>Indique el numero para el prestamo: ";
	numPre = Interfaz::ingresarInt(1);
	cin.ignore();
	cout << "=>Indique la fecha de Inicio para el pretamo(DD/MM/YYYY): "; getline(cin, fechI, '\n'); 

	return new Prestamo(*usr, *mat, numPre, fechI);
}

bool Interfaz::devolucionPrestamo(Biblioteca& b)
{
	system("cls");

	int num;
	cout << "==========DEVOLUCION DE PRESTAMO=============" << endl;
	string reporte = b.reportePrestamos();
	if (reporte.empty()) {
		cout << "Aun no hay reportes registrados." << endl;
		cout << "Toque \"enter\" para volver." << endl;
		system("pause");
		return false;
	}
	cout << reporte;
	cout << "Ingrese el Numero de prestamo que desea para la devolucion: "; 
	num = Interfaz::ingresarInt(1);

	return b.devolucionMaterial(num);
}

bool Interfaz::modificarMaterial(Biblioteca& b)
{
	system("cls");

	int num;
	char tipMaterial;
	Material* nuevMaterial = nullptr; 
	cout << "==========MODIFICACION DE MATERIAL==========" << endl;
	cout << "Indique el tipo de material a modificar" << endl;;
	cout << "('L'=Libro|'R'=Revistas|'A'=Articulo|'V'=Video|'D'=Material Digital): ";
	tipMaterial = Interfaz::ingresarChar();

	string reporte = b.reporteMatEspecifico(tipMaterial);
	if (reporte.empty()) {
		cout << "Aun no hay materiales ingresados." << endl;
		cout << "Presione enter para volver." << endl;
		system("pause");
		return false;
	}

	cout << reporte;
	cout << "Indique el numero de catalago del material a modificar: "; 
	num = Interfaz::ingresarInt(1);
	nuevMaterial = b.getMaterial(num); 
	if (!nuevMaterial) {
		mensajeErrorIngreso();
		return false;
	}
	b.eliminacionMaterial(num);

	return menuOpModificacionMaterial(b, nuevMaterial, tipMaterial);
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
	cin.ignore(); 
	cout << reporte; 
	cout << "Indique el ID del usuario a modificar: "; getline(cin, idUsr, '\n'); 
	newUsr = b.getUsuarios(idUsr);
	if (!newUsr) {
		mensajeErrorIngreso();
		return false;
	}

	Usuario usuarioCopia = *newUsr;
	b.eliminacionUsuario(idUsr);
	
	return menuOpModificacionUsr(b, newUsr);       
}

void Interfaz::reporteInvMaterial(Biblioteca& b)
{
	system("cls");
	cout << "Materiales ingresados:\n";
	if (b.reporteInvtMariales().empty()) {
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
	cout << "('L'=Libro|'R'=Revistas|'D'=Material Digital): ";
	cin >> tipo;

	string reporte = b.reportePrestamosxMat(tipo);
	if (reporte.empty()) {
		cout << "No hay prestamos creados con el tipo de material seleccionado\n";
		cout << "Toque \"enter\" para volver el Submenu Busquedas y Listados" << endl;
		system("pause");
		return;
	}
	cout << "===================PRESTAMO=====================\n";
	cout << reporte << endl; 
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
	cin.ignore();
	cout << "Ingrese el id del Id del Usuario para ver sus prestamos: "; getline(cin, id); 
	if (b.reportePrestamosxUsr(id).empty()) {  
		cout << "No hay prestamos creados con el usuario selecionado\n";
		cout << "Toque \"enter\" para volver el Submenu Busquedas y Listados" << endl;
		system("pause");
		return;
	}
	cout << "===================PRESTAMO=====================\n"; 
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
