#include "ConvDatosyFunc.h"

int conversionInt(string s)
{
    stringstream r(s);
    int v;
    r >> v;
    return v;
}

char conversionChar(string s)
{
    stringstream r(s);
    char v;
    r >> v;
    return v;
}

bool esAnioBisiesto(int anio) {//Verifica si un año es bisiesto
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int diasEnMes(int mes, int anio) {//Obtener el número de días en un mes específico
    const int diasPorMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//Dias totales de cada mes

    if (mes == 2 && esAnioBisiesto(anio))
        return 29;

    return diasPorMes[mes - 1];
}

string sumarDiasxPrestamo(const string& fechaF, char tipoMat) {
    // Parsear la fecha
    int dia, mes, anio;
    char delimitador;
    stringstream s(fechaF);

    s >> dia >> delimitador >> mes >> delimitador >> anio;

    switch (toupper(tipoMat))//Suma los dias segun el tipo material
    {
    case 'L'://Dias de pretamo para Libro
        dia += 7;
    case 'R'://Dias de pretamo para Revista
        dia += 2;
    case 'D'://Dias de pretamo para Material Digital
        dia += 5;
    default:
        break;
    }
    // Ajustar si excede el número de días del mes actual
    while (dia > diasEnMes(mes, anio)) {
        dia -= diasEnMes(mes, anio);
        mes++;
        if (mes > 12) {// Ajustar si excede el número de meses en un año
            mes = 1;
            anio++;
        }
    }
    //Realiza la fecha como "DD/MM/YYYY"
    stringstream resultado;
    resultado << setfill('0') << setw(2) << dia << "/"
        << setfill('0') << setw(2) << mes << "/"
        << anio;

    return resultado.str();
}