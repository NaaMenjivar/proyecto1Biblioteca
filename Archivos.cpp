#include "Archivos.h"
#include "Libro.h"
#include "Revista.h"
#include "Articulo.h"
#include "MaterialDigital.h"
#include "Video.h"
#include "ConvDatosyFunc.h"
//Se incluyen aqui los .h para evitar dependencia circular

Archivos::Archivos(){}

Archivos::~Archivos(){}

void PersistenciaLibros::guardarMaterial(Material* m, std::ofstream& salida)
{
	Libro* libro = dynamic_cast<Libro*>(m);
	if (!libro) {
		return;
	}

	salida << libro->getNumClasificacion() << '\t';
	salida << libro->getNumCatalogo() << '\t';
	salida << libro->getTitulo() << '\t';
	salida << libro->getAutor() << '\t';
	salida << libro->getPalabrasClave() << '\t';
	salida << libro->getEstado() << '\t';
	salida << libro->getUbicacionFisica() << '\n';

}

Libro* PersistenciaLibros::cargarLibro(std::ifstream& entrada)
{
	string nCl, nCa, titu, aut, pClav, est, ubiF;

	getline(entrada, nCl, '\t');
	getline(entrada, nCa, '\t');
	getline(entrada, titu, '\t');
	getline(entrada, aut, '\t'); 
	getline(entrada, pClav, '\t');
	getline(entrada, est, '\t');
	getline(entrada, ubiF, '\n');  

	char tipo = 'L';
	int numCla = conversionInt(nCl);
	int numCat = conversionInt(nCa);

	if (!nCl.empty() && !nCa.empty() && !titu.empty() && 
		!aut.empty() && !pClav.empty() && !est.empty() && !ubiF.empty()) {
		return new Libro(tipo, numCla, numCat, titu, aut, pClav, est, ubiF);
	}
	return nullptr; 
}

void PersistenciaArticulos::guardarMaterial(Material* m, std::ofstream& salida)
{
	Articulo* articulo = dynamic_cast<Articulo*>(m); 
	if (!articulo) {
		return;
	}

	salida << articulo->getNumClasificacion() << '\t'; 
	salida << articulo->getNumCatalogo() << '\t'; 
	salida << articulo->getTitulo() << '\t'; 
	salida << articulo->getAutor() << '\t'; 
	salida << articulo->getPalabrasClave() << '\t'; 
	salida << articulo->getEstado() << '\t';
	salida << articulo->getRevistaPublicacion() << '\t';
	salida << articulo->getFechaPublicacion() << '\n';
}

Articulo* PersistenciaArticulos::cargarArticulo(std::ifstream& entrada)
{
	string nCl, nCa, titu, aut, pClav, est, revP, fecha;

	getline(entrada, nCl, '\t');
	getline(entrada, nCa, '\t');
	getline(entrada, titu, '\t');
	getline(entrada, aut, '\t');
	getline(entrada, pClav, '\t');
	getline(entrada, est, '\t');
	getline(entrada, revP, '\t'); 
	getline(entrada, fecha, '\n'); 

	char tipo = 'A';
	int numCla = conversionInt(nCl);
	int numCat = conversionInt(nCa);

	if (!nCl.empty() && !nCa.empty() && !titu.empty() && !aut.empty() && 
		!pClav.empty() && !est.empty() && !revP.empty() && !fecha.empty()) {
		return new Articulo(tipo, numCla, numCat, titu, aut, pClav, est, revP, fecha);
	}
	return nullptr;
}

void PersistenciaResvistas::guardarMaterial(Material* m, std::ofstream& salida)
{ 
	Revista* revista = dynamic_cast<Revista*>(m); 
	if (!revista) {
		return;
	}

	salida << revista->getNumClasificacion() << '\t'; 
	salida << revista->getNumCatalogo() << '\t'; 
	salida << revista->getTitulo() << '\t'; 
	salida << revista->getAutor() << '\t'; 
	salida << revista->getPalabrasClave() << '\t'; 
	salida << revista->getEstado() << '\t';
	salida << revista->getNumero() << '\t';
	salida << revista->getVolumen() << '\t';
	salida << revista->getUbicacionFisica() << '\n';
}

Revista* PersistenciaResvistas::cargarRevista(std::ifstream& entrada)
{
	string nCl, nCa, titu, aut, pClav, est, numR, vol, ubiF;

	getline(entrada, nCl, '\t'); 
	getline(entrada, nCa, '\t'); 
	getline(entrada, titu, '\t'); 
	getline(entrada, aut, '\t');
	getline(entrada, pClav, '\t'); 
	getline(entrada, est, '\t'); 
	getline(entrada, numR, '\t'); 
	getline(entrada, vol, '\t');
	getline(entrada, ubiF, '\n'); 

	char tipo = 'R';
	int numCla = conversionInt(nCl); 
	int numCat = conversionInt(nCa);
	int numRev = conversionInt(numR);
	int volumen = conversionInt(vol);

	if (!nCl.empty() && !nCa.empty() && !titu.empty() && !aut.empty() && 
		!pClav.empty() && !est.empty() && !numR.empty() && !vol.empty() && !ubiF.empty()) {
		return new Revista(tipo, numCla, numCat, titu, aut, pClav, est, numRev, volumen, ubiF);
	}
	return nullptr;
}

void PersistenciaMatDigitales::guardarMaterial(Material* m, std::ofstream& salida)
{ 
	MaterialDigital* matDigital = dynamic_cast<MaterialDigital*>(m); 
	if (!matDigital) {
		return;
	}

	salida << matDigital->getNumClasificacion() << '\t'; 
	salida << matDigital->getNumCatalogo() << '\t'; 
	salida << matDigital->getTitulo() << '\t'; 
	salida << matDigital->getAutor() << '\t'; 
	salida << matDigital->getPalabrasClave() << '\t'; 
	salida << matDigital->getEstado() << '\t'; 
	salida << matDigital->getFormato() << '\t';
	salida << matDigital->getTipo() << '\n';
}

MaterialDigital* PersistenciaMatDigitales::cargarMaterialDigital(std::ifstream& entrada)
{
	string nCl, nCa, titu, aut, pClav, est, form, tip; 
 
	getline(entrada, nCl, '\t');
	getline(entrada, nCa, '\t'); 
	getline(entrada, titu, '\t'); 
	getline(entrada, aut, '\t');
	getline(entrada, pClav, '\t'); 
	getline(entrada, est, '\t'); 
	getline(entrada, form, '\t'); 
	getline(entrada, tip, '\n'); 


	char tipo = 'D';
	int numCla = conversionInt(nCl); 
	int numCat = conversionInt(nCa); 

	if (!nCl.empty() && !nCa.empty() && !titu.empty() && !aut.empty() &&
		!pClav.empty() && !est.empty() && !form.empty() && !tip.empty()) { 
		return new MaterialDigital(tipo, numCla, numCat, titu, aut, pClav, est, form, tip); 
	}
	return nullptr;
}

void PersistenciaVideo::guardarMaterial(Material* m, std::ofstream& salida)
{
	Video* video = dynamic_cast<Video*>(m); 
	if (!video) {
		return;
	}

	salida << video->getNumClasificacion() << '\t';
	salida << video->getNumCatalogo() << '\t';
	salida << video->getTitulo() << '\t';
	salida << video->getAutor() << '\t';
	salida << video->getPalabrasClave() << '\t';
	salida << video->getEstado() << '\t';
	salida << video->getDuracion() << '\t';
	salida << video->getFormato() << '\n'; 

}

Video* PersistenciaVideo::cargarVideo(std::ifstream& entrada)
{
	string nCl, nCa, titu, aut, pClav, est, dur, form; 

	getline(entrada, nCl, '\t');
	getline(entrada, nCa, '\t');
	getline(entrada, titu, '\t');
	getline(entrada, aut, '\t');
	getline(entrada, pClav, '\t');
	getline(entrada, est, '\t');
	getline(entrada, dur, '\t');
	getline(entrada, form, '\n');


	char tipo = 'V';
	int numCla = conversionInt(nCl);
	int numCat = conversionInt(nCa);

	if (!nCl.empty() && !nCa.empty() && !titu.empty() && !aut.empty() &&
		!pClav.empty() && !est.empty() && !dur.empty() && !form.empty()){
		return new Video(tipo, numCla, numCat, titu, aut, pClav, est, dur, form);
	}
	return nullptr;
}
