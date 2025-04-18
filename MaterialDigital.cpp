#include "MaterialDigital.h"

MaterialDigital::MaterialDigital(char tm, int c, int ct, string t, string a, string pC, string s, string f, string typ, bool acEL)
    : Material(tm, c, ct, t, a, pC, s), formato(f), tipo(typ), accesoEnLinea(acEL) {}
MaterialDigital::~MaterialDigital() {} 

//Acceso
string MaterialDigital::getFormato() { return formato; }
string MaterialDigital::getTipo() { return tipo; }
bool MaterialDigital::getAccesoEnLinea() { return accesoEnLinea; }

//Setteo
void MaterialDigital::setFormato(string f) { formato = f; }
void MaterialDigital::setTipo(string typ) { tipo = typ; }
void MaterialDigital::setAccesoEnLinea(bool acEl) { accesoEnLinea = acEl; }

//toString
string MaterialDigital::toString() const {
    stringstream s;
    s << Material::toString() << endl;
    s << "Formato: " << formato << endl;
    s << "Tipo: " << tipo << endl;
    s << "Acceso en linea: " << accesoEnLinea << endl;

    return s.str();
}
