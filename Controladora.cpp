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
    cargarArchivos();
    int opcion;
    do {
        opcion = menuPrincipal();
        switch (opcion)
        {
        case 1: { controlMenuIngresos(); }break;

        case 2: { controlMenuPrestamosyDevoluciones(); }break;

        case 3: { controlMenuReportes(); }break;

        case 4: { controlMenuGuardar(); }break;

        case 5: {}break;

        default: {}break;
        }
    } while (opcion != 5);
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

        case 3: { modificarMaterial(); }break;

        case 4: { modificarUsuario(); }break;

        case 5: {}break;

        default: {}break;
        }
    } while (opcion != 5);
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

void Controladora::modificarMaterial()
{
    if (Interfaz::modificarMaterial(*biblioteca)) {
        Interfaz::mensajeIngresoExitoso(); 
    }
    Interfaz::mensajeErrorIngreso(); 
}

void Controladora::modificarUsuario()
{
    if (Interfaz::modicarUsuario(*biblioteca)) { 
        Interfaz::mensajeIngresoExitoso();
    }
    Interfaz::mensajeErrorIngreso();
}

void Controladora::controlMenuPrestamosyDevoluciones()
{
    int opcion;
    do {
        opcion = menuPyD();
        switch (opcion)
        {
        case 1: { ingresarPrestamo(); }break;

        case 2: { devolucionPres(); }break;

        case 3: {}break;

        default: {}break;
        }
    } while (opcion != 3);
}

int Controladora::menuPyD()
{
    return Interfaz::menuPrestamos();
}

void Controladora::ingresarPrestamo()
{
    Prestamo* p = Interfaz::crearPrestamo(*biblioteca);
    if (p) { 
        if (biblioteca->ingresarPrestamos(*p)) {
            Interfaz::mensajeIngresoExitoso(); 
        }
        else {
            Interfaz::mensajeErrorIngreso(); 
            delete p; 
        }
    }
}

void Controladora::devolucionPres()
{
    if (Interfaz::devolucionPrestamo(*biblioteca)) {
        Interfaz::msjDevolucionExitoso();
    }
    else {
        Interfaz::msjErrorDevolucion();
    }
}

void Controladora::controlMenuReportes()
{
    int opcion;
    do {
        opcion = menuReportes();
        switch (opcion)
        {
        case 1: { repMateriales(); }break;

        case 2: { repUsuarios(); }break; 

        case 3: { repPrestamos(); }break;

        case 4: { repPrestamosporMat(); }break;

        case 5: { repPrestamosporUsr(); }break;

        case 6: {}break;

        default: {}break;
        }
    } while (opcion != 6);
}

int Controladora::menuReportes()
{
    return Interfaz::menuReportes(); 
}

void Controladora::repMateriales()
{
    Interfaz::reporteInvMaterial(*biblioteca);
}

void Controladora::repUsuarios()
{
    Interfaz::reportdeUsuarios(*biblioteca);
}

void Controladora::repPrestamos()
{
    Interfaz::reportedePrestamos(*biblioteca);
}

void Controladora::repPrestamosporMat()
{
    Interfaz::reportedePrestamosxMat(*biblioteca);
}

void Controladora::repPrestamosporUsr()
{
    Interfaz::reportedePrestamosxUsr(*biblioteca);
}

void Controladora::controlMenuGuardar()
{
    guardarArchivos();
    Interfaz::msjGuardado();
}

void Controladora::guardarArchivos()
{
    biblioteca->guardarMateriales();
    biblioteca->guardarUsuarios();
    biblioteca->guardarPrestamos();
}

void Controladora::cargarArchivos()
{
    biblioteca->cargarMateriales();
    biblioteca->cargarUsuarios();
    biblioteca->cargarPrestamos();
}
