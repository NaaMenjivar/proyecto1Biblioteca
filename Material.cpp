#include "Material.h"

Material::Material(char tm, int c, int ct, string t, string a, string pC, string s)
    : tipoMaterial(tm), numeroClasificacion(c), numeroCatalogo(ct), titulo(t), autor(a), palabrasClave(pC), estado(s) {}
Material::~Material() {}

//Acceso
int Material::getNumClasificacion() { return numeroClasificacion; }
int Material::getNumCatalogo() { return numeroCatalogo; }
string Material::getTitulo() { return titulo; }
string Material::getAutor() { return autor; }
string Material::getPalabrasClave() { return palabrasClave; }
char Material::getTipoMaterial() { return tipoMaterial; }
string Material::getEstado() { return estado; }

//Setteo
void Material::setNumClasificacion(int c) { numeroClasificacion = c; }
void Material::setNumCatalogo(int ct) { numeroCatalogo = ct; }
void Material::setTitulo(string t) { titulo = t; }
void Material::setAutor(string a) { autor = a; }
void Material::setPalabrasClave(string pC) { palabrasClave = pC; }
void Material::setTipoMaterial(char tm) { tipoMaterial = tm; }
void Material::setEstado(string s) { estado = s; }

//toString
string Material::toString() const {
    stringstream s;
    s << "Tipo de material: " << tipoMaterial << endl; 
    s << "Numero de clasificacion: " << numeroClasificacion << endl;
    s << "Numero de catalogo: " << numeroCatalogo << endl;
    s << "Titulo: " << titulo << endl;
    s << "Autor(es): " << autor << endl;
    s << "Palabras clave: " << palabrasClave << endl;
    s << "Estado del material: " << estado << endl;

    return s.str();
}
