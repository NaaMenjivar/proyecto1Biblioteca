#include "Video.h"

Video::Video(char tm, int c, int ct, string t, string a, string pC, string s, string d, string f)
    : Material(tm, c, ct, t, a, pC, s), duracion(d), formato(f) {} 
Video::~Video() {}

//Acceso
string Video::getDuracion() { return duracion; }
string Video::getFormato() { return formato; }

//Setteo
void Video::setDuracion(string d) { duracion = d; }
void Video::setFormato(string f) { formato = f; }

//toString
string Video::toString() const {
    stringstream s;
    s << Material::toString() << endl;
    s << "Duracion: " << duracion << endl;
    s << "Formato: " << formato << endl;

    return s.str();
}
