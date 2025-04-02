#include "Libro.h"

Libro::Libro(int c, int ct, string t, string a, string pC, string ty, string s, string uF) 
	: Material(c, ct, t, a, pC, ty, s), ubicacionFisica(uF) {}
Libro::~Libro() {}

//Acceso
string Libro::getUbicacionFisica() { return ubicacionFisica; }

//Setteo
void Libro::setUbicacionFisica(string uF) { ubicacionFisica = uF; }

//toString
string Libro::toString() const {
	stringstream s;
	s << Material::toString() << endl;
	s << "Ubicacion física: " << endl;

	return s.str();
}
