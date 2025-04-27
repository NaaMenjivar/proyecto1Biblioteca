#include "Usuario.h"

Usuario::Usuario(string i, string n, bool a) 
    : id(i), nombre(n), activo(a) {}
Usuario::~Usuario() {}

//Acceso
string Usuario::getId() { return id; }
string Usuario::getNombre() { return nombre; }
bool Usuario::getActivo() { return activo; }

//Setteo
void Usuario::setId(string i) { id = i; }
void Usuario::setNombre(string n) { nombre = n; }
void Usuario::setActivo(bool a) { activo = a; }

//toString
string Usuario::toString() const {
    stringstream s;
    s << "ID: " << id << endl;
    s << "Nombre: " << nombre << endl;
    s << "Activo: " << activo << endl;

    return s.str();
}

void Usuario::guardar(std::ofstream& salida)
{
    salida << id << "\t";
    salida << nombre << "\t";
    salida << activo << "\n";
}

Usuario* Usuario::cargar(std::ifstream& entrada)
{
    string unId, unNombre, act; 

    entrada >> unId;
    entrada >> unNombre;
    entrada >> act;
    int unActivo = conversionInt(act);

    if (!unId.empty() && !unNombre.empty() && !act.empty()) {
        return new Usuario(unId, unNombre, unActivo);
    }
    return nullptr;
}
