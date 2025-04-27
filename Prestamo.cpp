#include "Prestamo.h"

Prestamo::Prestamo(Usuario& u, Material& m, int n, string fI)
{
    this->numeroPrestamo = n;
    this->usuario = (Usuario*)&u;
    this->material = (Material*)&m;
    this->fechaInicio = fI;
    //Define la fecha final sumando los dias segun el tipo de material usando la funcion sumarDiasxPrestamo()
    this->fechaFin = sumarDiasxPrestamo(fechaInicio, getTipoMaterial()); 
}

Prestamo::~Prestamo() {}

//Acceso
int Prestamo::getNumeroPrestamo() { return numeroPrestamo; }
Usuario* Prestamo::getUsuario() { return usuario; }
string Prestamo::getIdUsuario() { return usuario->getId(); }
char Prestamo::getTipoMaterial() { return material->getTipoMaterial(); };
Material* Prestamo::getMaterial() { return material; }
string Prestamo::getFechaInicio() { return fechaInicio; }
string Prestamo::getFechaFin() { return fechaFin; }

//Setteo
void Prestamo::setNumeroPrestamo(int n) { numeroPrestamo = n; }
void Prestamo::setUsuario(Usuario* u) { usuario = u; }
void Prestamo::setMaterial(Material* m) { material = m; }
void Prestamo::setFechaInicio(string fI) { fechaInicio = fI; }
void Prestamo::setFechaFin(string fF) { fechaFin = sumarDiasxPrestamo(fechaInicio, getTipoMaterial());} 

//toString
string Prestamo::toString() const {
    stringstream s;
    s << "Numero de prestamo: " << numeroPrestamo << "\n";
    s << "ID de usuario: " << usuario->getId() << "\n";
    if ((material->getTipoMaterial() == 'L' || material->getTipoMaterial() == 'l')) {
        s << "Tipo de material: Libro" << "\n";
    }
    if ((material->getTipoMaterial() == 'A' || material->getTipoMaterial() == 'A')) {
        s << "Tipo de material: Articulo" << "\n";
    }
    if ((material->getTipoMaterial() == 'R' || material->getTipoMaterial() == 'r')) {
        s << "Tipo de material: Revista" << "\n";
    }
    if ((material->getTipoMaterial() == 'V' || material->getTipoMaterial() == 'v') ) { 
        s << "Tipo de material: Video" << "\n";
    }
    if ((material->getTipoMaterial() == 'D' || material->getTipoMaterial() == 'd')) {
        s << "Tipo de material: Material Digital" << "\n";
    }
    s << "Numero de catalogo del material: " << material->getNumCatalogo() << "\n";
    s << "Fecha de inicio: " << fechaInicio << "\n";
    s << "Fecha de finalizacion: " << fechaFin << "\n";

    return s.str();
}

void Prestamo::guardar(std::ofstream& file)
{
    file << usuario->getId() << '\t';
    file << material->getNumCatalogo() << '\t'; 
    file << numeroPrestamo << '\t'; 
    file << fechaInicio << '\n'; 
}
