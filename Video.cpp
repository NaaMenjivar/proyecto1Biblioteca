#include "Video.h"
#include "Archivos.h" 

Video::Video(char tm, int c, int ct, string t, string a, string pC, string s, string d, string f)
    : Material(tm, c, ct, t, a, pC, s), duracion(d), formato(f) {
	this->persistencia = new PersistenciaVideo();
} 

//Acceso
string Video::getDuracion() { return duracion; }
string Video::getFormato() { return formato; }

//Setteo
void Video::setDuracion(string d) { duracion = d; }
void Video::setFormato(string f) { formato = f; }

//toString
string Video::toString() const {
    stringstream s;
	s << "-------------------------------------------------" << "\n";
	s << "Tipo de material: Video" << "\n";
	s << "Numero de clasificacion: " << numeroClasificacion << "\n";
	s << "Numero de catalogo: " << numeroCatalogo << "\n";
	s << "Titulo: " << titulo << "\n";
	s << "Autor(es): " << autor << "\n";
	s << "Palabras clave: " << palabrasClave << "\n";
	s << "Estado del material: " << estado << "\n";
    s << "Duracion: " << duracion << "\n";
	s << "Formato: " << formato << "\n";

    return s.str();
}
