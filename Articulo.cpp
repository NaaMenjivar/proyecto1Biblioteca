#include "Articulo.h"

Articulo::Articulo(int c, int ct, string t, string a, string pC, string ty, string s, string rP, string fP) 
    : Material(c, ct, t, a, pC, ty, s), revistaPublicacion(rP), fechaPublicacion(fP) {}
Articulo::~Articulo() {}

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
