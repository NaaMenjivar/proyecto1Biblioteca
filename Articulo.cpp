#include "Articulo.h"
#include "Archivos.h"

Articulo::Articulo(char tm, int c, int ct, string t, string a, string pC, string s, string rP, string fP)
    : Material(tm, c, ct, t, a, pC, s), revistaPublicacion(rP), fechaPublicacion(fP) {
	this->persistencia = new PersistenciaArticulos();    
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
    s << Material::toString() << endl;
    s << "Revista de la publicacion: " << revistaPublicacion << endl;
    s << "Fecha de publicacion: " << fechaPublicacion << endl;

    return s.str();
}
