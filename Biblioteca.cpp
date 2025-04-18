#include "Biblioteca.h"

Biblioteca::Biblioteca()
{
    materiales = new ListaMateriales();
    usuarios = new ListaUsuarios();
    prestamos = new GestorPrestamos(); 
}

Biblioteca::~Biblioteca()  
{
    if (materiales)
        delete materiales;
    if (usuarios)
        delete usuarios;
    if (prestamos)
        delete prestamos;
}

bool Biblioteca::ingresarMateriales(Material& m)
{
    return materiales->agregarMateriales(m);
}

bool Biblioteca::ingresarUsuarios(Usuario& u)
{
    return usuarios->agregarUsuarios(u);
}

bool Biblioteca::ingresarPrestamos(Prestamo& p)
{
    return prestamos->agregarPrestamo(p);
}

Material* Biblioteca::getMaterial(char tipMat)
{
    return materiales->obtenerMaterial(tipMat);
}

Usuario* Biblioteca::getUsuarios(string idUs)
{
    return usuarios->obtenerUsuario(idUs);
}

Prestamo* Biblioteca::getPrestamo(int numPe)
{
    return prestamos->obtenerPrestamo(numPe);
}
