#include "Revista.h"
#include "Archivos.h"

Revista::Revista(char tm, int c, int ct, string t, string a, string pC, string s, int nm, int vl, string uF)
    : Material(tm, c, ct, t, a, pC, s), numero(nm), volumen(vl), ubicacionFisica(uF) {
	this->persistencia = new PersistenciaResvistas();
} 

Revista::~Revista() {
	if (persistencia) {
		delete persistencia;
	}
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
	s << "-------------------------------------------------" << "\n";
	s << "Tipo de material: Revista" << "\n";
	s << "Numero de clasificacion: " << numeroClasificacion << "\n";
	s << "Numero de catalogo: " << numeroCatalogo << "\n";
	s << "Titulo: " << titulo << "\n";
	s << "Autor(es): " << autor << "\n";
	s << "Palabras clave: " << palabrasClave << "\n";
	s << "Estado del material: " << estado << "\n";
	s << "Numero: " << numero << "\n";
	s << "Volumen: " << volumen << "\n";
	s << "Ubicacion fisica: " << ubicacionFisica << "\n";

    return s.str();
}

void Revista::guardar(std::ofstream& file)
{
	persistencia->guardarMaterial(this, file);
}

Revista* Revista::cargar(std::ifstream& file)
{
	PersistenciaResvistas per; 
	return per.cargarRevista(file);
}
