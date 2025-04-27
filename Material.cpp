#include "Material.h"

Material::Material(char tm, int c, int ct, string t, string a, string pC, string s)
    : tipoMaterial(tm), numeroClasificacion(c), numeroCatalogo(ct), titulo(t), autor(a), palabrasClave(pC), estado(s) {}
Material::~Material() {}

//Acceso
int Material::getNumClasificacion() { return this->numeroClasificacion; }
int Material::getNumCatalogo() { return this->numeroCatalogo; }
string Material::getTitulo() { return this->titulo; }
string Material::getAutor() { return this->autor; }
string Material::getPalabrasClave() { return this->palabrasClave; }
char Material::getTipoMaterial() { return this->tipoMaterial; }
string Material::getEstado() { return this->estado; }

//Setteo
void Material::setNumClasificacion(int c) { this->numeroClasificacion = c; }
void Material::setNumCatalogo(int ct) { this->numeroCatalogo = ct; }
void Material::setTitulo(string t) { this->titulo = t; }
void Material::setAutor(string a) { this->autor = a; }
void Material::setPalabrasClave(string pC) { this->palabrasClave = pC; }
void Material::setTipoMaterial(char tm) { this->tipoMaterial = tm; }
void Material::setEstado(string s) { this->estado = s; }

void Material::setGeneral(int c, int ct, string t, string a, string pC, string s)
{
    setNumClasificacion(c);
    setNumCatalogo(ct);
    setTitulo(t);
    setAutor(a);
    setPalabrasClave(pC);
    setEstado(s);
}

ostream& operator<<(ostream& os, const Material& m) 
{
    os << m.toString();
    return os;
}
