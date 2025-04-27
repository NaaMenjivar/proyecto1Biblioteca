#include "Revista.h"
#include "Archivos.h"

Revista::Revista(char tm, int c, int ct, string t, string a, string pC, string s, int nm, int vl, string uF)
    : Material(tm, c, ct, t, a, pC, s), numero(nm), volumen(vl), ubicacionFisica(uF) {
	this->persistencia = new PersistenciaResvistas();
} 

//Acceso
int Revista::getNumero() { return numero; }
int Revista::getVolumen() { return volumen; }
string Revista::getUbicacionFisica() { return ubicacionFisica; }

//Setteo
void Revista::setNumero(int nm) { numero = nm; }
void Revista::setVolumen(int vl) { volumen = vl; }
void Revista::setUbicacionFisica(string uF) { ubicacionFisica = uF; }

//toString
string Revista::toString() const {
    stringstream s;
    s << Material::toString() << endl;
    s << "Numero: " << numero << endl;
    s << "Volumen: " << volumen << endl;
    s << "Ubicacion fisica: " << ubicacionFisica << endl;

    return s.str();
}
