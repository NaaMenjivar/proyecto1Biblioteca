#include "MaterialDigital.h"
#include "Archivos.h"

MaterialDigital::MaterialDigital(char tm, int c, int ct, string t, string a, string pC, string s, string f, string typ)
    : Material(tm, c, ct, t, a, pC, s), formato(f), tipo(typ){
	this->accesoEnLinea = true;
	this->persistencia = new PersistenciaMatDigitales();
}

MaterialDigital::~MaterialDigital() {
	if (persistencia)
		delete persistencia;
} 

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
	s << "-------------------------------------------------" << "\n";
	s << "Tipo de material: Material digital" << "\n";
	s << "Numero de clasificacion: " << numeroClasificacion << "\n";
	s << "Numero de catalogo: " << numeroCatalogo << "\n";
	s << "Titulo: " << titulo << "\n";
	s << "Autor(es): " << autor << "\n";
	s << "Palabras clave: " << palabrasClave << "\n";
	s << "Estado del material: " << estado << "\n";
    s << "Formato: " << formato << "\n";
    s << "Tipo: " << tipo << "\n";
    s << "Acceso en linea: " << accesoEnLinea << "\n";

    return s.str();
}

void MaterialDigital::guardar(std::ofstream& file)
{
	persistencia->guardarMaterial(this, file);
}

MaterialDigital* MaterialDigital::cargar(std::ifstream& file)
{
	PersistenciaMatDigitales per;
	return per.cargarMaterialDigital(file);
}
