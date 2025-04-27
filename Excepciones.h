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
#pragma once
#include "Includes.h"
using namespace std;

class Excepcion :public exception
{
public:
	Excepcion() {};
	virtual ~Excepcion() {};
	virtual string porque() = 0;
};

class ExcRango : public Excepcion
{
protected:
    int max;
    int min;
public:
    ExcRango(int mi, int ma):min(mi), max(ma) {}
    virtual ~ExcRango() {}
    virtual string porque() = 0;
};

class ExcValSup : public ExcRango
{
private:
    int val;
public:
    ExcValSup(int n, int m, int a) :ExcRango(n, m), val(a) {} 

    ExcValSup(int ma, int va) :ExcValSup(0, ma, va) {}

    ExcValSup() :ExcValSup(1, 2, 3) {} 

    virtual ~ExcValSup() {}

    string porque() {
        stringstream s;
        s << "El valor ingresado: " << val << " es superior al max: " << max
            << ". Debe ingresar un numero inferior o igual a: " << max << ".";
        return s.str();
    }


};

class ExcValInf : public ExcRango
{
private:
    int val;
public:
    ExcValInf(int n, int m, int a):ExcRango(n, m), val(a) {}

    ExcValInf(int min, int va):ExcValInf(min, 0, va) {}
    
    ExcValInf() :ExcValInf(1, 2, 0) {}

    virtual ~ExcValInf() {}

    string porque() {
        stringstream s;
        s << "El valor ingresado: " << val << " es inferior a: " << min
            << ". Debe ingresar un numero mayor o igual a: " << min << ".";
        return s.str();
    }
};

class ExcValInvalido :
    public Excepcion
{
public:
    ExcValInvalido():Excepcion() {}

    virtual ~ExcValInvalido() {}

    string porque() {
        stringstream s;
        s << "Caracter invalido. Debe digitar un numero.";
        return s.str();
    }
};

class ExcCharInvalido : public Excepcion
{
private:
    char valor;
    string permitidos;
public:
    ExcCharInvalido(char val, string chars) : valor(val), permitidos(chars) {}

    ExcCharInvalido() : ExcCharInvalido(' ', "L, l, R, r, A, a, V, v, D, d") {}

    virtual ~ExcCharInvalido() {}

    string porque() {
        stringstream s;
        s << "El caracter ingresado '" << valor << "' es invalido. "
            << "Los caracteres permitidos son: " << permitidos << ".";
        return s.str();
    }
};

