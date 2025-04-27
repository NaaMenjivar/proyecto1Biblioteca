#include "Libro.h"
#include "Archivos.h" 

Libro::Libro(char tm, int c, int ct, string t, string a, string pC, string s, string uF)
	: Material(tm, c, ct, t, a, pC, s), ubicacionFisica(uF) {
	this->persistencia = new PersistenciaLibros();            
} 

Libro::~Libro() {
	if (persistencia)
		delete persistencia;
}

//Acceso
string Libro::getUbicacionFisica() { return ubicacionFisica; }

//Setteo
void Libro::setUbicacionFisica(string uF) { ubicacionFisica = uF; }

//toString
string Libro::toString() const {
	stringstream s;
	s << "-------------------------------------------------" << "\n";
	s << "Tipo de material: Libro" << "\n";
	s << "Numero de clasificacion: " << numeroClasificacion << "\n";
	s << "Numero de catalogo: " << numeroCatalogo << "\n";
	s << "Titulo: " << titulo << "\n";
	s << "Autor(es): " << autor << "\n";
	s << "Palabras clave: " << palabrasClave << "\n";
	s << "Estado del material: " << estado << "\n";
	s << "Ubicacion fisica: " << ubicacionFisica << "\n";

	return s.str();
}

void Libro::guardar(std::ofstream& file)
{
	persistencia->guardarMaterial(this, file);
}

Libro* Libro::cargar(std::ifstream& file)
{
	PersistenciaLibros per;
	return per.cargarLibro(file);
}
