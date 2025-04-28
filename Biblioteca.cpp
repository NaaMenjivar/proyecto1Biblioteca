#include "Biblioteca.h"

Biblioteca::Biblioteca()
{//Encargado de crear las listas y sus manejos
    materiales = new ListaMateriales();
    usuarios = new ListaUsuarios();
    prestamos = new GestorPrestamos(); 
    reportes = new Reportes();
}

Biblioteca::~Biblioteca()  
{//Encargado de borrar las listas
    if (materiales)
        delete materiales;
    if (usuarios)
        delete usuarios;
    if (prestamos)
        delete prestamos;
    if (reportes)
        delete reportes;
}

bool Biblioteca::ingresarMateriales(Material& m)
{
    return materiales->agregarMateriales(m);
}

bool Biblioteca::ingresarUsuarios(Usuario& u)
{
    return usuarios->agregarUsuarios(u);
}

bool Biblioteca::ingresarPrestamos(Prestamo& p)
{
    return prestamos->agregarPrestamo(p);
}

Material* Biblioteca::getMaterial(int tipMat)
{
    return materiales->obtenerMaterial(tipMat);
}

Usuario* Biblioteca::getUsuarios(string idUs)
{
    return usuarios->obtenerUsuario(idUs);
}

Prestamo* Biblioteca::getPrestamo(int numPe)
{
    return prestamos->obtenerPrestamo(numPe);
}

string Biblioteca::reporteInvtMariales()
{
    return reportes->repInventarioMaterial(*materiales); 
}

string Biblioteca::reporteMatEspecifico(char tip)
{
    return reportes->repMaterialEspecif(*materiales, tip);
}

string Biblioteca::reporteUsuarios()
{
    return reportes->repUsuarios(*usuarios); 
}

string Biblioteca::reportePrestamos()
{
    return reportes->repPrestamos(*prestamos);
}

string Biblioteca::reportePrestamosxMat(char tipo)
{
    return reportes->repPresxMat(*prestamos, tipo);
}

string Biblioteca::reportePrestamosxUsr(string id)
{
    return reportes->repPresxUsr(*prestamos, id);;
}

void Biblioteca::eliminacionMaterial(int numCat)
{
    materiales->eliminarMaterial(numCat);
}

void Biblioteca::eliminacionUsuario(string idUsr)
{
    usuarios->eliminarUsuario(idUsr);
}

bool Biblioteca::devolucionMaterial(int numPre)
{
    return prestamos->eliminarPrestamo(numPre);
}

void Biblioteca::guardarMateriales()
{
    std::ofstream file;
    file.open("Materiales.txt", ios::out);
    materiales->guardar(file);
    file.close();
}

void Biblioteca::cargarMateriales()
{
    std::ifstream file;
    file.open("Materiales.txt");
    if (!file.is_open()) {
        cout << "no se pudo abrir el archivo\n";
        return;
    }

    string tipoMat;
    while (getline(file, tipoMat)) {
        if (tipoMat.empty())
            continue;

        Material* material = nullptr;
        if (tipoMat == "L" || tipoMat == "l") {
            material = Libro::cargar(file);
        }
        else if (tipoMat == "A" || tipoMat == "a") {
            material = Articulo::cargar(file);
        }
        else if (tipoMat == "R" || tipoMat == "r") {
            material = Revista::cargar(file); 
        }
        else if (tipoMat == "V" || tipoMat == "v") { 
            material = Video::cargar(file); 
        }
        else if (tipoMat == "D" || tipoMat == "d") { 
            material = MaterialDigital::cargar(file); 
        }

        if (!material) 
            continue;

        if (!materiales->agregarMateriales(*material)) { 
            delete material; 
        }
    }
    file.close();
}

void Biblioteca::guardarUsuarios()
{
    std::ofstream file;
    file.open("Usuarios.txt", ios::out);
    usuarios->guardar(file); 
    file.close(); 
}

void Biblioteca::cargarUsuarios()
{
    std::ifstream file;
    file.open("Usuarios.txt", ios::in);
    if (!file.is_open()) {
        cout << "no se pudo abrir el archivo\n";
        return;
    }

    while (!file.eof()) {
        Usuario* us = Usuario::cargar(file);
        if (!us)
            continue;

        if (!usuarios->agregarUsuarios(*us)) {
            delete us;
        }
    }
    file.close();
}

void Biblioteca::guardarPrestamos()
{
    std::ofstream file; 
    file.open("Prestamos.txt", ios::out);
    prestamos->guardar(file); 
    file.close();
}

void Biblioteca::cargarPrestamos()
{
    std::ifstream file; 
    file.open("Prestamos.txt", ios::in); 
    if (!file.is_open()) { 
        cout << "no se pudo abrir el archivo\n";
        return;
    }

    string usr, mat, num, fchI;
    while (file >> usr >> mat >> num >> fchI)
    {
        if (usr.empty()) 
            continue;

        int numCat = conversionInt(mat);  // Convierte el numero de catalogo en int 
        int numPres = conversionInt(num); // Convierte el numero de prestamo en int 

        Usuario* usuario = usuarios->obtenerUsuario(usr); 
        if (!usuario) 
            continue;

        Material* material = materiales->obtenerMaterial(numCat); 
        if (!material) 
            continue;

        Prestamo* prest = new Prestamo(*usuario, *material, numPres, fchI); 

        if (!prestamos->agregarPrestamo(*prest)) { 
            delete prest; 
        }
    }
    file.close(); 
}
 