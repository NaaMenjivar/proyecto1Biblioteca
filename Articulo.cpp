#include "Articulo.h"
#include "Archivos.h"

Articulo::Articulo(char tm, int c, int ct, string t, string a, string pC, string s, string rP, string fP)
    : Material(tm, c, ct, t, a, pC, s), revistaPublicacion(rP), fechaPublicacion(fP) {
	this->persistencia = new PersistenciaArticulos();    
} 

Articulo::~Articulo() {
	if (persistencia)
		delete persistencia;
}

//Acceso
string Articulo::getRevistaPublicacion() { return revistaPublicacion; }
string Articulo::getFechaPublicacion() { return fechaPublicacion; }

//Setteo
void Articulo::setRevistaPublicacion(string rP) { revistaPublicacion = rP; }
void Articulo::setFechaPublicacion(string fP) { fechaPublicacion = fP; }

//toString
string Articulo::toString() const {
    stringstream s;
	s << "-------------------------------------------------" << "\n";
	s << "Tipo de material: Articulo" << "\n";
	s << "Numero de clasificacion: " << numeroClasificacion << "\n";
	s << "Numero de catalogo: " << numeroCatalogo << "\n";
	s << "Titulo: " << titulo << "\n";
	s << "Autor(es): " << autor << "\n";
	s << "Palabras clave: " << palabrasClave << "\n";
	s << "Estado del material: " << estado << "\n";
    s << "Publicacion de la Revista: " << revistaPublicacion << "\n";
    s << "Fecha de publicacion: " << fechaPublicacion << "\n";

    return s.str();
}

void Articulo::guardar(std::ofstream& file)
{
	persistencia->guardarMaterial(this, file);
}

Articulo* Articulo::cargar(std::ifstream& file)
{
	PersistenciaArticulos per;
	return per.cargarArticulo(file);
}
