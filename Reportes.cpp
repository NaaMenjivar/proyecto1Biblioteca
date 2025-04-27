#include "Reportes.h"

Reportes::Reportes(){}

Reportes::~Reportes(){}

//se realiza de esta manera por estar sobrecargado el operador << para los materiales
string Reportes::repInventarioMaterial(ListaMateriales& m)
{
    stringstream s;
    NodoMaterial* aux = m.getPrimero();
    while (aux) {
        s << *aux->getDato() << endl;
        aux = aux->getSiguiente();
    }
    return s.str();
}

string Reportes::repMaterialEspecif(ListaMateriales& m, char t)
{
    return m.toStringxMaterial(t);
}

string Reportes::repUsuarios(ListaUsuarios& u)
{
    return u.toString();
}

string Reportes::repPrestamos(GestorPrestamos& p)
{
    return p.toString();
}

string Reportes::repPresxMat(GestorPrestamos& p, char tipo)
{
    return p.toStringxMaterial(tipo);
}

string Reportes::repPresxUsr(GestorPrestamos& p, string id)
{
    return p.toStringxUsuario(id);
}
