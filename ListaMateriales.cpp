#include "ListaMateriales.h"

/*--------------------NODO--------------------*/
NodoMaterial::NodoMaterial(Material* d, NodoMaterial* s) : dato(d), sig(s) {}
NodoMaterial::~NodoMaterial() {}

//Acceso
Material* NodoMaterial::getDato() { return dato; }
NodoMaterial* NodoMaterial::getSiguiente() { return sig; }

//Setteo
void NodoMaterial::setMaterial(Material* d) { dato = d; }
void NodoMaterial::setSiguiente(NodoMaterial* s) { sig = s; }

//toString
string NodoMaterial::toString() const {
    return dato->toString();
}

/*--------------------LISTA--------------------*/
ListaMateriales::ListaMateriales() : primero(nullptr), actual(nullptr) {}
ListaMateriales::~ListaMateriales() {
    if (primero != nullptr) {
        vaciarLista();//Lamada al metodo vaciar lista
    }
}
//Agregar materiales
bool ListaMateriales::agregarMateriales(Material& nuevoMaterial) {
    if (buscarxTipMaterial(nuevoMaterial.getTipoMaterial())) {
        return false;
    }
    primero = new NodoMaterial(&nuevoMaterial, primero);
    return true;
}

//Buscar materiales
bool ListaMateriales::buscarxTipMaterial(char tipMaterial) {
    if (primero == nullptr) {
        return false;
    }
    actual = primero;
    while (actual != nullptr) {
        if (actual->getDato()->getTipoMaterial() == tipMaterial) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

bool ListaMateriales::buscarxNumCatalago(int numCatalago)
{
    if (primero == nullptr) {
        return false;
    }
    actual = primero;
    while (actual != nullptr) {
        if (actual->getDato()->getNumCatalogo() == numCatalago) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
    return false;
}

Material* ListaMateriales::obtenerMaterial(int numCatalago)
{
    actual = primero;
    while (actual != nullptr) {
        if (actual->getDato()->getNumCatalogo() == numCatalago) {
            return actual->getDato();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

NodoMaterial* ListaMateriales::getPrimero()
{
    return primero;
}

//Eliminar material
void ListaMateriales::eliminarMaterial(int numCatalogo) {
    actual = primero;
    if (buscarxNumCatalago(numCatalogo)) {
        if (actual->getDato()->getNumCatalogo() == numCatalogo) {
            primero = primero->getSiguiente();
            delete actual;
        }
        else {
            while (actual->getSiguiente()->getDato()->getNumCatalogo() != numCatalogo) {
                actual = actual->getSiguiente();
            }
            NodoMaterial* nodo = actual->getSiguiente();
            actual->setSiguiente(actual->getSiguiente()->getSiguiente());
            delete nodo;
        }
    }
}

//Vaciar lista
void ListaMateriales::vaciarLista() {//Metodo encargado de borrar elementos, nodos y la lista...
    while (primero != nullptr) {
        actual = primero;
        primero = primero->getSiguiente();
        delete actual->getDato();
        delete actual;
    }
}

//toString
string ListaMateriales::toString() {
    stringstream s;
    int t = 1;
    if (primero == nullptr) {
        s << "No hay informacion que mostrar, la lista esta vacia." << endl;
    }
    else {
        actual = primero;
        while (actual != nullptr) {
            s << "---------------- " << t << " ----------------" << endl;
            s << actual->getDato();
            t++;
            actual = actual->getSiguiente();
        }
    }
    return s.str();
}

string ListaMateriales::toStringxMaterial(char tip) 
{
    stringstream s;
    actual = primero;
    if (primero) {
        while (actual) {
            if ((tip == 'L' || tip == 'l') && dynamic_cast<Libro*>(actual->getDato())) { 
                s << actual->getDato()->toString() << "\n";
            }
            if ((tip == 'A' || tip == 'a') && dynamic_cast<Articulo*>(actual->getDato())) {
                s << actual->getDato()->toString() << "\n";
            }
            if ((tip == 'R' || tip == 'r') && dynamic_cast<Revista*>(actual->getDato())) { 
                s << actual->getDato()->toString() << "\n";
            }
            if ((tip == 'V' || tip == 'v') && dynamic_cast<Video*>(actual->getDato())) { 
                s << actual->getDato()->toString() << "\n";
            }
            if ((tip == 'D' || tip == 'd') && dynamic_cast<MaterialDigital*>(actual->getDato())) { 
                s << actual->getDato()->toString() << "\n";
            }
            actual = actual->getSiguiente(); 
        }
    }
    return s.str();
}

void ListaMateriales::guardar(std::ofstream& file)
{
    actual = primero;
    while (actual) {
        // Sepera en una linea aparte el tipo de material
        file << actual->getDato()->getTipoMaterial() << "\n";

        if ((actual->getDato()->getTipoMaterial() == 'L' || actual->getDato()->getTipoMaterial() == 'l')
            && dynamic_cast<Libro*>(actual->getDato())) {
            Libro* libro = dynamic_cast<Libro*>(actual->getDato());
            libro->guardar(file);
        }
        else if ((actual->getDato()->getTipoMaterial() == 'A' || actual->getDato()->getTipoMaterial() == 'a')
            && dynamic_cast<Articulo*>(actual->getDato())) {
            Articulo* articulo = dynamic_cast<Articulo*>(actual->getDato());
            articulo->guardar(file);
        } 
        else if ((actual->getDato()->getTipoMaterial() == 'R' || actual->getDato()->getTipoMaterial() == 'r')
            && dynamic_cast<Revista*>(actual->getDato())) {
            Revista* revista = dynamic_cast<Revista*>(actual->getDato());
            revista->guardar(file);
        }
        else if ((actual->getDato()->getTipoMaterial() == 'V' || actual->getDato()->getTipoMaterial() == 'v')
            && dynamic_cast<Video*>(actual->getDato())) {
            Video* video = dynamic_cast<Video*>(actual->getDato());
            video->guardar(file);
        }
        else if ((actual->getDato()->getTipoMaterial() == 'D' || actual->getDato()->getTipoMaterial() == 'd')
            && dynamic_cast<MaterialDigital*>(actual->getDato())) {
            MaterialDigital* mDigital = dynamic_cast<MaterialDigital*>(actual->getDato());
            mDigital->guardar(file);
        }
        actual = actual->getSiguiente();
    }
}
