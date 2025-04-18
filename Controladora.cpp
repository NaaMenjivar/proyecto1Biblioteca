#include "Controladora.h"

Controladora::Controladora()
{
    biblioteca = new Biblioteca();
}

Controladora::~Controladora()
{
    if (biblioteca)
        delete biblioteca;
}

void Controladora::control0()//Todos los menus de interfaz
{
    int opcion;
    do {
        opcion = menuPrincipal();
        switch (opcion)
        {
        case 1: { controlMenuIngresos(); }break;

        case 2: {}break;

        default: {}break;
        }
    } while (opcion != 2);
}

int Controladora::menuPrincipal()
{
    return Interfaz::menuPrincipal();
}

void Controladora::controlMenuIngresos()
{
     int opcion;
    do {
        opcion = menuIngresos();
        switch (opcion)
        {
        case 1: { ingresarMaterial(); }break;

        case 2: { ingresarUsuario(); }break;

        //case 3: { ingresarPeriodo(); }break;

        //case 4: { ingresarGrupo(); }break;

        case 3: {}break;

        default: {}break;
        }
    } while (opcion != 3);
}

int Controladora::menuIngresos()
{
    return Interfaz::menuIngresosModificaciones(); 
}

void Controladora::ingresarMaterial()
{
    Material* m = Interfaz::crearMaterial();
    if (m) {
        if (biblioteca->ingresarMateriales(*m)) {
            Interfaz::mensajeIngresoExitoso();
        }
        else {
            Interfaz::mensajeErrorIngreso();
            delete m;
        }
    }
}

void Controladora::ingresarUsuario()
{
    Usuario* u = Interfaz::crearUsuario();
    if (u) {
        if (biblioteca->ingresarUsuarios(*u)) {
            Interfaz::mensajeIngresoExitoso();
        }
        else {
            Interfaz::mensajeErrorIngreso();
            delete u;
        }
    }
}
