// -------------------------------------------------------------------+ 
//                                                                    | 
// (c) 2025                                                           | 
// EIF204 - Programación 2                                            | 
// 1er ciclo 2025                                                     | 
// NRC 41371 – Grupo 06                                               | 
// Proyecto 1                                                         | 
//                                                                    | 
// 1-1977-0346; Menjívar Ramírez, Naara                               | 
// 1-1905-0975; Chaves Salazar, Sebastián                             | 
//                                                                    | 
// versión 1.0.0 2025-04-01                                           | 
//                                                                    | 
// -------------------------------------------------------------------+
#ifndef CONVDATOSYFUNC_H  
#define CONVDATOSYFUNC_H
#include "Includes.h"

int conversionInt(string);//Realiza la conversion de un string a un int para la carga de archivos

char conversionChar(string); 

bool esAnioBisiesto(int);//Verifica si un año es bisiesto

int diasEnMes(int, int);//Obtener el número de días en un mes específico
    
string sumarDiasxPrestamo(const string& fechaF, char tipoMat);//Suma los dias segun la fecha recibida

#endif