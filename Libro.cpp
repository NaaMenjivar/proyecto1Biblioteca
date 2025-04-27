#include "Libro.h"
#include "Archivos.h" 

Libro::Libro(char tm, int c, int ct, string t, string a, string pC, string s, string uF)
	: Material(tm, c, ct, t, a, pC, s), ubicacionFisica(uF) {
	this->persistencia = new PersistenciaLibros();            
} 

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
